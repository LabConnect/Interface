#include <QMessageBox>
#include "libSgen-V0.1.h"
#include <QTimer>

extern "C" {              /*include C Header*/
#include "usb/hiddata.h"
#include "usb/usbconfig.h"
}

usbDevice_t *dev = NULL;

unsigned char output_data[] = {0x20, 0x00, 0x66, 0x49, 0x01, 0x40, 0xd4, 0xd5, 0x80, 0x7f, 0x01};
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


bool rechteck = false;

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

void Sgen::set_waveform(int Form)
{
    if (Form == 2)
    {
        rechteck = true;
    }
    else
    {
        rechteck = false;
    }
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


    if (rechteck == true)
    {
        output_data[10] = 3;
    }
    else
    {
        if (Frequenz < 500)
        {
            output_data[10] = 3;
        }
        else if (Frequenz < 10000)
        {
            output_data[10] = 2;
        }
        else
        {
            output_data[10] = 1;
        }
    }


}

static usbDevice_t  *openDevice(void)
{
usbDevice_t     *dev = NULL;
unsigned char   rawVid[2] = {USB_CFG_VENDOR_ID}, rawPid[2] = {USB_CFG_DEVICE_ID};
char            vendorName[] = {USB_CFG_VENDOR_NAME, 0}, productName[] = {USB_CFG_DEVICE_NAME, 0};
int             vid = rawVid[0] + 256 * rawVid[1];
int             pid = rawPid[0] + 256 * rawPid[1];
    usbhidOpenDevice(&dev, vid, vendorName, pid, productName, 0);
    return dev;
}

void Sgen::commit_data()
{
    if(usbhidSetReport(dev,output_data,sizeof(output_data)) == NULL)
    {
        QMessageBox error;
        error.setText("FEHLER! Die Verbindung zum USB-Gerät wurde unterbrochen. Bitte prüfe die Verbindungen und versuche es erneut.");
        error.exec();

    }

    /*
    for (int i=0;i<11;i++)
    {
        QMessageBox Ausgabe;
        Ausgabe.setText("<Array, Stelle " + QString::number(i) + " > " + QString::number(output_data[i],16));
        Ausgabe.exec();
    }
    //*/
    return;
}

int Sgen::openUSB()
{
    if((dev=openDevice())==NULL)
    {
        QMessageBox error;
        error.setText("FEHLER! Es wurde kein USB Gerät gefunden. Bitte prüfe die Verbindungen und versuche es erneut.");
        error.exec();
        return 1;
    }
    return 0;
}

