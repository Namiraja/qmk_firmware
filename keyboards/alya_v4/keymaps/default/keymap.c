/* Copyright 2021 Martin Errenst
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

// overrides for M2 layer (so we get the shift key send "standalone" if only ):
// example:
// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// result: shift + backspace = del
const key_override_t de_1_override = ko_make_basic(MOD_MASK_SHIFT, DE_1, DE_DEG);
const key_override_t de_2_override = ko_make_basic(MOD_MASK_SHIFT, DE_2, DE_SECT);
const key_override_t de_6_override = ko_make_basic(MOD_MASK_SHIFT, DE_6, DE_DLR);
const key_override_t de_ques_override = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_QUES);

const key_override_t **key_overrides = (const key_override_t *[]){
    &de_1_override,
    &de_2_override,
    &de_6_override,
    &de_ques_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_ESC,   DE_1,    DE_2,    DE_3,    DE_4,     DE_5,
        KC_TAB,   KC_TAB,   DE_J,    DE_D,    DE_U,    DE_A,     DE_X,
        MO(_M3),            DE_C,    DE_T,    DE_I,    DE_E,     DE_O,
        KC_LSFT,  DE_F,     DE_V,    DE_UDIA, DE_ADIA, DE_ODIA,  KC_BACKSPACE,
        KC_LCTL,  KC_LWIN,  MO(_FN), MO(_M4), KC_LALT, KC_SPACE, KC_SPACE,

        DE_6,     DE_7,     DE_8,    DE_9,    DE_0,    DE_SS,    KC_PAGE_UP,
        DE_P,     DE_H,     DE_L,    DE_M,    DE_W,    DE_Q,     KC_PAGE_DOWN,
        DE_B,     DE_N,     DE_R,    DE_S,    DE_G,              MO(_M3),
                  DE_Y,     DE_Z,    DE_COMM, DE_DOT,  DE_K,     KC_RSFT,
        KC_ENTER, KC_ENTER, MO(_M4), MO(_FN), KC_MENU, KC_RALT,  KC_RCTL
    ),
    [_M3] = LAYOUT(
        KC_ESC,   KC_ESC,   KC_NO,   KC_NO,      KC_NO,    KC_NO,     KC_NO,
        KC_TAB,   KC_TAB,   KC_NO,   DE_UNDS,    DE_LBRC,  DE_RBRC,   DE_CIRC,
        MO(_M3),            DE_BSLS, DE_SLSH,    DE_LCBR,  DE_RCBR,   DE_ASTR,
        KC_LSFT,  DE_HASH,  DE_DLR,  DE_PIPE,    DE_TILD,  DE_GRV,    KC_BACKSPACE,
        KC_LCTL,  KC_LWIN,  MO(_FN), MO(_M4),    KC_LALT,  KC_SPACE,  KC_SPACE,

        KC_NO,    KC_NO,    KC_NO,   KC_NO,      KC_NO,     DE_AT,    KC_PAGE_UP,
        DE_EXLM,  DE_LABK,  DE_RABK, DE_EQL,     DE_AMPR,   KC_NO,    KC_PAGE_DOWN,
        DE_QUES,  DE_LPRN,  DE_RPRN, DE_MINS,    DE_COLN,             MO(_M3),
                  DE_PLUS,  DE_PERC, DE_DQUO,    DE_QUOT,   DE_SCLN,  KC_RSFT,
        KC_ENTER, KC_ENTER, MO(_M4), MO(_FN),    KC_MENU,   KC_RALT,  KC_RCTL
    ),
    [_M4] = LAYOUT(
        KC_ESC,   KC_ESC,   KC_NO,   KC_NO,      KC_NO,    KC_NO,     KC_NO,
        KC_TAB,   KC_TAB,   KC_PGUP, KC_BSPC,    KC_UP,    KC_DEL,    KC_PGDN,
        MO(_M3),            KC_HOME, KC_LEFT,    KC_DOWN,  KC_RIGHT,  KC_END,
        KC_LSFT,  KC_ESC,   KC_TAB,  KC_INS,     KC_RETURN,KC_NO,     KC_BACKSPACE,
        KC_LCTL,  KC_LWIN,  MO(_FN), MO(_M4),    KC_LALT,  KC_SPACE,  KC_SPACE,

        KC_NO,    KC_NO,    KC_NO,   KC_KP_SLASH,KC_KP_ASTERISK,KC_NO,       KC_PAGE_UP,
        KC_NO,    KC_KP_7,  KC_KP_8, KC_KP_9,    KC_KP_PLUS,    KC_KP_MINUS, KC_PAGE_DOWN,
        KC_NO,    KC_KP_4,  KC_KP_5, KC_KP_6,    KC_COMM,                    MO(_M3),
                  DE_COLN,  KC_KP_1, KC_KP_2,    KC_KP_3,       DE_SCLN,     KC_RSFT,
        KC_ENTER, KC_ENTER, MO(_M4), MO(_FN),    KC_MENU,       KC_RALT,     KC_RCTL
    ),
    [_FN] = LAYOUT(
        KC_ESC,   KC_ESC,   KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,
        KC_TAB,   KC_TAB,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,
        MO(_M3),            KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,
        KC_LSFT,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_BACKSPACE,
        KC_LCTL,  KC_LWIN,  MO(_FN), MO(_M4),  KC_LALT, KC_SPACE, KC_SPACE,

        KC_F6,    KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        KC_NO,    KC_KP_7,  KC_KP_8, KC_KP_9,  KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_KP_4,  KC_KP_5, KC_KP_6,  KC_NO,            MO(_M3),
                  DE_COLN,  KC_KP_1, KC_KP_2,  KC_NO,   QK_BOOTLOADER,   KC_RSFT,
        KC_ENTER, KC_ENTER, MO(_M4), MO(_FN),  KC_MENU, KC_RALT, KC_RCTL
    )
   // [_FN] = LAYOUT(
   //     QMKBEST, QMKURL,  _______,
   //         RESET,    XXXXXXX
   // )
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
