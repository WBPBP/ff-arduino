#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define SENSOR_PIN 25

BluetoothSerial SerialBT;
int value = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32TestNew"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
 }

void dumpInput(int pinNumber) {
  value = analogRead(pinNumber);

  Serial.print(pinNumber);
  Serial.print(": ");
  Serial.println(value);
  
  SerialBT.println(value);
}

void loop() {
  dumpInput(SENSOR_PIN);

   // delay(20);
}
