// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H





enum custom_keycodes {
  TXT_WIN = SAFE_RANGE,   // winモードを使っていると表示するためのキー
  TXT_MAC,                // macモードを使って--
  IME_W,                  //windowsのimeきりかえ
  IME_M                   //macのime切り替え
};





enum layer_number {
    _Q_WIN = 0,
    _Q_MAC,
    _L_WIN,
    _L_MAC,
    _R_WIN,
    _R_MAC
};





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TXT_WIN:
      if (record->event.pressed) {
        SEND_STRING("windows mode");
      }
      return false;
    case TXT_MAC:
      if (record->event.pressed) {
        SEND_STRING("mac mode");
      }
      return false;
    case IME_W:    //IME切り替えのキー(windows)が押されたら、alt+` を入力する
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`"));
      }
      return false;
    case IME_M:    //IME切り替えのキー(mac)が押されたら、alt+` を入力する
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(" "));
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    LT(layer, keycode)で、キーを押し続けている間は、layerのレイヤに切り替わる。短押しだと、keycodeが押される。
    MO(layer)で、キーを押し続けている間は、layerのレイヤに切り替わる。
     */
    [_Q_WIN] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
 LT(_L_WIN,KC_F13), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_R_WIN),
        KC_LWIN, KC_LALT, KC_LCTL, KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),


    /*
    winをctrlに、ctrlをcommandキーに変更
    */
    [_Q_MAC] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
 LT(_L_MAC,KC_F12), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_R_MAC),
        KC_LCTL, KC_LALT, KC_LCMD, KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),


    /*
    DELはカーソルの右側を削除、BSPCはカーソルの左側を削除。 F13 + ] = DEL
    ENDは文末にカーソルを移動、HOMEは文頭にカーソルを移動。 F13 + f = END,  F13 + b = HOME
    hjlkで矢印                                       F13 + h = 右,  F13 + j = 下,  F13 + k = 上,  F13 + l = 右
    _LOWERレイヤでspaceを押すと、shiftになり、文字の選択ができる
    winモードとMacモードの違いは、ctrlの位置にある変換キーの違い
    */
    [_L_WIN] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,  KC_BSPC,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_END,  KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   IME_W,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    [_L_MAC] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,  KC_BSPC,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_END,  KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   IME_M,   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),


    /*
    数字の位置にF1-F12までを割り当てている。
    TG(_Q_MAC)でmacモード、winモードの切り替えを行っている
    */
    [_R_WIN] = LAYOUT(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(_Q_MAC),TXT_WIN,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),


    /*
    
    */
    [_R_MAC] = LAYOUT(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG(_Q_MAC),TXT_MAC,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};





// エンコーダのマッピング     全てのレイヤーで、エンコーダにスクロールすることをマッピングする
/*いったんコメントアウト
#if defined(ENCODER_MAP_ENABLE)
  const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
      [_Q_WIN] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
      [_Q_MAC] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
      [_L_WIN] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
      [_L_MAC] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
      [_R_WIN] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
      [_R_MAC] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) }
  };
#endif
*/



// これはたぶん意味ない
/*
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(F7, 300, 600, 900),
    [1] = JOYSTICK_AXIS_IN(B1, 0, 1000, 2000)
};
*/
