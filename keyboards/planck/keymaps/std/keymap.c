/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _CAT
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  EXT_PLV,
  O3O_COPY,
  O3O_PASTE,
  O3O_SBLK,
  O3O_EBLK,
};


// Tap Dance declarations
enum {
    TD_COMMA, // ,<
    TD_DOT, // ,.
    TD_Q, // q and caps.

};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, S(KC_COMMA)),
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_DOT)),
    [TD_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, S(KC_CAPS)),
};

// layer
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define L1 MO(_CAT)

#define SFT_SP LSFT_T(KC_SPC) // NOT USED Left Shift when held, space when tapped
#define _SL LSFT_T(KC_LEFT) // Left Shift when held, left arrow when tapped
#define _GR LGUI_T(KC_RGHT)// left gui Shift when held, right arrow when tapped
#define _SFT  OSM(MOD_LSFT)// one shot  shift, shift remaining active until next key is press.
# define _N_ KC_TRANSPARENT  //abbrev for transparent
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; : |  ent |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  / ? | shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | alt  |  L1  | gui  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_planck_grid(
 KC_TAB  , TD(TD_Q) , KC_W , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I         , KC_O       , KC_P    , KC_BSPC ,
 KC_ESC  , KC_A     , KC_S , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K         , KC_L       , KC_SCLN , KC_ENT  ,
 _SFT    , KC_Z     , KC_X , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , TD(TD_COMMA) , TD(TD_DOT) , KC_SLSH , _SFT    ,
 KC_LCTL , KC_LALT  , L1   , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , _SL          , KC_DOWN    , KC_UP   , _GR
      )  ,

  /* Raise
   * ,-----------------------------------------------------------------------------------.
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
KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
KC_DEL , KC_COLN, KC_MINS, KC_LCBR, KC_LPRN, KC_LBRC, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_DQUO, KC_PIPE,
_N_    , KC_EQL , KC_PLUS, KC_RCBR, KC_RPRN, KC_RBRC, _N_    , KC_UNDS, _N_    , _N_    , _N_    , _N_,
_N_    , _N_    , _N_    , _N_    , _N_    , _N_    , _N_    , _N_    , _N_    , _N_    , _N_    , RGB_TOG
      ),
  /* lower
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |  '   |  \   |
   * |------+------+------+------+--==--+------+------+--==--+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |      |      |
   * |------+------+------+------+------+------+------+------+---- -+------+------+------|
   * |      |      |      |      |  low |             |  up  |   0  |   .  |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
KC_GRV , KC_1  , KC_2  , KC_3  , KC_4   , KC_5   , KC_6   , KC_7 , KC_8 , KC_9    , KC_0    , KC_BSPC ,
KC_DEL , KC_F1 , KC_F2 , KC_F3 , KC_F4  , KC_F5  , KC_F6  , KC_4 , KC_5 , KC_6    , KC_QUOT , KC_BSLS ,
_N_    , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F11 , KC_F12 , KC_1 , KC_2 , KC_3    , _N_     , _N_ ,
_N_    , _N_   , _N_   , _N_   , _N_    , _N_    , _N_    , _N_  , KC_0 , KC_PDOT , _N_     , _N_
      ),

 /* cat
   * ,-----------------------------------------------------------------------------------.
   * |      | q    |      | {    | }     | "+y  |      |      |      |      | "+p  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | )     |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  z   |  x   |   c  | _    |  b   |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_CAT] = LAYOUT_planck_grid(
_N_ , _N_ , _N_ , KC_LCBR , KC_RCBR , _N_ , O3O_COPY , _N_     , O3O_SBLK , O3O_EBLK , O3O_PASTE , _N_    ,
_N_ , _N_ , _N_ , KC_LPRN , KC_RPRN , _N_ , KC_LEFT  , KC_DOWN , KC_UP    , KC_RGHT  , KC_COLN   , KC_ENT ,
_N_ , _N_ , _N_ , _N_     , KC_UNDS , _N_ , _N_      , _N_     , KC_LT    , KC_GT    , _N_       , _N_    ,
_N_ , _N_ , _N_ , _N_     , _N_     , _N_ , _N_      , _N_     , _N_      , _N_      , _N_       , _N_
      )
};

#ifdef AUDIO_ENABLE
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/*layer_state_t layer_state_set_user(layer_state_t state) {*/
  /*return update_tri_layer_state(state, _LOWER, _RAISE, _CAT);*/
/*}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
        backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
        writePinLow(E6);
#endif
      } else {
        unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
        writePinHigh(E6);
#endif
      }
      return false;
    case O3O_COPY:
      if (record->event.pressed) {
        SEND_STRING("\"+y");
      }
      return false;
    case O3O_PASTE:
      if (record->event.pressed) {
        SEND_STRING("\"+p");
      }
      return false;
    case O3O_SBLK:
      if (record->event.pressed) {
        SEND_STRING("[{");
      }
      return false;
    case O3O_EBLK:
      if (record->event.pressed) {
        SEND_STRING("]}");
      }
      return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_DOWN);
#else
      tap_code(KC_PGDN);
#endif
    } else {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_UP);
#else
      tap_code(KC_PGUP);
#endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0: {
#ifdef AUDIO_ENABLE
              static bool play_sound = false;
#endif
              if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
              } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
              }
#ifdef AUDIO_ENABLE
              play_sound = true;
#endif
              break;
            }
    case 1:
            if (active) {
              muse_mode = true;
            } else {
              muse_mode = false;
            }
  }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else {
    if (muse_counter) {
      stop_all_notes();
      muse_counter = 0;
    }
  }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
