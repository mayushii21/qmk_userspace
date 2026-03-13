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

// --- COMBO ACTIONS ---

// const uint16_t PROGMEM underscore_combo[] = {OSM(MOD_LSFT), KC_SPC, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(underscore_combo, KC_UNDS)
// };

// --- LAYER DEFINITIONS ---

enum layers {
    BASE = 0,
    SYMBOL,
    NUMPAD,
    NAV,
    MOUSE,
    GAMING,
    BASE_BASE,
    QWERTY,
    NUM_LAYERS  // Total number of layers
};

/**
 * Iterates through all available layers and forces them to unlock.
 * Used as a panic/reset button bound to the Escape key.
 */
void unlock_all_layers(void) {
    for (uint8_t layer = BASE; layer < NUM_LAYERS; layer++) {
        if (is_layer_locked(layer)) {
            layer_lock_off(layer);
        }
    }
}

// --- MACROS & KEYCODES ---

// Declare before key overrides
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
#define LSFT_L LSFT_T(KC_L)
#define LSFT_U LSFT_T(KC_U)
#define LCTL_B LCTL_T(KC_B)
#define LCTL_COMM LCTL_T(KC_COMM)

// TODO: get hrm to work on other layers as well..
// #define LT_NUM_EQL LT(NUMPAD, KC_EQL)
// #define LT_SYM_PLUS LT(SYMBOL, KC_PLUS)
// #define LT_NAV_MINS LT(NAV, KC_MINS)

// New keycodes
// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  // LLOCK = SAFE_RANGE,
  DDSLASH = SAFE_RANGE,
  TGRV,
  LMAGIC,
  RMAGIC,
};

// --- KEY OVERRIDES ---

/**
 * Custom callbacks for QK_REP (Repeat Key).
 * Strips weak/oneshot modifiers before registering the Backspace, ensuring
 * the Repeat Key repeats the action without dragging unwanted modifiers along.
 */
// 1) Custom action: record the Backspace for repeat
bool record_bspc_for_repeat(bool activated, void *context) {
    // Only do it on the *press* activation, not on release
    if (activated) {
        set_last_keycode(KC_BSPC);
        // Strip weak/oneshot so we only record real modifiers
        set_last_mods(get_mods() & ~(get_weak_mods() | get_oneshot_mods()));
    }
    // Return true so QMK still sends the replacement key
    return true;
}
bool record_wbspc_for_repeat(bool activated, void *context) {
    // Only do it on the *press* activation, not on release
    if (activated) {
        set_last_keycode(C(KC_BSPC));
        // Strip weak/oneshot so we only record real modifiers
        set_last_mods(get_mods() & ~(get_weak_mods() | get_oneshot_mods()));
    }
    // Return true so QMK still sends the replacement key
    return true;
}

// 2) Build override, then attach your action
static key_override_t bspc_key_override =
    ko_make_basic(MOD_MASK_SHIFT, RMAGIC, KC_BSPC);
static key_override_t wbspc_key_override =
    ko_make_basic(MOD_MASK_CTRL,  RMAGIC, LCTL(KC_BSPC));

// Attach the callback to the override’s custom_action slot:
__attribute__((constructor))  // run before main()
static void attach_override_callbacks(void) {
    bspc_key_override.custom_action  = record_bspc_for_repeat;
    wbspc_key_override.custom_action = record_wbspc_for_repeat;
}

// const key_override_t delete_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0, MOD_MASK_CTRL);
const key_override_t exlm_key_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, LCTL_COMM, KC_EXLM, (1 << BASE), MOD_MASK_CTRL);
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

// --- Gaming layer: only when Shift is held ---
const key_override_t go_esc_to_1 =
    ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_ESC, KC_1, (1 << GAMING), 0);
const key_override_t go_tab_to_2 =
    ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_TAB, KC_2, (1 << GAMING), 0);
const key_override_t go_t_to_4 =
    ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_T,   KC_4, (1 << GAMING), 0);
const key_override_t go_g_to_5 =
    ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_G,   KC_5, (1 << GAMING), 0);
