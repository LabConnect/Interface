#include <QMessageBox>
#include "libSgen-V0.1.h"
#include "globals.h"

unsigned char output_data[] = {0x00, 0x00, 0x66, 0x49, 0x01, 0x40, 0xd4, 0xd5, 0x80, 0x7f, 0x00};
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
 * Eine vordefinition der Werte ist nötig!
 */

void Sgen::regwert_u_out(int uAmplitude)
{
    float umax = 12, bits = 510;
    int Register1, Register2;

    int ergebnis = (uAmplitude / (umax / bits));

    if (ergebnis%2==0)
    {
        Register1 = 255 - ergebnis / 2;
        Register2 = 255 - ergebnis / 2;
    }
    else
    {
        ergebnis = ergebnis- 1;
        Register1 = 255-((ergebnis / 2) + 1);
        Register2 = 255 - ergebnis / 2;
    }

    output_data[6] = Register1;
    output_data[7] = Register2;
    return;
}

void Sgen::regwert_offset(int uOffset)
{
    float uges = 12, bits = 510;
    int Register1, Register2;

    int ergebnis = ((uOffset + 6) / (uges / bits));

    if (ergebnis%2==0)
    {
        Register1 = ergebnis / 2;
        Register2 = ergebnis / 2;
    }
    else
    {
        ergebnis = ergebnis- 1;
        Register1 = (ergebnis / 2) + 1;
        Register2 = ergebnis / 2;
    }
    output_data[8] = Register1;
    output_data[9] = Register2;
    return;
}

void Sgen::set_current_c(int Form, int Frequenz)
{
    QMessageBox Debug;

    int pos;

    if (Frequenz <= 10)
    {
        pos = 1;
    }
    else if (Frequenz <= 1000)
    {
        pos = 2;
    }
    else
    {
        pos = 3;
    }

    switch (Form) {
    case 0: //Dignalform Sinus
        Debug.setText("<Sinus> Stellung"+ QString::number(pos));
        break;
    case 1: //Signalform Dreieck
        Debug.setText("<Dreieck> Stellung"+ QString::number(pos));
        break;
    case 2: //Signalform Rechteck
        Debug.setText("<Rechteck> Stellung4");
        break;
    default:
        break;
    }
    Debug.exec();
    return;
}

void Sgen::set_frequency(int Frequenz)
{
    float MCLK = 25000000, Register = 268435456;

    float teiler = MCLK / Register;
    int FRegWert = Frequenz / teiler;

    //block1=lsb --> block4=msb
    unsigned char block1, block2, block3, block4;

    block1 = FRegWert;
    FRegWert = FRegWert >> 8;
    block2 = FRegWert;
    block2 = (block2 | 0x40) & (~0x80);
    FRegWert = FRegWert >> 6;
    block3 = FRegWert;
    FRegWert = FRegWert >> 8;
    block4 = FRegWert;
    block4 = (block4 | 0x40) & (~0x80);

    output_data[2] = block1;
    output_data[3] = block2;
    output_data[4] = block3;
    output_data[5] = block4;
    return;
}

void Sgen::commit_data()
{
    for (int i=0;i<11;i++)
    {
        QMessageBox Ausgabe;
        Ausgabe.setText("<Array, Stelle " + QString::number(i) + " > " + QString::number(output_data[i],2));
        Ausgabe.exec();
    }

    return;
}
