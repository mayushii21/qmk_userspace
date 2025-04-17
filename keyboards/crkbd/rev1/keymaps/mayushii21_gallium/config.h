/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

/* #ifdef RGBLIGHT_ENABLE */
/*     #define RGBLIGHT_EFFECT_BREATHING */
/*     #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/*     #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/*     #define RGBLIGHT_EFFECT_SNAKE */
/*     #define RGBLIGHT_EFFECT_KNIGHT */
/*     #define RGBLIGHT_EFFECT_CHRISTMAS */
/*     #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
/*     #define RGBLIGHT_EFFECT_RGB_TEST */
/*     #define RGBLIGHT_EFFECT_ALTERNATING */
/*     #define RGBLIGHT_EFFECT_TWINKLE */
/*     #define RGBLIGHT_LIMIT_VAL 120 */
/*     #define RGBLIGHT_HUE_STEP 10 */
/*     #define RGBLIGHT_SAT_STEP 17 */
/*     #define RGBLIGHT_VAL_STEP 17 */
/* #endif */

// #define KEY_OVERRIDE_INCLUDE_WEAK_MODS
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
/*#define RETRO_TAPPING*/
/*#define RETRO_TAPPING_PER_KEY*/

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 0

#define TAPPING_TOGGLE 2

#define LAYER_STATE_8BIT

#define NO_ALT_REPEAT_KEY // reduce firmware size
#define PERMISSIVE_HOLD
#define ACHORDION_STREAK

// MouseKey stuff
#define MOUSEKEY_DELAY          3
#define MOUSEKEY_INTERVAL       4  // 1//240(refresh rate)*1000
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      5
#define MOUSEKEY_TIME_TO_MAX    32


/*#define MK_KINETIC_SPEED*/
/*#define MOUSEKEY_MOVE_DELTA     100*/
/*#define MOUSEKEY_INITIAL_SPEED  700*/

#define MOUSEKEY_INERTIA
#define MOUSEKEY_FRICTION 24 // How quickly the cursor stops after releasing a key
#define MOUSEKEY_MOVE_DELTA	1

