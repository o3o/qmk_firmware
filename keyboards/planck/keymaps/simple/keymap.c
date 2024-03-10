/* Copyright 2015-2021 Jack Humbert
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
 * Versione pulita di o3onvim del ottobre 2021, attualmente la versione default
 */
#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _VIM
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE, // SAFE_RANGE e' una macro che ritorna un codice univoco
  VIM_COPY, // associato a y -> "+y
  VIM_PASTE //  associato a p -> "+p
};


#define LOWER MO(_LOWER) //Momentarily turn on layer when pressed (requires KC_TRNS/______ on destination layer)
#define RAISE MO(_RAISE)
#define VIM MO(_VIM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
 *
 * QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |lgui  |
 * | Ctrl | alt  | lgui | VIM  |LOWER |    Space    |RAISE | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
 *
 * LGUI_T(KC_RGHT) left gui when held, right arrow when tapped
 */
[_QWERTY] = LAYOUT_planck_grid(
   KC_TAB        , KC_Q    , KC_W , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC         ,
   KC_ESC        , KC_A    , KC_S , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT         ,
   OSM(MOD_LSFT) , KC_Z    , KC_X , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT          ,
   KC_LCTL       , KC_LALT , VIM  , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , KC_RGHT , KC_DOWN , KC_UP   , LGUI_T(KC_RGHT)
)                ,

/** Raise
 * /-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  :   |   -  |   {  |  (   |   [  |   h  |  j   |   k  |  l   |   "  |  |   |
 * |------+------+------+------+-====-+------+------+-====-+------+------+------+------|
 * |      |      |  +   |   }  |  )   |   ]  |   =  |  _   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |  rgb |
 * `-------------------------------------------------------------------- --------------'
 */

[_RAISE] = LAYOUT_planck_grid(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC ,
    KC_DEL  , KC_COLN , KC_MINS , KC_LCBR , KC_LPRN , KC_LBRC , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_DQUO , KC_PIPE ,
    _______ , KC_EQL  , KC_PLUS , KC_RCBR , KC_RPRN , KC_RBRC , _______ , KC_UNDS , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , RGB_TOG
),

/**
 * lower
 * /-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |  '   |  \   |
 * |------+------+------+------+--==--+------+------+--==--+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+---- -+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
        KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8 , KC_9    , KC_0    , KC_BSPC ,
        KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_4    , KC_5 , KC_6    , KC_QUOT , KC_BSLS ,
        _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_1    , KC_2 , KC_3    , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_0 , KC_PDOT , _______ , _______
        ) ,

 /**
  * VIM
  *
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |  {   |   }  |      | "+y  |      |      |      |      | "+p  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |  (   |   )  |      | <-   |  V   |  ^   |  ->  |  '   | ente |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |   _  |      |      |      |  <   |  >   |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
[_VIM] = LAYOUT_planck_grid(
        _______ , _______ , _______ , KC_LCBR , KC_RCBR , _______ , VIM_COPY , _______ , _______ , _______ , VIM_PASTE , _______ ,
        _______ , _______ , _______ , KC_LPRN , KC_RPRN , _______ , KC_LEFT  , KC_DOWN , KC_UP   , KC_RGHT , KC_COLN   , KC_ENT  ,
        _______ , _______ , _______ , _______ , KC_UNDS , _______ , _______  , _______ , KC_LT   , KC_GT   , _______   , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______   , _______
        )
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/**
 * Quando si vuole sovrascrivere il comportamento di una tasto esistente o definire il comportamento di una nuova tasto,
 * si devono usare le funzioni `process_record_kb()` e `process_record_user()`.
 *
 * Queste vengono chiamate da QMK durante l'elaborazione del tasto, prima che venga gestito l'evento tasto vero e proprio.
 * Se queste funzioni restituiscono true, QMK elaborerà i codici dei tasti come di consueto.
 * Questo può essere utile per estendere la funzionalità di un tasto piuttosto che sostituirlo.
 * Se queste funzioni restituiscono false, QMK salterà la normale gestione dei tasti e
 * spetterà all'utente inviare gli eventi `key up` e `key down` necessari.
 *
 * Queste funzioni vengono richiamate ogni volta che un tasto viene premuto o rilasciato.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case VIM_COPY:
      if (record->event.pressed) {
        SEND_STRING("\"+y");
      }
      return false;
      break;
    case VIM_PASTE:
      if (record->event.pressed) {
        SEND_STRING("\"+p");
      }
      return false;
      break;
  }
  return true;
}
