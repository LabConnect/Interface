#include <libusb.h>
class Psup {
public:
   Psup(unsigned int vid, unsigned int pid);
    ~Psup();
  /* 0 = everything is fine
   * 1 = device not found
   * 2 = write failure
   * 3 = read failure
   */
  int state = 0;
  void Init(void);
  void SetVoltage(float voltage);
  void SetCurrent(float current);
  void ReadVoltageBuffer(int &voltage, int &timestamp);
  void ReadCurrentBuffer(int &current, int &timestamp);
private:
  libusb_device_handle *_dev_handle;
  libusb_context *_ctx = NULL;
};

Psup::Psup(unsigned int vid, unsigned int pid){
  state = libusb_init(&_ctx);
  if (state >= 0){
    _dev_handle = libusb_open_device_with_vid_pid(_ctx,vid,pid);
    if (_dev_handle == NULL)
      state = 1;
    state = 0;
  }

}

Psup::~Psup(){
  libusb_close(_dev_handle);
  libusb_exit(_ctx);
}

void Psup::SetVoltage(float voltage){
  //libusb_control_transfer(_dev_handle,0b00100001,0x09,0x0300,);
}

void Psup::SetCurrent(float current){

}

void Psup::ReadVoltageBuffer(int &voltage, int &timestamp){

}

void Psup::ReadCurrentBuffer(int &current, int &timestamp){

}
