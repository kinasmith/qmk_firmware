/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"
/**
 * 14 Columns
 * 6 rows
 */
#define MATRIX_COL_PINS { B12, B13, B14, B15, A8, A9, A10, B7, B8, A15, B3, B4, B5, B6 } //don't use A11 and A12, they're USB COMS
#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5 }
#define UNUSED_PINS

// #define CAPS_LED_PIN B9
// #define LOCK1_LED_PIN A7
// #define LOCK2_LED_PIN B0

#define RGB_DI_PIN B11
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS
#define RGBLED_NUM 6
#define RGBLIGHT_HUE_STEP 16
#define RGBLIGHT_SAT_STEP 16
#define RGBLIGHT_VAL_STEP 16
