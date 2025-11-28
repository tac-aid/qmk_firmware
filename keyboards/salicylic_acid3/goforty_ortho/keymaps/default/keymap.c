/*
Copyright 2025 Salicylic_Acid

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

enum custom_keycodes {
    USER_0 = SAFE_RANGE, 
    USER_1,
    USER_2,
    USER_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB,         KC_Q,  KC_L,    KC_U,    KC_SCLN, LSFT(KC_SCLN), KC_NO, KC_F, KC_W, KC_R, KC_Y, KC_P, KC_BSPC,
        KC_LCTL,        KC_E,  KC_I,    KC_A,    KC_O,    KC_COMM,       KC_NO, KC_K, KC_T, KC_N, KC_S, KC_H, KC_BSPC,
        LSFT_T(KC_ESC), KC_Z,  KC_X,    KC_C,    KC_V,    KC_DOT,        KC_NO, KC_G, KC_D, KC_M, KC_J, KC_B, KC_NO,
        KC_NO,          KC_NO, KC_LALT, KC_LGUI, USER_2,LT(3, KC_SPC),LSFT_T(KC_ENT),USER_3, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [1] = LAYOUT(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, LSFT(KC_SCLN), KC_1, KC_2, KC_3, KC_NO, KC_NO, 
        KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, KC_DOT, KC_4, KC_5, KC_6, KC_NO, KC_NO,
        KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, LALT(KC_F7), KC_NO, KC_SLASH, KC_7, KC_8, KC_9, KC_0, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   USER_3,    KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, KC_DOT, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, LSFT(KC_TAB), USER_1, KC_NO, KC_NO, KC_NO, LALT(KC_LEFT), KC_UP, LALT(KC_RIGHT), KC_NO, KC_NO, 
        KC_NO, KC_NO, LALT(KC_S), LSFT(KC_TAB), USER_0, KC_NO, KC_NO, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, LCTRL(KC_LEFT), LCTRL(KC_LEFT),
        KC_NO, KC_NO, LALT(KC_X), LALT(KC_C), KC_NO, KC_NO, KC_NO, KC_PGDN, LGUI(KC_LEFT), KC_NO, LGUI(KC_RIGHT), LCTRL(KC_LEFT), KC_F11,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_LSFT,    KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [4] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_NO,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_NO,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_NO,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_NO,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_NO,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_LALT,KC_LGUI,    KC_LNG1,    KC_SPC,     KC_ENT,    KC_LNG2, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [6] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    )
};

static bool alt_tab_active = false;
static bool ctrl_tab_active = false;
static bool user2_active = false;
static bool user3_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case USER_0:
      if (record->event.pressed) {
        if (ctrl_tab_active) {
          ctrl_tab_active = false;
          unregister_code(KC_LCTL);
        }
        if (alt_tab_active) {
          tap_code(KC_TAB);
        } else {
          alt_tab_active = true;
          register_code(KC_LALT);
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_1:
      if (record->event.pressed) {
        if (alt_tab_active) {
          alt_tab_active = false;
          unregister_code(KC_LALT);
        }
        if (ctrl_tab_active) {
          tap_code(KC_TAB);
        } else {
          ctrl_tab_active = true;
          register_code(KC_LCTL);
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_2:
      if (record->event.pressed) {
        user2_active = true;
        if (user3_active) {
          layer_off(2);
          register_code(KC_LSFT);
        } else {
          layer_on(1);
        }
      } else {
        user2_active = false;
        if (user3_active) {
          unregister_code(KC_LSFT);
          layer_on(2);
        } else {
          layer_off(1);
        }
      }
      return false;
    case USER_3:
      if (record->event.pressed) {
        user3_active = true;
        if (user2_active) {
          layer_off(1);
          register_code(KC_LSFT);
        } else {
          layer_on(2);
        }
      } else {
        user3_active = false;
        if (user2_active) {
          layer_on(1);
          unregister_code(KC_LSFT);
        } else {
          layer_off(2);
        }
      }
      return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) != 4) {
      if (alt_tab_active) {
        unregister_code(KC_LALT);
        alt_tab_active = false;
      }
      if (ctrl_tab_active) {
        unregister_code(KC_LCTL);
        ctrl_tab_active = false;
      }
    }
    return state;
}
