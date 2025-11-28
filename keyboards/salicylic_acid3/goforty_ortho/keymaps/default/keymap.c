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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_L,    KC_U,    KC_SCLN, KC_T,    KC_LCBR,    KC_F,    KC_W,    KC_R,    KC_Y,    KC_P,  KC_BSPC,
        KC_LCTL, KC_E,    KC_I,    KC_A,    KC_O,    KC_COMM, KC_SCLN,    KC_K,    KC_T,    KC_N,    KC_S,    KC_H,  KC_BSPC,
        LSFT_T(KC_ESC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_DOT,  KC_MINS,    KC_G,    KC_D,    KC_M,    KC_J,    KC_B,  _______,
        _______, _______, KC_LALT, KC_GUI,   _______, LT(3, KC_SPC),LSFT_T(KC_ENT),_______, _______, _______, _______, _______
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LCBR,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_SCLN,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MINS,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP,   MO(1),
        KC_LCTL, KC_LGUI, KC_LALT,KC_LNG1,    KC_SPC,    KC_SPC,     KC_SPC,    KC_SPC, KC_LNG2, KC_LEFT, KC_DOWN, KC_RGHT
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

enum custom_keycodes {
    USER_0 = SAFE_RANGE, 
    USER_1,
    USER_2,
    USER_3,
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
