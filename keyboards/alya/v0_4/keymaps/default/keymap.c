/* Copyright 2026 Martin Errenst, Namigator
 *
 * (SPDX-License-Identifier: GPL-2.0-or-later)
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

/* SF_SPC = Left Shift when held, Space when tapped
 * CTL_ENT = Left Control when held, Enter when tapped
 */
#define SFT_SPC LSFT_T(KC_SPACE)
#define SFT_ENT LSFT_T(KC_ENTER)
#define CTL_SPC LCTL_T(KC_SPACE)
#define CTL_ENT LCTL_T(KC_ENTER)
#define DE_DOTS RALT(DE_DOT)

enum layer_names {
  BONE,
  WASD,
  MOD3,
  MOD4,
  FN
};

  /*
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │   │   │   │   │   │ █ │   │   │   │   │   │     │
   * ├────┬┴──┬┴──┬┴──┬┴──┬┴──┬┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
   * │    │   │   │   │   │   │     │   │   │   │   │   │    │
   * ├───┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │Esc│ ^ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ` │Pup│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │Tab│ q │ j │ d │ u │ a │ x │ p │ h │ l │ m │ w │ ß │Pdn│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │ M3  │ c │ t │ i │ e │ o │ █ │ b │ n │ r │ s │ g │  M3 │
   * ├────┬┴──┬┴──┬┴──┬┴──┬┴──┬┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
   * │Sft │ f │ v │ ü │ ä │ ö │Bkspc│ y │ z │ , │ . │ k │ Sft│
   * ├───┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
   * │Ctl│Fn │Win│Alt│M4 │SSc│CEn│Ent│Spc│ M4│Alt│Win│ Fn│Ctl│
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [BONE] = LAYOUT(
    KC_ESC,   DE_CIRC,  DE_1,     DE_2,     DE_3,     DE_4,     DE_5,         DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_GRV,   KC_PGUP,
    KC_TAB,   DE_Q,     DE_J,     DE_D,     DE_U,     DE_A,     DE_X,         DE_P,     DE_H,     DE_L,     DE_M,     DE_W,     DE_SS,    KC_PGDN,
    MO(MOD3),           DE_C,     DE_T,     DE_I,     DE_E,     DE_O,         DE_B,     DE_N,     DE_R,     DE_S,     DE_G,               MO(MOD3),
    KC_LSFT,  DE_F,     DE_V,     DE_UDIA,  DE_ADIA,  DE_ODIA,      KC_BSPC,  DE_Y,     DE_Z,     DE_COMM,  DE_DOT,   DE_K,               KC_RSFT,
    KC_LCTL,  MO(FN),   KC_LWIN,  KC_LALT,  MO(MOD4), SFT_SPC,  CTL_ENT,      KC_ENTER, KC_SPACE, MO(MOD4), KC_LALT,  KC_RWIN,  MO(FN),   KC_RCTL
    ),
  /*
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │ ß │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │ ä │ q │ w │ e │ r │ t │ z │ u │ i │ o │ p │ ü │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │ a │ s │ d │ f │ g │ █ │ h │ j │ k │ l │ ö │     │
   * ├────┬┴──┬┴──┬┴──┬┴──┬┴──┬┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
   * │    │ y │ x │ c │ v │ b │     │ n │ m │   │   │ - │    │
   * ├───┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [WASD] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  DE_SS,    _______,
    _______,  DE_ADIA,  DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,         DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     DE_UDIA,  _______,
    _______,            DE_A,     DE_S,     DE_D,     DE_F,     DE_G,         DE_H,     DE_J,     DE_K,     DE_L,     DE_ODIA,            _______,
    _______,  DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,         _______,  DE_N,     DE_M,     _______,  _______,  DE_MINS,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
 /*
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  * │ ^ │ ° │ § │XXX│XXX│XXX│ $ │ € │XXX│XXX│XXX│XXX│XXX│Hme│
  * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
  * │   │ @ │ … │ _ │ [ │ ] │ ^ │ ! │ < │ > │ = │ & │XXX│End│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
  * │     │ \ │ / │ { │ } │ * │ █ │ ? │ ( │ ) │ - │ : │     │
  * ├────┬┴──┬┴──┬┴──┬┴──┬┴──┬┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
  * │    │ # │ $ │ | │ ~ │ ` │     │ + │ % │ " │ ' │ ; │    │
  * ├───┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
  * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
  * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
  */
  [MOD3] = LAYOUT(
    KC_GRV,   DE_DEG,   DE_SECT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DE_DLR,       DE_EURO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,
    _______,  DE_AT,    DE_DOTS,  DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,      DE_EXLM,  DE_LABK,  DE_RABK,  DE_EQL,   DE_AMPR,  XXXXXXX,  KC_END,
    _______,            DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,      DE_QUES,  DE_LPRN,  DE_RPRN,  DE_MINS,  DE_COLN,            _______,
    _______,  DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,       _______,  DE_PLUS,  DE_PERC,  DE_DQUO,  DE_QUOT,  DE_SCLN,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
  /*
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │XXX│XXX│ ² │ ³ │XXX│XXX│XXX│Tab│ / │ * │XXX│XXX│   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │XXX│Pup│Bsp│ ↑ │Del│Pdn│XXX│ 7 │ 8 │ 9 │ + │ - │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │Hme│ ← │ ↓ │ → │End│ █ │ µ │ 4 │ 5 │ 6 │ , │     │
   * ├────┬┴──┬┴──┬┴──┬┴──┬┴──┬┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
   * │    │Esc│Tab│Ins│Ent│Und│     │ : │ 1 │ 2 │ 3 │ . │    │
   * ├───┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
   * │   │   │   │   │   │   │   │   │ 0 │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [MOD4] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  DE_SUP2,  DE_SUP3,  XXXXXXX,  XXXXXXX,      XXXXXXX,  KC_TAB,   KC_PSLS,  KC_PAST,  XXXXXXX,  XXXXXXX,  _______,
    _______,  XXXXXXX,  KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   KC_PGDN,      XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_PMNS,  _______,
    _______,            KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,       DE_MICR,  KC_P4,    KC_P5,    KC_P6,    KC_PDOT,            _______,
    _______,  KC_ESC,   KC_TAB,   KC_INS,   KC_ENTER, KC_UNDO,      _______,  DE_COLN,  KC_P1,    KC_P2,    KC_P3,    KC_PCMM,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  KC_P0,    _______,  _______,  _______,  _______,  _______
    ),
  /*
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │QBT│XXX│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │Vl-│Mte│Vl+│   │   │Nlk│   │   │Psc│Slk│Pau│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │ Esc │   │Mpv│Mpl│Mnx│   │ █ │   │   │   │   │   │     │
   * ├────┬┴──┬┴──┬┴──┬┴──┬┴──┬┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
   * │    │   │Br-│   │Br+│   │     │   │WSD│   │   │   │    │
   * ├───┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
   * │   │   │Mnu│   │   │   │   │   │   │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [FN] = LAYOUT(
    QK_BOOT,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    _______,  _______,  _______,  KC_VOLD,  KC_MUTE,  KC_VOLU,  _______,      _______,  KC_NUM,   _______,  _______,  KC_PSCR,  KC_SCRL,  KC_PAUS,
    KC_ESC,             _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,      _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  KC_BRID,  _______,  KC_BRIU,      _______,  _______,  TG(WASD), _______,  _______,  _______,  _______,
    _______,  _______,  KC_APP,   _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______
    )
};