const key_override_t go_b_to_6 =
    ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_B,   KC_6, (1 << GAMING), 0);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    // Gaming overrides must come first
    &go_esc_to_1,
    &go_tab_to_2,
    &go_t_to_4,
    &go_g_to_5,
    &go_b_to_6,

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
    &wbspc_key_override,
    &bspc_key_override,
    NULL
};

// --- QMK INTERNAL CALLBACKS ---

/**
 * Ensures specific dual-role keys (like Escape/Ctrl or OSM Shift) resolve
 * to their Hold function immediately if another key is pressed, ignoring the default
 * typing delay rules.
 */
bool get_chordal_hold(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    // Always allow these dual-role keys to act as hold when chorded:
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
    // Fallback to the default opposite-hands rule:
    return get_chordal_hold_default(tap_hold_record, other_record);
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

// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT_MS_N:
//         case LT_NAV_R:
//         case LT_NAV_E:
//         case LT_SYM_T:
//         case LT_NUM_S:
//         case LT_SYM_A:
//         case LT_NUM_EQL:
//         case LT_SYM_PLUS:
//         case LT_NAV_MINS:
//
//         case LALT_V:
//         case LALT_J:
//         case HYPR_C:
//         case HYPR_Y:
//         case LGUI_D:
//         case LGUI_O:
//         case LSFT_L:
//         case LSFT_U:
//         case LCTL_B:
//         case LCTL_COMM:
//             return true;
//         default:
//             return false;
//     }
// }

// --- KEYMAPS ---

#define ________________LEFT_HAND_SYMBOLS_ROW_1________________ _______, XXXXXXX, KC_RABK, KC_LABK, KC_GRV, TGRV, KC_DLR
#define ________________LEFT_HAND_SYMBOLS_ROW_2________________ _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH, KC_PERC
// #define ________________LEFT_HAND_SYMBOLS_ROW_2________________ _______, KC_EXLM, LT_NAV_MINS, KC_PLUS,  LT_NUM_EQL, KC_HASH, KC_COLN
// #define ________________LEFT_HAND_NUMBERS_ROW_2________________ _______, KC_EXLM, LT_NAV_MINS, LT_SYM_PLUS,  KC_EQL, KC_HASH, KC_COLN
#define ________________LEFT_HAND_SYMBOLS_ROW_3________________ _______, XXXXXXX, DDSLASH,XXXXXXX, KC_ASTR, KC_CIRC, KC_AT

#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                    ,------------------------------------------------------.
      KC_VOLD,  LCTL_B,   LSFT_L,   LGUI_D,   HYPR_C,  LALT_V,                       LALT_J,  HYPR_Y,   LGUI_O, LSFT_U, LCTL_COMM, KC_VOLU,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
       KC_TAB, LT_MS_N, LT_NAV_R, LT_SYM_T, LT_NUM_S,    KC_G,                         KC_P,    KC_H, LT_SYM_A,LT_NAV_E,    KC_I, KC_COLN,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
      CW_TOGG,    KC_X,     KC_Q,     KC_M,     KC_W,    KC_Z,                         KC_K,    KC_F,  KC_QUOT, KC_SLSH,  KC_DOT, XXXXXXX,
  //|--------+--------+---------+---------+---------+--------+--------|  |--------+--------+--------+---------+--------+--------+--------|
                                  LMAGIC,OSM(MOD_LSFT),LCTL_T(KC_ESC),     KC_ENT,  KC_SPC,  RMAGIC
                                      //`--------------------------'  `--------------------------'

  ),

    [SYMBOL] = LAYOUT_split_3x6_3_wrapper(
  //,-----------------------------------------------------.                    ,-------------------------------------------------------.
   ________________LEFT_HAND_SYMBOLS_ROW_1________________,                               KC_AMPR, KC_PIPE, KC_TILD,   XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_2________________,                               KC_LPRN, KC_LBRC, KC_LCBR,    KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_3________________,                               KC_RPRN, KC_RBRC, KC_RCBR,   XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+----------+--------|
                                          _______, _______, _______,    QK_LLCK, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NUMPAD] = LAYOUT_split_3x6_3_wrapper(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   ________________LEFT_HAND_SYMBOLS_ROW_1________________,                                  KC_4,    KC_5,    KC_6, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_2________________,                                  KC_1,    KC_2,    KC_3,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   ________________LEFT_HAND_SYMBOLS_ROW_3________________,                                  KC_7,    KC_8,    KC_9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    QK_LLCK, _______,    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, MS_WHLU, MS_WHLL,   MS_UP, MS_WHLR,TO(GAMING),                    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT,TO(BASE_BASE),                 KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5,TO(QWERTY),                  C(KC_LEFT),C(KC_DOWN),C(KC_UP),C(KC_RIGHT),XXXXXXX,_______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    QK_LLCK, MS_BTN1, MS_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

    [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_ACL2, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, MS_ACL0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      DT_PRNT,   DT_UP, DT_DOWN, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    QK_LLCK, MS_BTN1, MS_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

    [GAMING] = LAYOUT_split_3x6_3(
  //,-----------------.-----------------------------------                    ,-----------------------------------------------------.
         KC_T,  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_VOLU,
  //|---------|--------+------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------|
         KC_G,  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_VOLD,
  //|--------+--------|-------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------|
         KC_B, KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,TO(BASE),
  //|--------+--------+-------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT,  KC_SPC,     KC_ENT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [BASE_BASE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                    ,------------------------------------------------------.
      KC_VOLD,    KC_B,     KC_L,     KC_D,     KC_C,    KC_V,                         KC_J,    KC_Y,     KC_O,    KC_U, KC_COMM, KC_VOLU,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
       KC_TAB,    KC_N,     KC_R,     KC_T,     KC_S,    KC_G,                         KC_P,    KC_H,     KC_A,    KC_E,    KC_I, KC_COLN,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
      CW_TOGG,    KC_X,     KC_Q,     KC_M,     KC_W,    KC_Z,                         KC_K,    KC_F,  KC_QUOT, KC_SLSH,  KC_DOT, TO(BASE),
  //|--------+--------+---------+---------+---------+--------+--------|  |--------+--------+--------+---------+--------+--------+--------|
                                  XXXXXXX,OSM(MOD_LSFT),LCTL_T(KC_ESC),     KC_ENT,  KC_SPC,XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

    [QWERTY] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------.                    ,------------------------------------------------------.
      KC_VOLD,    KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                          KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_VOLU,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
       KC_TAB,    KC_A,     KC_S,     KC_D,     KC_F,    KC_G,                          KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_COLN,
  //|--------+--------+---------+---------+---------+--------|                    |--------+--------+---------+--------+--------+--------|
      CW_TOGG,    KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,                          KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, TO(BASE),
  //|--------+--------+---------+---------+---------+--------+--------|  |--------+--------+--------+---------+--------+--------+--------|
                                  XXXXXXX,OSM(MOD_LSFT),LCTL_T(KC_ESC),      KC_ENT,  KC_SPC,RMAGIC
                                      //`--------------------------'  `--------------------------'
  )
};

// --- MAGIC KEYS & MACROS ---

/**
 * Intercepts keys to determine if they should be tracked by the Repeat Key (QK_REP).
 * Returns 'false' for specific keys so they don't overwrite the last printable character.
 */
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
	switch (keycode) {
		case CW_TOGG:
        case KC_ESC:
        // case KC_BSPC:
        // case KC_DEL:

        case LMAGIC:
        case RMAGIC:
            return false;  // Magic keys will ignore the above keycodes.
    }

    // store the effective mods (held | oneshot | weak/CapsWord)
    *remembered_mods = (get_mods() | get_oneshot_mods() | get_weak_mods());

    return true;  // Other keys can be repeated.
}

