#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int pin[12] = {34, 32, 33, 25, 26, 27, 14, 12, 13, 4, 2, 15};
int datas[12] = {};
int ret[12] = {};


void setup() {
  Serial.begin(9600);
}


void dumpInput(void) {
  for (int i = 0; i < 12; i++) {
    datas[i] = analogRead(pin[i]) / 256;
    ret[i] = ((i << 4) & 0xF0) + (datas[i] & 0xF);
    Serial.println(ret[i]);
    SerialBT.println(ret[i]);
  }
}


void loop() {
  dumpInput();
}
