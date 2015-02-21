namespace Psup {
// set voltage (0-4095;1,XV-2XV)
void SetVoltage(float voltage);
// set current
void SetCurrent(float current);
// read last 10 voltage values
void ReadVoltage(int &voltage, int &timestamp);
// read last 10 current values
void ReadCurrent(int &current, int &timestamp);
}