#include "libUSB-V0.1.h"
#include "libusb.h"

usb_device_t *dev = NULL;


int Sgen::Open()
{
    ssize_t cnt = 0;
    libusb_context *ctx = NULL;
    libusb_device **devs;
    libusb_init(&ctx);
    cnt = libusb_get_device_list(ctx, &devs);
    
    for(int i=0; i<10; i++){
        QMessageBox Device;
        Device.setText(devs[i]);
        Device.exec();
    }
    QMessageBox DevicesFound;
    DevicesFound.setText("Number of Devices found:" + QString::number(cnt,10));
    DevicesFound.exec();
}