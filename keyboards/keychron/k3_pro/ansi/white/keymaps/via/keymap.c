/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H

static bool x_pressed = false;
static bool c_pressed = false;
static bool v_pressed = false;
static bool b_pressed = false;

static int lay0 = 0;
static int lay1 = 0;
static int lay2 = 0;
static int lay3 = 0;

static bool wkeep = false;
static bool akeep = false;
static bool skeep = false;
static bool dkeep = false;
/*
enum custom_keycodes {
    USER00 = SAFE_RANGE,
     USER01,USER02,USER03
};
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
     
/*
judge layer command
 */
     case KC_X:
        if (record->event.pressed) {
            x_pressed = true;
        } else {
            x_pressed = false;
               lay0 = 0;
               lay1 = 0;
               lay2 = 0;
               lay3 = 0;
        }
        break;
     
     case KC_C:
        if (record->event.pressed) {
            c_pressed = true;
        } else {
            c_pressed = false;
               lay0 = 0;
               lay1 = 0;
               lay2 = 0;
               lay3 = 0;
        }
        break;

     case KC_V:
        if (record->event.pressed) {
            v_pressed = true;
        } else {
            v_pressed = false;
               lay0 = 0;
               lay1 = 0;
               lay2 = 0;
               lay3 = 0;
        }
        break;

     case KC_B:
        if (record->event.pressed) {
            b_pressed = true;
        } else {
            b_pressed = false;
               lay0 = 0;
               lay1 = 0;
               lay2 = 0;
               lay3 = 0;
        }
        break;

/*
switch layer command
 */
     case KC_1:
          if (record->event.pressed) {
               if (x_pressed && c_pressed && v_pressed && b_pressed) {
                    lay0 ++;
                    if (lay0 == 5) {
                         set_single_persistent_default_layer(0);
                    }
               }
          }
          return true;
          break;
          
     case KC_2:
          if (record->event.pressed) {
               if (x_pressed && c_pressed && v_pressed && b_pressed) {
                    lay1 ++;
                    if (lay1 == 5) {
                         set_single_persistent_default_layer(1);
                    }
               }
          }
          return true;
          break;

     case KC_3:
          if (record->event.pressed) {
               if (x_pressed && c_pressed && v_pressed && b_pressed) {
                    lay2 ++;
                    if (lay2 == 5) {
                         set_single_persistent_default_layer(2);
                    }
               }
          }
          return true;
          break;

     case KC_4:
          if (record->event.pressed) {
               if (x_pressed && c_pressed && v_pressed && b_pressed) {
                    lay3 ++;
                    if (lay3 == 5) {
                         set_single_persistent_default_layer(3);
                    }
               }
          }
          return true;
          break;

/*
judge killswitch

     case QK_KB_0:
        if (record->event.pressed) {
            wkeep = true;
        } else {
            wkeep = false;
        }
        break;

     case QK_KB_1:
        if (record->event.pressed) {
            akeep = true;
        } else {
               akeep = false;
        }
        break;

     case QK_KB_2:
        if (record->event.pressed) {
            skeep = true;
        } else {
            skeep = false;
        }
        break;

     case QK_KB_3:
        if (record->event.pressed) {
            dkeep = true;
        } else {
            dkeep = false;
        }
        break;
 */

/*
aka killswitch
 */

    case QK_KB_0:
        if (record->event.pressed) {
               wkeep = true;
               unregister_code(KC_S);
            register_code(KC_W);
        } else {
               wkeep = false;
            unregister_code(KC_W);
               if (skeep) {
                    register_code(KC_S);
               }
        }
        break;

    case QK_KB_1:
        if (record->event.pressed) {
               akeep = true;
               unregister_code(KC_D);
            register_code(KC_A);
        } else {
               akeep = false;
            unregister_code(KC_A);
               if (dkeep) {
                    register_code(KC_D);
               }
        }
        break;

    case QK_KB_2:
        if (record->event.pressed) {
               skeep = true;
               unregister_code(KC_W);
            register_code(KC_S);
        } else {
               skeep = false;
            unregister_code(KC_S);
               if (wkeep) {
                    register_code(KC_W);
               }
        }
        break;

    case QK_KB_3:
        if (record->event.pressed) {
               dkeep = true;
               unregister_code(KC_A);
            register_code(KC_D);
        } else {
               dkeep = false;
            unregister_code(KC_D);
               if (akeep) {
                    register_code(KC_A);
               }
        }
        break;


    }
    return true;
};


// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_DEL,   BL_STEP,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  BL_TOGG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     BL_TOGG,  BL_STEP,  BL_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  BL_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   BL_STEP,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     QK_KB_0,  KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KQ_KB_1,  QK_KB_2,  QK_KB_3,  KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  BL_TOGG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     BL_TOGG,  BL_STEP,  BL_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  BL_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};
