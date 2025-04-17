/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "features/layer_lock.h"

/**
 * Combo actions
 */
// const uint16_t PROGMEM underscore_combo[] = {OSM(MOD_LSFT), KC_SPC, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(underscore_combo, KC_UNDS)
// };

enum layers {
    BASE = 0,
    SYMBOL,
    NUMPAD,
    NAV,
    MOUSE,
    GAMING,
    NUM_LAYERS  // Total number of layers
};

void unlock_all_layers(void) {
    for (uint8_t layer = BASE; layer < NUM_LAYERS; layer++) {
        if (is_layer_locked(layer)) {
            layer_lock_off(layer);
        }
    }
}

// Declare before key overrides
#define LT_MS_G LT(MOUSE, KC_G)
#define LT_MS_N LT(MOUSE, KC_N)
#define LT_NAV_R LT(NAV, KC_R)
#define LT_NAV_E LT(NAV, KC_E)
#define LT_SYM_T LT(SYMBOL, KC_T)
#define LT_NUM_S LT(NUMPAD, KC_S)
#define LT_SYM_A LT(SYMBOL, KC_A)

#define LALT_V LALT_T(KC_V)
#define LALT_J LALT_T(KC_J)
#define HYPR_C HYPR_T(KC_C)
#define HYPR_Y HYPR_T(KC_Y)
#define LGUI_D LGUI_T(KC_D)
#define LGUI_O LGUI_T(KC_O)
#define LCTL_L LCTL_T(KC_L)
#define LCTL_U LCTL_T(KC_U)
#define LSFT_B LSFT_T(KC_B)
#define LSFT_COMM LSFT_T(KC_COMM)


// get hrm to work on other layers as well..
#define LT_NUM_EQL LT(NUMPAD, KC_EQL)
#define LT_SYM_PLUS LT(SYMBOL, KC_PLUS)
#define LT_NAV_MINS LT(NAV, KC_MINS)


/**
 * Key overrides
 */
// const key_override_t delete_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0, MOD_MASK_CTRL);
const key_override_t exlm_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, LSFT_COMM, KC_EXLM, (1 << BASE), MOD_MASK_CTRL);
// const key_override_t exlm_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_COMM, KC_EXLM, (1 << BASE), MOD_MASK_CTRL);
const key_override_t ques_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DOT, KC_QUES, (1 << BASE), MOD_MASK_CTRL);
const key_override_t unds_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SPC, KC_UNDS, ~0, MOD_MASK_CTRL);
const key_override_t colon_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_COLN, KC_SCLN, (1 << BASE), MOD_MASK_CTRL);
const key_override_t slash_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, (1 << BASE), MOD_MASK_CTRL);
const key_override_t brid_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_VOLD, KC_BRID, ~0, MOD_MASK_CTRL);
const key_override_t briu_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_VOLU, KC_BRIU, ~0, MOD_MASK_CTRL);
const key_override_t f1_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_1, KC_F1, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f2_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_2, KC_F2, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f3_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_3, KC_F3, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f4_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_4, KC_F4, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f5_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_5, KC_F5, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f6_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_6, KC_F6, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f7_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_7, KC_F7, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f8_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_8, KC_F8, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f9_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_9, KC_F9, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f10_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LPRN, KC_F10, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f11_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DOT, KC_F11, (1 << NUMPAD), MOD_MASK_CTRL);
const key_override_t f12_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_RPRN, KC_F12, (1 << NUMPAD), MOD_MASK_CTRL);
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    // &delete_key_override,
    &exlm_key_override,
    &ques_key_override,
    &colon_key_override,
    &slash_key_override,
    &unds_key_override,
    &brid_key_override,
    &briu_key_override,
    &f1_key_override,
    &f2_key_override,
    &f3_key_override,
    &f4_key_override,
    &f5_key_override,
    &f6_key_override,
    &f7_key_override,
    &f8_key_override,
    &f9_key_override,
    &f10_key_override,
    &f11_key_override,
    &f12_key_override,
};



