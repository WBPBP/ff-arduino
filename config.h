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

#ifndef _config_h
#define _config_h

// IO
#define BAUDRATE 115200
#define ADC_WIDTH 12

// HW setup
#define N_PINS 12
#define PINS {2, 4, 15, 34, 32, 33, 25, 26, 14, 27, 13, 12}

// Protocol
#define SAMPLE_WIDTH 4
#define DELIMITER 0xFF

#endif /* _config_h */
