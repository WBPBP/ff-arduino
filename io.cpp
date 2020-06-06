/**
* Copyright (C) 2020 WBPBP <potados99@gmail.com>
*
* This file is part of Preshoes (https://github.com/WBPBP).
*
* Preshoes is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Preshoes is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "io.h"
#include "config.h"

#include <Arduino.h>

void io_init() {
  Serial.begin(BAUDRATE);
}

static inline void _send(int byte) {
  Serial.write(byte);
}

static inline int _read_sample(int pin) {
  int value = min((int)analogRead(pin), ADC_VALUE_WHEN_PRESSURE_MAX);

  return map(value, 0, ADC_VALUE_WHEN_PRESSURE_MAX, 0, SAMPLE_MAX);
}

static inline int _read_battery() {
  return map(analogRead(PIN_BATTERY), 0, ADC_VALUE_WHEN_BATTERY_FULL, 0, 100);
}

void io_read_and_send_samples() {
  _send((0xFF << 4) | TYPE_SAMPLE); // Following 12 bytes will be sent.

  _send(_read_sample(PIN_SENSOR_0));
  _send(_read_sample(PIN_SENSOR_1));
  _send(_read_sample(PIN_SENSOR_2));
  _send(_read_sample(PIN_SENSOR_3));

  _send(_read_sample(PIN_SENSOR_4));
  _send(_read_sample(PIN_SENSOR_5));
  _send(_read_sample(PIN_SENSOR_6));
  _send(_read_sample(PIN_SENSOR_7));

  _send(_read_sample(PIN_SENSOR_8));
  _send(_read_sample(PIN_SENSOR_9));
  _send(_read_sample(PIN_SENSOR_10));
  _send(_read_sample(PIN_SENSOR_11));

  delay(10);
}

void io_read_and_send_battery() {
  _send((0xFF << 4) | TYPE_BATTERY); // Following 1 byte will be sent.

  _send(_read_battery());
}