// An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// held while sending the string. Additionally, the last key is set such that if
// the Repeat Key is pressed next, it produces `repeat_keycode`.
#define MAGIC_STRING(str, repeat_keycode) \
		magic_send_string_P(PSTR(str), (repeat_keycode))

static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
	uint8_t saved_mods = 0;

  if (is_caps_word_on()) { // If Caps Word is on, save the mods and hold Shift.
    saved_mods = get_mods();
    register_mods(MOD_BIT(KC_LSFT));
  }

  send_string_with_delay_P(str, TAP_CODE_DELAY);  // Send the string.
  set_last_keycode(repeat_keycode); // 2024-03-09 Disabled sending of string for mag-rep / rep-mag consistency.

  // If Caps Word is on, restore the mods.
  if (is_caps_word_on()) {
    set_mods(saved_mods);
  }
}

static inline bool was_shifted(uint8_t mods) { return (mods & MOD_MASK_SHIFT) != 0; }

// Pick between two *literals* based on the remembered mods.
// Keeps MAGIC_STRING (and its PSTR usage) happy.
#define MAGIC_CHOOSE(mods, unshift_lit, shift_lit, repeat_keycode) \
    do { \
        if (was_shifted(mods)) { \
            MAGIC_STRING(shift_lit, repeat_keycode); \
        } else { \
            MAGIC_STRING(unshift_lit, repeat_keycode); \
        } \
    } while (0)

