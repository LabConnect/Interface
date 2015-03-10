#include <QMessageBox>
#include "libSgen-V0.1.h"

unsigned char output_data[] = {0x20, 0x00, 0x66, 0x49, 0x01, 0x40, 0xd4, 0xd5, 0x80, 0x7f, 0x01, 0x11};
/* 0 CReg1
 * 1 Creg2
 * 2 Freg1
 * 3 Freg2
 * 4 Freg3
 * 5 Freg4
 * 6 uAmp1
 * 7 uAmp2
 * 8 uOff1
 * 9 uOff2
 * 10 Kondensatoren
 * Bootdaten
 * Eine vordefinition der Werte ist unbedingt nötig!
 */


bool rechteck = false;

namespace Sgen {

bool GetBootLoad()
{
    bool load_data_at_boot = false;
    if ((output_data[11] & 0xF0) == 0x10)
    {
        load_data_at_boot = true;
    }
    return load_data_at_boot;
}

void BootData(bool save_data, bool load_data_at_boot)
{
    unsigned char save = 0x00, load = 0x00;
    if(save_data == true)
    {
        save = 0x01;
    }
    if(load_data_at_boot)
    {
        load = 0x10;
    }
    output_data[11] = save | load;
    return;
}

void RegwertUout(int u_amplitude_mv)
{
    int umax = 12000, bits = 510, register1, register2;

    int ergebnis = u_amplitude_mv / (umax / bits);

    if (510 < ergebnis)
    {
        ergebnis = 510;
    }

    if (ergebnis%2==0)
    {
        register1 = 255 - ergebnis / 2;
        register2 = 255 - ergebnis / 2;
    }
    else
    {
        ergebnis = ergebnis- 1;
        register1 = 255-((ergebnis / 2) + 1);
        register2 = 255 - ergebnis / 2;
    }

    output_data[6] = register1;
    output_data[7] = register2;
    return;
}

void RegwertOffset(int u_offset)
{
    float uges = 12, bits = 510;
    int register1, register2;

    int ergebnis = ((u_offset + 6) / (uges / bits));

    if (ergebnis%2==0)
    {
        register1 = ergebnis / 2;
        register2 = ergebnis / 2;
    }
    else
    {
        ergebnis = ergebnis- 1;
        register1 = (ergebnis / 2) + 1;
        register2 = ergebnis / 2;
    }
    output_data[8] = register1;
    output_data[9] = register2;
    return;
}

void SetWaveform(int form)
{
    if (form == 2)
    {
        rechteck = true;
    }
    else
    {
        rechteck = false;
    }
    return;
}

void SetFrequency(int frequenz)
{
    float mclk = 25000000, register_size = 268435456;

    float teiler = mclk / register_size;
    int f_regwert = frequenz / teiler;

    //block1=lsb --> block4=msb
    unsigned char block1, block2, block3, block4;

    block1 = f_regwert;
    f_regwert = f_regwert >> 8;
    block2 = f_regwert;
    block2 = (block2 | 0x40) & (~0x80);
    f_regwert = f_regwert >> 6;
    block3 = f_regwert;
    f_regwert = f_regwert >> 8;
    block4 = f_regwert;
    block4 = (block4 | 0x40) & (~0x80);

    output_data[2] = block1;
    output_data[3] = block2;
    output_data[4] = block3;
    output_data[5] = block4;


    if (rechteck == true)
    {
        output_data[10] = 3;
    }
    else
    {
        if (frequenz < 500)
        {
            output_data[10] = 3;
        }
        else if (frequenz < 10000)
        {
            output_data[10] = 2;
        }
        else
        {
            output_data[10] = 1;
        }
    }


}

void CommitData()
{

    for (int i=0;i<12;i++)
    {
        QMessageBox Ausgabe;
        Ausgabe.setText("<Array, Stelle " + QString::number(i) + " > " + QString::number(output_data[i],10));
        Ausgabe.exec();
    }
    //*/
    return;
}

//end of namespace
}
