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

#include "config.h"

int pins[] = PINS;
int i;

static inline int read_analog(int pin) {
	return map(analogRead(pin), 0, 1 << ADC_WIDTH, 0, 1 << SAMPLE_WIDTH);
}

static inline void read_and_send_sample() {
	for (i = 0; i < N_PINS; ++i)
			Serial.write(read_analog(pins[i]));

	Serial.write(DELIMITER);
}

void setup() {
	Serial.begin(BAUDRATE);
}

void loop() {
	read_and_send_sample();
}