// New keycodes
// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  LLOCK = SAFE_RANGE,
  DDSLASH,
  TGRV,
  // TO_NMP = QK_USER,
};

// static bool move_to_numpad = false;
static bool is_shift_held = false; // For Caps Word
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    // process achordion homerow mods
    if (!process_achordion(keycode, record)) { return false; }

    // Update Shift State for Caps Word
    if (keycode==KC_LSFT || keycode==OSM(MOD_LSFT)) {
        is_shift_held = record->event.pressed;
    }
    // If caps word is on and the pressed key is space
    if (is_caps_word_on() && keycode==KC_SPC) {
        // Send underscore if shift is held (on key press)
        if (is_shift_held && record->event.pressed) {
            tap_code16(KC_UNDS);
        }
        // Disable caps word if shift isn't held
        else if (record->event.pressed){
            caps_word_off();
        }
        // Do not process further
        return false;
    }

    static bool kc_shift = false;
    switch (keycode) {
        // Raise shift before clicking = after + or !
        case KC_RABK:
        case KC_LABK:
        case KC_EXLM:
        case KC_PLUS:
            kc_shift = record->event.pressed;
            break;
        case KC_EQUAL:
            if (record->event.pressed && kc_shift) {
                del_weak_mods(MOD_LSFT);
                // del_mods(MOD_LSFT);
                send_keyboard_report();
            }
            break;

        // case TO_NMP:
        //     if (record->event.pressed)
        //         move_to_numpad = true;
        //     return false;

        // Unlock LLOCK'ed layers on ESC
        case LCTL_T(KC_ESC):
            if (!record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    // Key was tapped (Escape)
                    unlock_all_layers();
                }
                // For both tap and hold, allow default behavior
                return true;
            }
            break;

        case TGRV:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case DDSLASH:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;

        default:
            break;
    }

    // Process Other Keycodes Normally
    return true;
}

// /**
//  * Moves to the numpad layer on key press while ensuring the symbol layer is on
//  */
// void housekeeping_task_user(void) {
//     if (move_to_numpad) {
//         move_to_numpad = false;
//         layer_move(SYMBOL);
//         layer_on(NUMPAD);
//     }
// }

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
    case LCTL_T(KC_ESC):
    case OSM(MOD_LSFT):
      return true;
  }

  switch (other_keycode) {
    case LCTL_T(KC_ESC):
    case OSM(MOD_LSFT):
      return true;
  }

  // Allow same-hand holds when the other key is in the rows below the alphas
  // if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }
  // if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  // switch (tap_hold_keycode) {
  //   // skip handling LCTL_T(KC_ESC) with achordion
  //   case LCTL_T(KC_ESC):
  //     return 0;
  // }

  return 1000;
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  return 200;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    return 0;
    switch (keycode) {
        // case SFT_T(KC_SPC):
            // return QUICK_TAP_TERM - 20;
        default:
            return 0;
            // return QUICK_TAP_TERM;
    }
}

/**
 * Tap dances
 */
enum {
  TD_RESET, // Reset the keyboard if tapped more than three times
  TD_UNTG, // Untoggle the NUMPAD layer on hold, send 0 on press
  TD_BASE_NAV // Base layer navigation
};

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;



// Declare the functions to be used with your tap dance key(s)
// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);
// Functions associated with individual tap dances
// void ql_finished(tap_dance_state_t *state, void *user_data);
// void ql_reset(tap_dance_state_t *state, void *user_data);
void safe_reset(tap_dance_state_t *state, void *user_data);
void base_nav_finished(tap_dance_state_t *state, void *user_data);
void base_nav_reset(tap_dance_state_t *state, void *user_data);




bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_MS_G:
        case LT_MS_N:
        case LT_NAV_R:
        case LT_NAV_E:
        case LT_SYM_T:
        case LT_NUM_S:
        case LT_SYM_A:
        case LT_NUM_EQL:
        case LT_SYM_PLUS:
        case LT_NAV_MINS:

        case LALT_V:
        case LALT_J:
        case HYPR_C:
        case HYPR_Y:
        case LGUI_D:
        case LGUI_O:
        case LCTL_L:
        case LCTL_U:
        case LSFT_B:
        case LSFT_COMM:
            return true;
        default:
            return false;
    }
}

