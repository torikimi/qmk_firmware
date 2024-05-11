# This file intentionally left blank

# 分割キーボードを宣言
SPLIT_KEYBOARD = yes

#シリアルドライバを設定 https://github.com/qmk/qmk_firmware/blob/master/docs/serial_driver.md
SERIAL_DRIVER = bitbang


# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_pointing_device.md
# https://github.com/joric/qmk/blob/master/docs/feature_joystick.md
# https://note.com/yinouet1001/n/n1537fba884e3
# http://www.neko.ne.jp/~freewing/hardware/qmk_firmware_test_analog_joystick_function_psp2000/
# ポインティングデバイスにジョイスティックを使うと宣言  
#POINTING_DEVICE_ENABLE = yes
#POINTING_DEVICE_DRIVER = analog_joystick
# じぶんでマウスレポートを作成する場合は以下をコメントアウト。しない場合は、上をコメントアウト
#JOYSTICK_ENABLE = yes
#JOYSTICK_DRIVER = analog


# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
# エンコーダーを使うと宣言
# ENCODER_ENABLE = yes  いったんコメントアウト

# エンコーダのマッピングを設定 スクロールや、音量の上げ下げを割り当てるために必要
# ENCODER_MAP_ENABLE = yes  いったんコメントアウト

# マウスキーを使うと宣言 スクロールや、クリックを使うために必要
MOUSEKEY_ENABLE = yes



# デバッグ用に定義
CONSOLE_ENABLE = yes