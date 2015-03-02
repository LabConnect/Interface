#include "libUSB-V0.1.h"
#include "libusb.h"
#include <QMessageBox>

namespace USB {

libusb_device_handle *Open(int vid, int pid)
{
    int rc = 0;
    ssize_t cnt = 0;
    libusb_context *ctx = NULL;
    libusb_device **devs = NULL;
    libusb_device_handle *dev_handle; //, *dev_psup;


    rc = libusb_init(&ctx);
    cnt = libusb_get_device_list(ctx, &devs);



    dev_handle = libusb_open_device_with_vid_pid(ctx, vid, pid);

    if (dev_handle == NULL)
    {
        //return 1;
    }

    if(libusb_kernel_driver_active(dev_handle, 0) == 1)
    {
        libusb_detach_kernel_driver(dev_handle, 0);
    }


    libusb_free_device_list(devs, 1);

    return 0;
}
/*
int Write(int data[], int dev_handle){
  libusb_control_transfer(dev_handle, 0x20, 0x09, 0x0300, 0, data, sizeof(data),0)
}

int Read(int data[], int dev_handle){
  libusb_control_transfer(dev_handle, 0x20, 0x09, 0x0300, 0, data, sizeof(data),0)
}
*/
//end namespace
}