#define ________________LEFT_HAND_SYMBOLS_ROW_1________________ _______, TGRV, KC_RABK, KC_LABK, KC_GRV, KC_PERC, KC_DLR
#define ________________LEFT_HAND_SYMBOLS_ROW_2________________ _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH, KC_COLN
// #define ________________LEFT_HAND_SYMBOLS_ROW_2________________ _______, KC_EXLM, LT_NAV_MINS, KC_PLUS,  LT_NUM_EQL, KC_HASH, KC_COLN
// #define ________________LEFT_HAND_NUMBERS_ROW_2________________ _______, KC_EXLM, LT_NAV_MINS, LT_SYM_PLUS,  KC_EQL, KC_HASH, KC_COLN
#define ________________LEFT_HAND_SYMBOLS_ROW_3________________ _______, KC_DQUO, DDSLASH,  TGRV, KC_ASTR, KC_CIRC, KC_AT

#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                    ,------------------------------------------------------.
      KC_VOLD,  LSFT_B,   LCTL_L,   LGUI_D,   HYPR_C,  LALT_V,                       LALT_J,  HYPR_Y,   LGUI_O, LCTL_U, LSFT_COMM, KC_VOLU,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
       KC_TAB, LT_MS_N, LT_NAV_R, LT_SYM_T, LT_NUM_S, LT_MS_G,                         KC_P,    KC_H, LT_SYM_A,LT_NAV_E,    KC_I, KC_COLN,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
      XXXXXXX,    KC_X,     KC_Q,     KC_M,     KC_W,    KC_Z,                         KC_K,    KC_F,  KC_QUOT, KC_SLSH,  KC_DOT, XXXXXXX,
  //|--------+--------+---------+---------+---------+--------+--------|  |--------+--------+--------+---------+--------+--------+--------|
                                  XXXXXXX,OSM(MOD_LSFT),LCTL_T(KC_ESC),     KC_ENT,  KC_SPC,  XXXXXXX
                                 // TT(NAV),OSM(MOD_LSFT),LCTL_T(KC_ESC),    KC_ENT,  KC_SPC,    QK_REP
                                         //`--------------------------'  `--------------------------'

  ),

    [SYMBOL] = LAYOUT_split_3x6_3_wrapper(
  //,-----------------------------------------------------.                    ,-------------------------------------------------------.
   ________________LEFT_HAND_SYMBOLS_ROW_1________________,                               KC_LCBR, KC_AMPR, KC_RPRN,    KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_2________________,                               KC_LPRN, KC_PIPE, KC_LBRC,   KC_BSPC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_3________________,                               KC_RBRC, KC_TILD, KC_RCBR,LCTL(KC_BSPC), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+----------+--------|
                                          _______, _______, _______,      LLOCK, _______,    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [NUMPAD] = LAYOUT_split_3x6_3_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   ________________LEFT_HAND_SYMBOLS_ROW_1________________,                                  KC_4,    KC_5,    KC_6, KC_LPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_2________________,                                  KC_1,    KC_2,    KC_3,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_3________________,                                  KC_7,    KC_8,    KC_9, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,      LLOCK, _______,    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  // [SYMBOL] = LAYOUT_split_3x6_3(
  //  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //   _______, KC_QUOT, KC_RABK, KC_LABK, KC_SLSH, KC_PERC,                       KC_DLR, KC_LCBR, KC_AMPR, KC_RPRN, _______, _______,
  //  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,                      KC_COLN, KC_LPRN, KC_PIPE, KC_LBRC, KC_QUES, _______,
  //  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   _______, KC_DQUO, KC_BSLS,  KC_GRV, KC_ASTR, KC_CIRC,                        KC_AT, KC_RBRC, KC_TILD, KC_RCBR, _______, _______,
  //  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                               TD(TD_BASE_NAV), _______, _______,    LLOCK, _______,  TO_NMP
  //                                   //`--------------------------'  `--------------------------'
  //  ),
  //
  // [NUMPAD] = LAYOUT_split_3x6_3(
  //  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //   _______, _______, _______, _______, _______, _______,                      _______,    KC_4,    KC_5,    KC_6, KC_LPRN, _______,
  //  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   _______, _______, _______, _______, _______, _______,                      _______,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
  //  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //   _______, _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, KC_RPRN, _______,
  //  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                               TD(TD_BASE_NAV), _______, _______,    LLOCK, _______,    KC_0
  //                                   //`--------------------------'  `--------------------------'
  //  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 TD(TD_RESET), MS_WHLU, MS_BTN2,   MS_UP, MS_BTN1,TO(GAMING),                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, MS_WHLL, XXXXXXX, MS_WHLR, XXXXXXX,                      DT_PRNT,   DT_UP, DT_DOWN, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,      LLOCK, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_ACL2, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, MS_ACL0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,      LLOCK, MS_BTN1, MS_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

    [GAMING] = LAYOUT_split_3x6_3(
  //,-----------------.-----------------------------------                    ,-----------------------------------------------------.
      KC_VOLD,    KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_VOLU,
  //|--------+--------|-------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,
  //|--------+--------|-------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------|
      KC_RALT,    KC_B,   KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,TO(BASE),
  //|--------+--------+-------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT,  KC_SPC,     KC_ENT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

// static td_tap_t ql_tap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };
// // Functions that control what tap dance key does
// void ql_finished(tap_dance_state_t *state, void *user_data) {
//     ql_tap_state.state = cur_dance(state);
//     switch (ql_tap_state.state) {
//         case TD_SINGLE_TAP:
//             tap_code(KC_0);
//             reset_tap_dance(state);  // Reset the tap dance state immediately to prevent delay
//             break;
//         case TD_SINGLE_HOLD:
//             layer_off(NUMPAD);
//             break;
//         default:
//             break;
//     }
// }
// void ql_reset(tap_dance_state_t *state, void *user_data) {
//     // If the key was held down and now is released then switch on the layer
//     if (ql_tap_state.state == TD_SINGLE_HOLD) {
//         layer_on(NUMPAD);
//     }
//     ql_tap_state.state = TD_NONE;
// }

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

/**
 * Reset the keyboard safely
 */
void safe_reset(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 0) {
    // Reset the keyboard if you tap the key three or more times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

// Initialize tap structure associated with example tap dance key
static td_tap_t base_nav_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void base_nav_finished(tap_dance_state_t *state, void *user_data) {
    base_nav_tap_state.state = cur_dance(state);
    switch (base_nav_tap_state.state) {
        case TD_SINGLE_TAP:
            layer_move(BASE);
            break;
        case TD_SINGLE_HOLD:
            layer_on(NAV);
            break;
        case TD_DOUBLE_TAP:
            layer_move(NAV);
        default:
            break;
    }
}

void base_nav_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (base_nav_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(NAV);
    }
    base_nav_tap_state.state = TD_NONE;
}


// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset),
    // [TD_UNTG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
    [TD_BASE_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_nav_finished, base_nav_reset),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Set a long-ish tapping term for tap-dance keys
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 175;
        case OSM(MOD_LSFT):
        // case MOD_LSFT:
        // case KC_LSFT:
            return 200;
        default:
            return TAPPING_TERM;
    }
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        // case KC_SPC:
        //     if (is_shift_held) {
        //         // User is holding Shift; send underscore and keep Caps Word on.
        //         tap_code16(KC_UNDS);
        //         return true;
        //     } else {
        //         // No Shift; deactivate Caps Word and send space.
        //         return false;
        //     }
        // case KC_SPC:
            // add_mods(MOD_BIT(KC_LSFT));
            // return true;

        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        // case KC_1 ... KC_0:
        case KC_MINS:
        case KC_BSPC:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
