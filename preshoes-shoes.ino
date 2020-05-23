#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int pin[12] = {34, 32, 33, 25, 26, 27, 14, 12, 13, 4, 2, 15};
int delimeter = 0xFF;
int data_sensor = 0;


void setup() {
  Serial.begin(9600);
}


void dumpInput(void) {
  for (int i = 0; i < 12; i++) {
    data_sensor = analogRead(pin[i]) >> 8;
    Serial.println(data_sensor);
    SerialBT.println(data_sensor);
  }
  SerialBT.println(delimeter);
}


void loop() {
  dumpInput();
}
