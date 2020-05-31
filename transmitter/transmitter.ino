/**
 * Transmitter
 */
 
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define LEFT
//#define RIGHT

#ifdef LEFT
#define NAME "PreshoesLeft"
#elif defined(RIGHT)
#define NAME "PreshoesRight"
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin(NAME);
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
}
