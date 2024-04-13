// Copyright 2024 torikimi (@torikimi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// USBに接続されているほうを左手とする。
#define MASTER_LEFT

// シリアル通信に使うピンを定義
#define SOFT_SERIAL_PIN D3

// USBに電源が入力されているか検知するために必要
#define SPLIT_USB_DETECT



//---    ジョイスティック    ---//
// ジョイスティックのピンの定義
//#define ANALOG_JOYSTICK_X_AXIS_PIN F7

//#define ANALOG_JOYSTICK_Y_AXIS_PIN B1

//#define ANALOG_JOYSTICK_CLICK_PIN B3

// 自動で移動量を決定？
//#define ANALOG_JOYSTICK_AUTO_AXIS	

// xを反転
//#define POINTING_DEVICE_INVERT_X

// たぶん意味ない
//#define JOYSTICK_BUTTON_COUNT 1
//#define JOYSTICK_AXES_COUNT 2
 


//---     エンコーダ     ---//
//マスター側にはエンコーダはない
#define ENCODERS_PAD_A { }
#define ENCODERS_PAD_B { }
#define ENCODER_RESOLUTIONS { }
//スレーブ（右）側にエンコーダのピンを定義
#define ENCODERS_PAD_A_RIGHT { F7 }
#define ENCODERS_PAD_B_RIGHT { B1 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
