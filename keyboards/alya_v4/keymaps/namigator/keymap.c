/* Copyright 2021 Martin Errenst
 * modified by gator
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

#include "keymap_german.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _M3,
    _M4,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    MOVE_LED_LEFT,
    MOVE_LED_RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,   DE_0,     DE_1,    DE_2,    DE_3,    DE_4,     DE_5,
        KC_TAB,   DE_Q,     DE_J,    DE_D,    DE_U,    DE_A,     DE_X,
        KC_ESC,             DE_C,    DE_T,    DE_I,    DE_E,     DE_O,
        KC_LSFT,  DE_F,     DE_V,    DE_UDIA, DE_ADIA, DE_ODIA,  KC_BACKSPACE,
        KC_LCTL,  MO(_FN),  KC_LWIN, KC_LALT, MO(_M4), KC_LSFT,  KC_LCTL,

        DE_6,     DE_7,     DE_8,    DE_9,    DE_0,    DE_CIRC,  KC_PGUP,
        DE_P,     DE_H,     DE_L,    DE_M,    DE_W,    DE_SS,    KC_PGDN,
        DE_B,     DE_N,     DE_R,    DE_S,    DE_G,              MO(_M4),
                  DE_Y,     DE_Z,    DE_COMM, DE_DOT,  DE_K,     KC_RSFT,
        KC_ENTER, KC_SPACE, MO(_M3), KC_LALT, KC_RWIN, MO(_FN),  KC_RCTL
    ),
    [_M3] = LAYOUT(
        KC_ESC,   KC_GRV,   DE_DEG,       DE_SECT,    KC_NO,    KC_NO,     KC_NO,
        KC_TAB,   DE_AT,    RALT(DE_DOT), DE_UNDS,    DE_LBRC,  DE_RBRC,   DE_CIRC,
        KC_ESC,             DE_BSLS,      DE_SLSH,    DE_LCBR,  DE_RCBR,   DE_ASTR,
        KC_LSFT,  DE_HASH,  DE_DLR,       DE_PIPE,    DE_TILD,  DE_GRV,    KC_BACKSPACE,
        KC_LCTL,  MO(_FN),  KC_LWIN,      KC_LALT,    MO(_M4),  KC_LSFT,   KC_LCTL,

        DE_DLR,   DE_EURO,  KC_NO,   KC_NO,   KC_NO,     KC_GRV,   KC_PGUP,
        DE_EXLM,  DE_LABK,  DE_RABK, DE_EQL,  DE_AMPR,   KC_NO,    KC_PGDN,
        DE_QUES,  DE_LPRN,  DE_RPRN, DE_MINS, DE_COLN,             MO(_M4),
                  DE_PLUS,  DE_PERC, DE_DQUO, DE_QUOT,   DE_SCLN,  KC_RSFT,
        KC_ENTER, KC_SPACE, MO(_M3), KC_LALT, KC_RWIN,   MO(_FN),  KC_RCTL
    ),
    [_M4] = LAYOUT(
        KC_ESC,   KC_VOLD,  KC_MUTE, KC_VOLU, KC_MPRV,  KC_MPLY,   KC_MNXT,
        KC_TAB,   KC_NO,    KC_PGUP, KC_BSPC, KC_UP,    KC_DEL,    KC_PGDN,
        MO(_M3),            KC_HOME, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_END,
        KC_LSFT,  KC_ESC,   KC_TAB,  KC_INS,  KC_RETURN,KC_NO,     KC_BACKSPACE,
        KC_LCTL,  MO(_FN),  KC_LWIN, KC_LALT, MO(_M4),  KC_LSFT,   KC_LCTL,

        KC_NO,  KC_TAB,   KC_PSLS, KC_PAST, KC_BRID, KC_BRIU, KC_HOME,
        KC_NO,  KC_P7,    KC_P8,   KC_P9,   KC_PMNS, KC_NO,   KC_END,
        KC_NUM, KC_P4,    KC_P5,   KC_P6,   KC_PPLS,          MO(_M4),
                DE_COLN,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_RSFT,
        KC_P0,  KC_SPACE, MO(_M3), KC_LALT, KC_RWIN, MO(_FN), KC_RCTL
    ),
    [_FN] = LAYOUT(
        KC_PSCR,  KC_F10,   KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,
        KC_SCRL,  DE_SS,    DE_W,    DE_M,     DE_L,    DE_H,     DE_P,
        KC_ESC,             DE_G,    DE_S,     DE_R,    DE_N,     DE_B,
        KC_LSFT,  DE_K,     DE_DOT,  DE_COMM,  DE_Z,    DE_Y,     KC_PAUSE,
        KC_LCTL,  MO(_FN),  KC_APP,  KC_LALT,  MO(_M4), KC_LSFT,  KC_LCTL,

        KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,
        DE_X,     DE_A,     DE_U,    DE_D,    DE_J,   DE_Q,    QK_BOOT,
        DE_O,     DE_E,     DE_I,    DE_T,    DE_C,            MO(_M4),
                  DE_ODIA,  DE_ADIA, DE_UDIA, DE_V,   DE_F,    KC_RSFT,
        KC_ENTER, KC_SPACE, MO(_M3), KC_LALT, KC_APP, MO(_FN), KC_RCTL
    )
};

void pulse_backlight_clk(void);
void pulse_backlight_clk(void){
        writePinLow(BACKLIGHT_DATA_CLOCK);
        writePinHigh(BACKLIGHT_DATA_CLOCK);
}

void move_led(int8_t dir);
void move_led(int8_t dir){
        static uint8_t pos = 0;
        pos = (pos + dir) % 16;

        for(size_t i = 0; i < 8; i++){
                if(i == pos){
                        writePinHigh(BACKLIGHT_DATA_PIN);
                } else {
                        writePinLow(BACKLIGHT_DATA_PIN);
                }
                pulse_backlight_clk();
        }
        for(size_t i = 15; i >= 8; i--){
                if(i == pos){
                        writePinHigh(BACKLIGHT_DATA_PIN);
                } else {
                        writePinLow(BACKLIGHT_DATA_PIN);
                }
                pulse_backlight_clk();
        }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //print("process_record_user()\n");
    switch (keycode) {
        case MOVE_LED_LEFT:
                move_led(-1);
                break;
        case MOVE_LED_RIGHT:
                move_led(1);
                break;
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