/**
 * Contextual Dictionaries for LMAGIC / RMAGIC.
 * Evaluates the previously pressed key to output adaptive strings/punctuation.
 */
static void process_left_magic(uint16_t keycode, uint8_t mods) { // LMAGIC definitions
    switch (keycode) {
	    case LT_SYM_A: { MAGIC_STRING("o", 		KC_NO); } break;
	    case   LCTL_B: { MAGIC_STRING("b", 		KC_NO); } break;
	    case   HYPR_C: { MAGIC_STRING("c", 		KC_NO); } break;
	    case   LGUI_D: { MAGIC_STRING("d", 		KC_NO); } break;
	    case LT_NAV_E: { MAGIC_STRING("u", 		KC_NO); } break;
	    case     KC_F: { MAGIC_STRING("y", 		KC_NO); } break;
	    case     KC_G: { MAGIC_STRING("g", 		KC_NO); } break;
	    case     KC_H: { MAGIC_STRING("y", 		KC_NO); } break;
	    case     KC_I: { MAGIC_STRING("ng", 	KC_NO); } break;
	    case   LALT_J: { MAGIC_STRING("p", 		KC_NO); } break;
	    case     KC_K: { MAGIC_STRING("p", 		KC_NO); } break;
	    case   LSFT_L: { MAGIC_STRING("l", 		KC_NO); } break;
	    case     KC_M: { MAGIC_STRING("m", 		KC_NO); } break;
	    case  LT_MS_N: { MAGIC_STRING("n", 		KC_NO); } break;
	    case   LGUI_O: { MAGIC_STRING("a", 		KC_NO); } break;
	    case     KC_P: { MAGIC_STRING("k", 		KC_NO); } break;
	    case     KC_Q: { MAGIC_STRING("ue", 	KC_E); } break;
	    case LT_NAV_R: { MAGIC_STRING("r", 		KC_NO); } break;
	    case LT_NUM_S: { MAGIC_STRING("s", 		KC_NO); } break;
	    case LT_SYM_T: { MAGIC_STRING("t", 		KC_NO); } break;
	    case   LSFT_U: { MAGIC_STRING("e", 		KC_NO); } break;
	    case   LALT_V: { MAGIC_STRING("v", 		KC_NO); } break;
	    case     KC_W: { MAGIC_STRING("w", 		KC_NO); } break;
	    case     KC_X: { MAGIC_STRING("x", 		KC_NO); } break;
	    case   HYPR_Y: { MAGIC_STRING("p", 		KC_NO); } break;
	    case     KC_Z: { MAGIC_STRING("z", 		KC_NO); } break;

	    case   KC_DOT: { MAGIC_STRING(" ", 		KC_NO); set_oneshot_mods(MOD_BIT(KC_LSFT)); } break;
	    case  KC_QUES: { MAGIC_STRING(" ", 		KC_NO); set_oneshot_mods(MOD_BIT(KC_LSFT)); } break;
	    case  KC_EXLM: { MAGIC_STRING(" ", 		KC_NO); set_oneshot_mods(MOD_BIT(KC_LSFT)); } break;
	    case   KC_SPC: { MAGIC_STRING("the ", 		KC_NO); } break;

	    case   KC_GRV: { MAGIC_STRING("`", 		KC_NO); tap_code(KC_LEFT); } break;
	    case  KC_LABK: { MAGIC_STRING("<", 		KC_NO); } break;
	    case  KC_RABK: { MAGIC_STRING(">", 		KC_NO); } break;
	    case KC_EQUAL: { MAGIC_STRING("=", 		KC_NO); } break;
	    case  KC_PLUS: { MAGIC_STRING("+", 		KC_NO); } break;
	    case  KC_MINS: { MAGIC_STRING("-", 		KC_NO); } break;
	    case  KC_ASTR: { MAGIC_STRING("*", 		KC_NO); } break;
    }
}

