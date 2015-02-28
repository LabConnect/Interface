#include "libPsup-V0.1.h"
#include "../libUSB/libUSB-V0.1.h"
class Psup {
public:
  int   Init(int pid, int vid);
  void  SetVoltage(float voltage);
  void  SetCurrent(float current);
  void  ReadVoltageBuffer(int &voltage, int &timestamp);
  void  ReadCurrentBuffer(int &current, int &timestamp);
private:
	libusb_device_handle *_dev_handle;
}

void Psup::Init(int vid, int pid){
  _dev_handle = USB::Open(vid, pid);
}

void Psup::SetVoltage(float volgae){

}

void Psup::SetCurrent(float current){

}

void Psup::ReadVoltageBuffer(int &voltage, int &timestamp){

}

void Psup::ReadCurrentBuffer(int &current, int &timestamp){

}
