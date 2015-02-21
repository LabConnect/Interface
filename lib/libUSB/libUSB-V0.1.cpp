#include "libUSB-V0.1.h"
#include "libusb.h"
#include <QMessageBox>

namespace USB {

int Open()
{
  int rc = 0;
  ssize_t cnt = 0;
  libusb_context *ctx = NULL;
  libusb_device **devs = NULL;

  rc = libusb_init(&ctx);
  cnt = libusb_get_device_list(ctx, &devs);
  
  for (size_t idx = 0; idx < cnt; ++idx)
  {
    libusb_device *device = devs[idx];
    libusb_device_descriptor desc = {0};
    
    rc = libusb_get_device_descriptor(device, &desc);
    
    if (desc.idVendor == 0x123 && desc.idProduct == 0x123)
    {

    }
    

  }
  
  QMessageBox DevicesFound;
  DevicesFound.setText("Number of Devices found:" + QString::number(cnt,10));
  DevicesFound.exec();

  return 0;
}
/*
int Write(int data[], int dev_handle){
  libusb_control_transfer(dev_handle, 0x20, 0x09, 0x0300, 0, data, sizeof(data),0)
  return 0;
}

int Read(int data[], int dev_handle){
  libusb_control_transfer(dev_handle, 0x20, 0x09, 0x0300, 0, data, sizeof(data),0)
  return 0;
}
//*/
//end namespace
}