static void process_right_magic(uint16_t keycode, uint8_t mods) { // RMAGIC definitions
    switch (keycode) {
	    case LT_SYM_A: { MAGIC_STRING("a", 		KC_NO); } break;
	    case   LCTL_B: { MAGIC_STRING("n", 		KC_NO); } break;
	    case   HYPR_C: { MAGIC_STRING("s", 		KC_NO); } break;
	    case   LGUI_D: { MAGIC_STRING("m", 		KC_NO); } break;
	    case LT_NAV_E: { MAGIC_STRING("e", 		KC_NO); } break;
	    case     KC_E: { MAGIC_STRING("e", 		KC_NO); } break;
	    case     KC_F: { MAGIC_STRING("f", 		KC_NO); } break;
	    case     KC_G: { MAGIC_STRING("z", 		KC_NO); } break;
	    case     KC_H: { MAGIC_STRING("h", 		KC_NO); } break;
	    case     KC_I: { MAGIC_STRING("i", 		KC_NO); } break;
	    case   LALT_J: { MAGIC_STRING("j", 		KC_NO); } break;
	    case     KC_K: { MAGIC_STRING("k", 		KC_NO); } break;
	    case   LSFT_L: { MAGIC_STRING("r", 		KC_NO); } break;
	    case     KC_M: { MAGIC_STRING("d", 		KC_NO); } break;
	    case  LT_MS_N: { MAGIC_STRING("b", 		KC_NO); } break;
	    case   LGUI_O: { MAGIC_STRING("o", 		KC_NO); } break;
	    case     KC_P: { MAGIC_STRING("p", 		KC_NO); } break;
	    case     KC_Q: { MAGIC_STRING("uen", 	KC_NO); } break;
	    case LT_NAV_R: { MAGIC_STRING("l", 		KC_NO); } break;
	    case LT_NUM_S: { MAGIC_STRING("c", 		KC_NO); } break;
	    case LT_SYM_T: { MAGIC_STRING("m", 		KC_NO); } break;
	    case   LSFT_U: { MAGIC_STRING("u", 		KC_NO); } break;
	    case   LALT_V: { MAGIC_STRING("g", 		KC_NO); } break;
	    case     KC_W: { MAGIC_STRING("s", 		KC_NO); } break;
	    case     KC_X: { MAGIC_STRING("b", 		KC_NO); } break;
	    case   HYPR_Y: { MAGIC_STRING("y", 		KC_NO); } break;
	    case     KC_Z: { MAGIC_STRING("g", 		KC_NO); } break;


	    case   KC_DOT: { MAGIC_STRING(".", 		KC_NO); } break;
	    case LCTL_COMM: { MAGIC_STRING(" but ", KC_NO); } break;

	    case  KC_AMPR: { MAGIC_STRING("&", 		KC_NO); } break;
	    case  KC_PIPE: { MAGIC_STRING("|", 		KC_NO); } break;
	    case  KC_TILD: { MAGIC_STRING("~", 		KC_NO); } break;

	    // case  KC_BSLS: { MAGIC_STRING("n", 		KC_NO); } break;
	    // case  KC_SLSH: { MAGIC_STRING("/", 		KC_NO); } break;
        case KC_SLSH: { MAGIC_CHOOSE(mods, "/", "n", KC_NO); } break;

	    // case  KC_QUOT: { MAGIC_STRING("'", 		KC_NO); tap_code(KC_LEFT); } break;
	    case  KC_QUOT: { MAGIC_CHOOSE(mods, "'", "\"", KC_NO); tap_code(KC_LEFT); } break;
        // case KC_QUOT:
        //     if (was_shifted(mods)) {
        //         MAGIC_STRING("\"", KC_NO);     // last key was "
        //     } else {
        //         MAGIC_STRING("'",  KC_NO);     // last key was '
        //     }
        //     tap_code(KC_LEFT);                 // place cursor between the pair
            // break;

	    case  KC_LPRN: { MAGIC_STRING(")", 		KC_NO); tap_code(KC_LEFT); } break;
	    case  KC_LBRC: { MAGIC_STRING("]", 		KC_NO); tap_code(KC_LEFT); } break;
	    case  KC_LCBR: { MAGIC_STRING("}", 		KC_NO); tap_code(KC_LEFT); } break;

        case KC_BSPC:
            // send a normal Backspace
            tap_code(KC_BSPC);
            // record it so QK_REP will repeat it
            set_last_keycode(KC_BSPC);
            break;

        case C(KC_BSPC):  // Ctrl+Backspace
            // send a Ctrl+Backspace
            tap_code16(C(KC_BSPC));
            // record it for repeat
            set_last_keycode(C(KC_BSPC));
            break;
    }
}

