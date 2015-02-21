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
    
    QMessageBox Gefunden;
    Gefunden.setText("Vendor:Device =" + QString::number(desc.idVendor,16) + ":" + QString::number(desc.idProduct,16));
    Gefunden.exec();
  }
  
  QMessageBox DevicesFound;
  DevicesFound.setText("Number of Devices found:" + QString::number(cnt,10));
  DevicesFound.exec();

  return 0;
}

int Write(int data[], int size){
  
}

//end namespace
}
