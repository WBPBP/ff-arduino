#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define LEFT
//#define RIGHT

#ifdef LEFT
#define PINS {4, 34, 26, 2, 15, 25, 13, 12, 33, 32, 27, 14}
#elif defined(RIGHT)
#define PINS {...}
#endif


BluetoothSerial SerialBT;

int pin[12] = PINS;
int delimeter = 0xFF;
int data_sensor = 0;
int biggest[12] = {0,};


void setup() {
  Serial.begin(9600);
}


void dumpInput(void) {
  Serial.print("[  ");
  for (int i = 0; i < 12; i++) {
    data_sensor = analogRead(pin[i]);

    if (biggest[i] <= data_sensor)
      biggest[i] = data_sensor;

    if (biggest[i] != 0)
      data_sensor = ((double)data_sensor / (double)biggest[i]) * 4096;

    //Serial.print(biggest[i]);
    Serial.print(data_sensor);
    Serial.print(", ");
    Serial.print(biggest[i]);
    Serial.print("\t");

    //Serial.println(data_sensor);
    //SerialBT.println(data_sensor);
  }
  Serial.println("]");
  SerialBT.println(delimeter);
}


void loop() {
  dumpInput();
}
