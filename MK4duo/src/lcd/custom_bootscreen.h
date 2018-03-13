/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Custom Bitmap for splashscreen
 *
 * You may use one of the following tools to generate the C++ bitmap array from
 * a black and white image:
 *
 *  - http://www.marlinfw.org/tools/u8glib/converter.html
 *  - http://www.digole.com/tools/PicturetoC_Hex_converter.php
 */
#include <avr/pgmspace.h>

#define CUSTOM_BOOTSCREEN_TIMEOUT   2500
#define CUSTOM_BOOTSCREEN_BMPWIDTH  63
#define CUSTOM_BOOTSCREEN_BMPHEIGHT 64

const unsigned char custom_start_bmp[512] PROGMEM = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00
,0x00,0x00,0x00,0xff,0xfe,0x00,0x00,0x00
,0x00,0x00,0x07,0xff,0xff,0xc0,0x00,0x00
,0x00,0x00,0x0f,0xff,0xff,0xe0,0x00,0x00
,0x00,0x00,0x3f,0xff,0xff,0xf8,0x00,0x00
,0x00,0x00,0x7f,0xff,0xff,0xfc,0x00,0x00
,0x00,0x00,0xff,0xff,0xff,0xfe,0x00,0x00
,0x00,0x00,0xff,0xff,0xff,0xfe,0x00,0x00
,0x00,0x01,0xff,0xff,0xff,0xff,0x00,0x00
,0x00,0x03,0xff,0xff,0xff,0xff,0x80,0x00
,0x00,0x03,0xff,0xff,0xff,0xff,0x80,0x00
,0x00,0x03,0xff,0xff,0xff,0xff,0x80,0x00
,0x00,0x07,0xff,0xff,0xff,0xff,0xc0,0x00
,0x00,0x07,0xff,0xff,0xff,0xff,0xc0,0x00
,0x00,0x07,0xff,0xff,0xff,0xff,0xc0,0x00
,0x00,0x03,0xff,0xff,0xff,0xff,0x80,0x00
,0x00,0x03,0x80,0x00,0x00,0x03,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x01,0xff,0xff,0xf8,0xff,0x00,0x00
,0x00,0x0f,0x80,0x0f,0xe0,0x03,0xe0,0x00
,0x00,0x1f,0x80,0x3f,0xf0,0x03,0xf0,0x00
,0x00,0x3f,0x80,0x78,0x3c,0x03,0xf8,0x00
,0x00,0x3f,0x80,0xff,0xfe,0x03,0xf8,0x00
,0x00,0x3f,0xc3,0xff,0xff,0x87,0xf8,0x00
,0x00,0x3f,0xef,0xff,0xff,0xef,0xf8,0x00
,0x00,0x3f,0xff,0xff,0xff,0xfe,0xf8,0x00
,0x00,0x3e,0xfe,0xff,0xfe,0xfe,0xf8,0x00
,0x00,0x3e,0x73,0xff,0xff,0x9c,0xf8,0x00
,0x00,0x3e,0x0f,0xff,0xff,0xe0,0xf8,0x00
,0x00,0x3e,0x7f,0xfc,0x7f,0xfc,0xf8,0x00
,0x00,0x7e,0xff,0xf0,0x1f,0xff,0xfc,0x00
,0x00,0xff,0xff,0xf0,0x1f,0xff,0xfe,0x00
,0x00,0xff,0xff,0xc7,0xc7,0xff,0xfe,0x00
,0x01,0xef,0xff,0xdf,0xf7,0xff,0xef,0x00
,0x01,0xc7,0xff,0x7f,0xfd,0xff,0xd7,0x00
,0x03,0xf3,0xff,0xff,0xff,0xff,0x9f,0x80
,0x03,0xf9,0xff,0xff,0xff,0xff,0x7f,0x80
,0x03,0xfe,0xff,0xff,0xff,0xfe,0xff,0x80
,0x01,0xfd,0xff,0xff,0xff,0xef,0xff,0x00
,0x01,0xff,0xbf,0xff,0xff,0xf3,0xff,0x00
,0x00,0xfc,0xff,0xff,0xff,0xfe,0x7e,0x00
,0x00,0x77,0xff,0xfc,0x7f,0xff,0x9c,0x00
,0x00,0x6f,0xff,0xf8,0x3f,0xff,0xe8,0x00
,0x00,0x0f,0xff,0xf0,0x1f,0xff,0xe8,0x00
,0x00,0x0f,0xff,0xf0,0x1f,0xff,0xe0,0x00
,0x00,0x1f,0xff,0xf0,0x1f,0xff,0xf0,0x00
,0x00,0x1f,0xe7,0xe0,0x0f,0xcf,0xe0,0x00
,0x00,0x0f,0xc7,0xe0,0x0f,0xc7,0xe0,0x00
,0x00,0x0f,0xc7,0xa0,0x0b,0xc7,0xe0,0x00
,0x00,0x07,0xc0,0xa0,0x0a,0x47,0xc0,0x00
,0x00,0x03,0xc0,0x38,0x38,0x07,0x80,0x00
,0x00,0x01,0xe0,0x7f,0xfc,0x0f,0x00,0x00
,0x00,0x00,0xf0,0xf0,0x1e,0x1e,0x00,0x00
,0x00,0x00,0x3f,0xe0,0x1f,0xf8,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
