/*12-01-17*****************************************************************************************************
***************************************************************************************************************
**                                                                                                           **
**                                                layout_NO.h                                                **
**                                                                                                           **
***************************************************************************************************************
**************************************************************************************************************/

/* This header contains the HID definitions and the resulting look-up table for a tweaked norwegian layout*/

#ifndef _LAYOUT_NO_
#define _LAYOUT_NO_

/*#############################################################################################################

Section:                                          ~HID keyboard usage table

#############################################################################################################*/

/*      KEY                     ID     POSITION	*/
#define ROLL_OVER		0x01
#define KEY_A                   0x04// 31
#define KEY_B                   0x05// 50
#define KEY_C                   0x06// 48
#define KEY_D                   0x07// 33
#define KEY_E                   0x08// 19
#define KEY_F                   0x09// 34
#define KEY_G                   0x0A// 35
#define KEY_H                   0x0B// 36
#define KEY_I                   0X0C// 24
#define KEY_J                   0X0D// 37
#define KEY_K                   0X0E// 38
#define KEY_L                   0X0F// 39
#define KEY_M                   0X10// 52
#define KEY_N                   0X11// 51
#define KEY_O                   0X12// 25
#define KEY_P                   0X13
#define KEY_Q                   0X14
#define KEY_R                   0X15
#define KEY_S                   0X16
#define KEY_T                   0X17
#define KEY_U                   0X18
#define KEY_V                   0X19
#define KEY_W                   0X1A
#define KEY_X                   0X1B
#define KEY_Y                   0X1C
#define KEY_Z                   0X1D
#define KEY_1                   0X1E
#define KEY_2                   0X1F
#define KEY_3                   0X20
#define KEY_4                   0X21
#define KEY_5                   0X22
#define KEY_6                   0x23
#define KEY_7                   0x24
#define KEY_8                   0x25
#define KEY_9                   0x26
#define KEY_0                   0x27
#define KEY_ENTER               0x28
#define KEY_ESC                 0x29
#define KEY_BACKSPACE           0x2A
#define KEY_TAB                 0x2B
#define KEY_SPACE               0x2C
#define KEY_MINUS               0x2D
#define KEY_EQUAL               0x2E
#define KEY_LEFT_BRACE          0x2F
#define KEY_RIGHT_BRACE         0x30
#define KEY_BACKSLASH           0x31
#define KEY_NON_US_NUM          0x32
#define KEY_SEMICOLON           0x33
#define KEY_QUOTE               0x34
#define KEY_TILDE               0x35
#define KEY_COMMA               0x36
#define KEY_PERIOD              0x37
#define KEY_SLASH               0x38
#define KEY_CAPS_LOCK           0x39
#define KEY_F1                  0x3A
#define KEY_F2                  0x3B
#define KEY_F3                  0x3C
#define KEY_F4                  0x3D
#define KEY_F5                  0x3E
#define KEY_F6                  0x3F
#define KEY_F7                  0x40
#define KEY_F8                  0x41
#define KEY_F9                  0x42
#define KEY_F10                 0x43
#define KEY_F11                 0x44
#define KEY_F12                 0x45
#define KEY_PRINTSCREEN         0x46
#define KEY_SCROLL_LOCK         0x47
#define KEY_PAUSE               0x48
#define KEY_INSERT              0x49
#define KEY_HOME                0x4A
#define KEY_PAGE_UP             0x4B
#define KEY_DELETE              0x4C
#define KEY_END                 0x4D
#define KEY_PAGE_DOWN           0x4E
#define KEY_RIGHT               0x4F
#define KEY_LEFT                0x50
#define KEY_DOWN                0x51
#define KEY_UP                  0x52
#define KEY_NUM_LOCK            0x53
#define KEYPAD_SLASH            0x54
#define KEYPAD_ASTERIX          0x55
#define KEYPAD_MINUS            0x56
#define KEYPAD_PLUS             0x57
#define KEYPAD_ENTER            0x58
#define KEYPAD_1                0x59
#define KEYPAD_2                0x5A
#define KEYPAD_3                0x5B
#define KEYPAD_4                0x5C
#define KEYPAD_5                0x5D
#define KEYPAD_6                0x5E
#define KEYPAD_7                0x5F
#define KEYPAD_8                0x60
#define KEYPAD_9                0x61
#define KEYPAD_0                0x62
#define KEYPAD_PERIOD           0x63
#define KEY_NON_US_BS           0x64
#define KEY_MENU        	0x65
#define KEY_F13                 0x68
#define KEY_F14                 0x69
#define KEY_F15                 0x6A
#define KEY_F16                 0x6B
#define KEY_F17                 0x6C
#define KEY_F18                 0x6D
#define KEY_F19                 0x6E
#define KEY_F20                 0x6F
#define KEY_F21                 0x70
#define KEY_F22                 0x71
#define KEY_F23                 0x72
#define KEY_F24                 0x73

#define MODIFIERKEY_ALT         0xE2
#define MODIFIERKEY_GUI         0xE3
#define MODIFIERKEY_CTRL        0xE4
#define MODIFIERKEY_SHIFT       0xE5
#define MODIFIERKEY_ALTGR  	0xE6

/*----------------------------------- Norwegian equivallents in host software  ------------------------------------*/

#define N_KEY_PLUS		KEY_MINUS
#define N_KEY_BACKSLASH		KEY_EQUAL
#define N_KEY_AA		KEY_LEFT_BRACE
#define N_KEY_TILDE		KEY_RIGHT_BRACE
#define N_KEY_OE		KEY_SEMICOLON
#define N_KEY_AE		KEY_QUOTE
#define N_KEY_ASTERIX		KEY_NON_US_NUM
#define N_KEY_BAR		KEY_TILDE
#define N_KEY_BRACKET		KEY_NON_US_BS
#define N_KEY_MINUS		KEY_SLASH



#endif//_LAYOUT_NO_
