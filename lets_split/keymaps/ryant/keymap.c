#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _MOVE  4
#define _MOUSE 5

#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LOWER  	MO(_LOWER)
#define RAISE  	MO(_RAISE)
#define MOVE 	MO(_MOVE)
#define SH_ENT 	LSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Ent* |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | MOVE | LOWER| Space| Space| RAISE| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SH_ENT, \
   KC_LCTL, KC_LALT, KC_LGUI, MOVE,	   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Ent* |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | MOVE | LOWER| Space| Space| RAISE| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_DEL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SH_ENT, \
  KC_LCTL, KC_LALT, KC_LGUI, MOVE,	  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),


/* LOWER
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |   `  |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_ESC,  _______, _______, _______, _______, KC_GRV,  _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  _______, KC_1, 	KC_2,    KC_3,    KC_4,     KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),


/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |   ~  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_ESC,  _______, _______, _______, _______, KC_TILD, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  | MW_U |      |  Up  |      | PGUP |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | MW_D | Left | Down | Right| PGDN |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F11 |  F12 | COPY |PASTE |      | WWW- | WWW+ |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_WH_U, _______, KC_UP,   _______, KC_PGUP, _______, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_WH_D, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
  _______, KC_F11,  KC_F12,  KC_COPY, KC_PSTE, _______, KC_WBAK, KC_WFWD, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  | MW_U | MB_L | M_U  | MB_R | MB_C | PGUP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F6  |  F7  |  F8  |  F9  |  F10 | MW_D | M_L  | M_D  | M_R  |      | PGDN |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F11 |  F12 | COPY |PASTE |      | WWW- | WWW+ |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_PGUP, _______, \
  KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN, KC_BTN3, \
  _______, KC_F11,  KC_F12,  KC_COPY, KC_PSTE, _______, KC_WBAK, KC_WFWD, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _MOVE, _MOUSE);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}
