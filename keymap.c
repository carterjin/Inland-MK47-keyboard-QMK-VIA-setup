/* Copyright 2020 tominabox1
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
 *
 * This keyboard/user is
 * kprepublic/bm40hsrgb:carterjin
 * To compile: Open QMK MSYS and run: qmk compile
 * To flash to keyboard: open qmk toolbox, press RESET,
 * use C:\Users\Haoming\qmk_firmware\kprepublic_bm40hsrgb_carterjin.hex
 * MCU is atmega32u4
 */
#include QMK_KEYBOARD_H
//Define the macro used in layer 4
enum custom_keycodes {
    MCCROP = SAFE_RANGE,
    MCMASTER,
    MCPSCR,
    MCPASTE,
    MCCRPTMS,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MCCROP:
        if (record->event.pressed) {
            // when keycode MCCROP is pressed
            send_string(SS_LALT(SS_DELAY(100)"jp")"vc");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case MCMASTER:
        if (record->event.pressed) {
            // when keycode MCMASTER is pressed
            send_string(SS_LALT("x")"ya");
        } 
        break;
    case MCPSCR:
        if (record->event.pressed) {
           send_string(SS_LALT(SS_DELAY(100) SS_TAP(X_PSCR))); // selects all and copies
        }
        break;
    case MCPASTE:
        if (record->event.pressed) {
           send_string(SS_LCTL("v")); // selects all and copies
        }
        break;
    case MCCRPTMS:
        if (record->event.pressed) {
           send_string(SS_LALT("x")"yc"); // selects all and copies
        }
        break;
    }
    return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctr(Esc)|WIN | PSCR | Alt  | TO(3)|    Space    |MO(2) |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [0] = LAYOUT_planck_mit(
    KC_TAB, KC_Q,  KC_W,   KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_BSPC,
    KC_CAPS, KC_A, KC_S,   KC_D,  KC_F, KC_G,   KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN,KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT,
LCTL_T(KC_ESC), KC_LGUI, KC_PSCR, KC_LALT, TO(3), LT(1,KC_SPC), MO(2), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT),
/* Layer 1
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  1!  |  2@  |  3#  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |      |      |      |      |      | Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | PSCR | Alt  |      |    Space    |      |      |      | Vol- |      |
 * `-----------------------------------------------------------------------------------'
 */
    [1] = LAYOUT_planck_mit(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX,
    KC_LCTL, KC_LGUI, KC_PSCR, KC_LALT, XXXXXXX, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX),
/* Layer 2
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  1!  |  2@  |  3#  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | INS  | DEL  | HOME | Vol+ | END  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | PSCR | Alt  | TO(0)|    Space    | TO(0)|   /  | PGUP | Vol- | PGDN |
 * `-----------------------------------------------------------------------------------'
 */
    [2] = LAYOUT_planck_mit(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL, KC_HOME, KC_VOLU, KC_PGUP,
    KC_LCTL, KC_LGUI, KC_PSCR, KC_LALT, TO(0), LT(1,KC_SPC), TO(0), KC_SLSH, KC_END, KC_VOLD, KC_PGDN),
/* Layer 3
 * ,-----------------------------------------------------------------------------------.
 * |  TAB | NLOCK|  7   |  8   |  9   |  -   |  /   |RESET |DEBUG |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |      |  4   |  5   |  6   |  +   |  *   | RGB  |RGBMOD|      |TO(5) |TO(4) |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |  1   |  2   |  3   |Enter |      |      |      |      |  Up  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |  0   |  .   | TO(1)|   Space     | TO(0)|      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */ 
    [3] = LAYOUT_planck_mit(
    KC_TAB, KC_NUM, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PSLS, QK_BOOT, DB_TOGG, KC_NO, KC_NO, KC_BSPC,
    KC_DEL, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST, RGB_TOG, RGB_MOD, KC_NO, TO(5), TO(4),
    KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_ENT,
    KC_LCTL, KC_NO, KC_P0, KC_PDOT, TO(2), KC_SPC, TO(0), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),

 /* Layer 4
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  1   |  2   |  3   |  4   |  5   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  F7  |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  B   |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   | Vol+ | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Z   |  X   |Alt(C)|  V   |   Space     | TO(0)|  M   | Left | Vol- |Right |
 * `-----------------------------------------------------------------------------------'
 */ 
    [4] = LAYOUT_planck_mit(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
    KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_F7,
    KC_B, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_VOLU, KC_ENT, 
    KC_LCTL, KC_Z, KC_X, LALT_T(KC_C), KC_V, KC_SPC, TO(0), KC_M, KC_LEFT, KC_VOLD, KC_RGHT),

/* Layer 4
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CROP |MASTER| PRSR |PASTE |CRPTMS|   G  |MCRC1 |MCRC2 |MCPLY1|MCPLY2|   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  Z   |  X   |  C   |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctr(Esc)|WIN | PSCR | Alt  |      |    Space    |TO(0) |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [5] = LAYOUT_planck_mit(
    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    MCCROP, MCMASTER, MCPSCR, MCPASTE,MCCRPTMS, KC_G,   DM_REC1,  DM_REC2,   DM_PLY1,  DM_PLY2, KC_SCLN,KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT,
    LCTL_T(KC_ESC), KC_LGUI, KC_PSCR, KC_LALT, KC_NO, LT(1, KC_SPC), TO(0), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT)
};

// void set_color(int r, int g, int b){
//     rgb_matrix_set_color(5,  r, g, b);
//     rgb_matrix_set_color(6,  r, g, b);
//     rgb_matrix_set_color(17, r, g, b);
//     rgb_matrix_set_color(18, r, g, b);
//     rgb_matrix_set_color(29, r, g, b);
//     rgb_matrix_set_color(30, r, g, b);
//     rgb_matrix_set_color(41, r, g, b);
//     rgb_matrix_set_color(34, r, g, b);
//     rgb_matrix_set_color(44, r, g, b);
//     rgb_matrix_set_color(45, r, g, b);
//     rgb_matrix_set_color(46, r, g, b);
//     rgb_matrix_set_color(47, r, g, b);
// }

bool rgb_matrix_indicators_user(void) {

    switch (get_highest_layer(layer_state)) {
        case 1:
            rgb_matrix_set_color_all(50, 50, 0);
            break;
        case 2:
            rgb_matrix_set_color_all(50, 0, 0);
            break;
        case 3:
            rgb_matrix_set_color_all(0, 40, 50);
            break;
        case 4:
            rgb_matrix_set_color_all(0, 0, 50);
            break;
        case 5:
            rgb_matrix_set_color_all(0, 50, 0);
            break;
    }
    //capslock leds
    if (host_keyboard_led_state().caps_lock) {
    rgb_matrix_set_color_all(50, 15.6, 0);
  }
    return true;
}