// --- CAPS WORD TRACKING ---

/**
 * Defines which keys prevent Caps Word from automatically turning off.
 */
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

// --- MAIN EVENT LOOP ---

/**
 * Custom OSM State Trackers
 * QMK natively discards One-Shot Modifier tap events while Caps Word is active.
 * We manually intercept Shift events here to allow Shift+Space to safely output
 * an underscore (_) without breaking the One-Shot queue logic.
 */
// Tracks strictly *physical* left shift holds.
static bool is_shift_held = false;
// Manually tracks One-Shot taps specifically because QMK ignores them during Caps Word.
static bool caps_osm_queued = false;
// Tracks if another key was typed while Shift was held down
static bool shift_interrupted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // --- SHIFT STATE TRACKING ---
    // 1. Shift Downstroke
    if ((keycode == KC_LSFT || keycode == OSM(MOD_LSFT)) && record->event.pressed) {
        is_shift_held = true;
        shift_interrupted = false; // Reset the interruption flag
    }
    // 1a. Any other key Downstroke
    else if (record->event.pressed && is_shift_held) {
        shift_interrupted = true; // Flag that Shift was used as a physical hold
    }
    // 2. Shift Upstroke
    if ((keycode == KC_LSFT || keycode == OSM(MOD_LSFT)) && !record->event.pressed) {
        is_shift_held = false;

        // ONLY queue the One-Shot state if it was a pure tap (no other keys pressed)
        if (!shift_interrupted && is_caps_word_on()) {
            caps_osm_queued = true;
        }
    }

    // RALT -> 3 only on GAMING while Shift is held
    if (layer_state_is(GAMING) && (get_mods() | get_oneshot_mods() | get_weak_mods()) & MOD_MASK_SHIFT) {
        if (keycode == KC_RALT) {
            if (record->event.pressed) {
                // Save current mod states
                uint8_t saved_mods     = get_mods();
                uint8_t saved_oneshot  = get_oneshot_mods();
                uint8_t saved_weak     = get_weak_mods();

                // Clear Shift from all three buckets (held, oneshot, weak)
                set_mods(saved_mods & ~MOD_MASK_SHIFT);
                set_oneshot_mods(saved_oneshot & ~MOD_MASK_SHIFT);
                set_weak_mods(saved_weak & ~MOD_MASK_SHIFT);
                send_keyboard_report();

                tap_code(KC_3);  // sends an unshifted '3'

                // Restore previous mod states
                set_mods(saved_mods);
                set_oneshot_mods(saved_oneshot);
                set_weak_mods(saved_weak);
                send_keyboard_report();
            }
            caps_osm_queued = false; // Prevent stale queue leak
            return false;  // swallow the original RAlt
        }
    }

    // --- CAPS WORD + SHIFT BACKSPACE ---
    // Intercepts Shift (Physical hold OR One-Shot tap) + RMAGIC during Caps Word.
    if (record->event.pressed
        && keycode == RMAGIC
        && is_caps_word_on()
        && (is_shift_held || caps_osm_queued || (get_mods() & MOD_MASK_SHIFT)) // Native check for HRM
    ) {
        // Force a Backspace override here:
        tap_code(KC_BSPC);
        set_last_keycode(KC_BSPC);
        // set_last_mods(0);
        caps_osm_queued = false; // Consume custom OSM state
        return false;  // Consume keypress, bypass Key Overrides, don’t fall through to magic-string or key-override
    }

    // --- MAGIC KEYS & OVERRIDE GATEKEEPER ---
    if (record->event.pressed && (keycode == LMAGIC || keycode == RMAGIC)) {
        // GATEKEEPER: If Shift or Ctrl (held or OSM) are active, return true.
        // This hands the keypress back to QMK so the Key Override engine can
        // transform RMAGIC into KC_BSPC or C(KC_BSPC) and properly clear active OSM states.

        // Count held mods (strip weak), but allow One-Shot mods to qualify.
        uint8_t held_mods = get_mods() & ~get_weak_mods();
        uint8_t oneshot   = get_oneshot_mods();
        if ( (held_mods | oneshot) & (MOD_MASK_SHIFT | MOD_MASK_CTRL) ) {
            return true;  // fall through -> process_key_override()
        }

        // Otherwise no modifiers active: consume the keypress and fire the custom magic macros.
        if (keycode == LMAGIC) {
            process_left_magic (get_last_keycode(), get_last_mods());
        } else {
            process_right_magic(get_last_keycode(), get_last_mods());
        }
        caps_osm_queued = false; // Prevent stale queue leak
        return false;
    }

    // --- CAPS WORD + SPACEBAR ---
    if (is_caps_word_on() && keycode==KC_SPC && record->event.pressed) {
        // Send underscore if shift is held OR One-Shot was tapped
        if (is_shift_held || caps_osm_queued || (get_mods() & MOD_MASK_SHIFT)) { // Native check for HRM
            tap_code16(KC_UNDS);
            caps_osm_queued = false; // Consume our custom OSM state
        }
        // Disable caps word if shift isn't held
        else {
            tap_code16(KC_SPC);
            caps_word_off();
        }
        // Do not process further
        return false;
    }
    // Clear the custom OSM queue if any normal key is pressed during Caps Word (garbage collection)
    if (record->event.pressed && caps_osm_queued) {
        if (keycode != KC_LSFT && keycode != OSM(MOD_LSFT)) {
            caps_osm_queued = false;
        }
    }

    switch (keycode) {
        // Sequence-based Shift Leakage Fix
        case KC_EQUAL:
            if (record->event.pressed) {
                uint16_t last_kc = get_last_keycode();
                // Raise shift before clicking = after +!><
                if (last_kc == KC_PLUS || last_kc == KC_EXLM || last_kc == KC_LABK || last_kc == KC_RABK) {
                    del_weak_mods(MOD_MASK_SHIFT);
                    if (get_mods() & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                    send_keyboard_report();
                }
            }
            break;

    // static bool kc_shift = false;
    // switch (keycode) {
    //     // Raise shift before clicking = after +!><
    //     case KC_RABK:
    //     case KC_LABK:
    //     case KC_EXLM:
    //     case KC_PLUS:
    //         kc_shift = record->event.pressed;
    //         break;
    //     case KC_EQUAL:
    //         if (record->event.pressed && kc_shift) {
    //             del_weak_mods(MOD_LSFT);
    //             // del_mods(MOD_LSFT);
    //             send_keyboard_report();
    //         }
    //         break;

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

        // Custom keys
        case TGRV:
            if (record->event.pressed) {
                // open the code fence
                SEND_STRING("```");
                // two "soft" line-breaks (Shift+Enter twice)
                tap_code16(S(KC_ENTER));
                tap_code16(S(KC_ENTER));
                // close the code fence
                SEND_STRING("```");
                // jump back up into the empty line
                tap_code(KC_UP);
            }
            return false;
        case DDSLASH:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        default:
            break;
    }

    // Process Other Keycodes Normally
    return true;
}
