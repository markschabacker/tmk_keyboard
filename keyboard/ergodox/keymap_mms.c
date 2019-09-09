#include <util/delay.h>
#include "bootloader.h"
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |      |           |   6  |   7  |   8  |   9  |   0  |   -  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L1  | LAlt | LGui |  Lft | Rght |                                       |  Up  |  Dn  |      |      | RGui |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Esc  | LAlt |       | RAlt |RCtrl |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | BkSp | LGui |------|       |------| Enter| Space|
     *                                 |      |      |  ~L1 |       | ~L1  |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Keymap: L2
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |  F6  |  F7  |  F8  |  F9  |  F0  |  F11 |  F12   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | TRNS   |      |      |  Up  |      |      |      |           |      |      | Ins  | PgUp |  Del |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | TRNS   |      |  Lft |  Dn  | Rght |      |------|           |------|      | Home | PgDn |  End |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | TRNS   |      |      |      |      |      |      |           |      |      | PrtSc| ScrLk| Pause|      |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | Caps |       | TRNS | TRNS |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | Del  | TRNS |------|       |------| TRNS | TRNS |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     */

    KEYMAP(  // Layer0: default, leftled:none
        // left hand
        GRV, 1,   2,   3,   4,   5,   NO,
        TAB, Q,   W,   E,   R,   T,   LBRC,
        LCTL,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   NO,
        FN1 ,LALT,LGUI,LEFT,RGHT,
                                      ESC,LALT,
                                           NO,
                                 BSPC,LGUI,FN1,
        // right hand
             6,   7,   8,   9,   0,MINS,   EQL,
             RBRC,Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             NO,  N,   M,   COMM,DOT, SLSH,RSFT,
                       DOWN,UP  ,NO,  NO  ,RGUI,
        RALT,RCTL,
        NO,
        FN1, ENT, SPC
    ),

    KEYMAP(  // Layer1: Functions and Utils, leftled:all
        // left hand
        ESC, F1,  F2,  F3,  F4,  F5,  NO,
        TRNS,NO,  NO,  UP,  NO,  NO,  NO,
        TRNS,NO,  LEFT,DOWN,RGHT,NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,CAPS,
                                           NO,
                                 DEL ,TRNS,TRNS,
        // right hand
             F6,  F7,  F8,  F9, F10, F11,   F12,
             NO,  NO,  INS, PGUP,DEL, NO,  TRNS,
                  NO,  HOME,PGDN,END, NO,  TRNS,
             TRNS,NO,  PSCR,SLCK,PAUS,NO,  TRNS,
                       TRNS,  NO,  NO,  NO,  NO,
        TRNS,TRNS,
        NO,
        TRNS,TRNS,TRNS
    ),

/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_KEY,
    L_CTRL_ALT_ENT,
    R_CTRL_ALT_ENT,
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key
    [1] =   ACTION_LAYER_MOMENTARY(1),                      // FN1 - momentary Layer1
    [2] =   ACTION_LAYER_MOMENTARY(2),                      // FN2 - momentary Layer2
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
