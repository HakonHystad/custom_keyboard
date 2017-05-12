/*12-01-17*****************************************************************************************************
***************************************************************************************************************
**                                                                                                           **
**                                             keyboardConfig.h                                              **
**                                                                                                           **
***************************************************************************************************************
**************************************************************************************************************/


/* This header configures the pins used, global variables and constants and includes the layout*/

#ifndef _KEYBOARDCONFIG_
#define _KEYBOARDCONFIG_

/*#############################################################################################################

Section:                                          ~keyboard layout

#############################################################################################################*/

#include "HID_keys.h"

/*#############################################################################################################

Section:                                          ~macros

#############################################################################################################*/

#define LSB( n )	( n & 0xFF )// extract least significant byte
#define MSB( n )	( ( n>>8 ) & 0xFF )// extract most significant byte (from 16 bit nr)

/*#############################################################################################################

Section:                                          ~info sent to host

#############################################################################################################*/

#define MANUFACTURER 	L"Hystad"// USB uses unicode => L to get unicode length characters
#define PRODUCT		L"Keyboard"

/* if windows has problem finding the drivers match these to INF file, other OS' should be fine */
#define VENDOR_ID	0x0000
#define PRODUCT_ID	0x0000
/* specify version of the device */
#define VERSION_NR	0x0100 //ex: 0x0200 = version 2.0
#define COUNTRY_CODE   	0x13 // country code, here norwegian, 0 is non-localized

/*#############################################################################################################

Section:                                          ~keyboard (matrix) dimensions

#############################################################################################################*/

#define ROW_NR 5 // max 6
#define COL_NR 15 // max 16,  min 8

/*#############################################################################################################

Section:                                          ~settings

#############################################################################################################*/


/* debounce constant:
 * this constant determines how many matrix scans defines a 
 * change in switch state.
 * The needed value will vary dependent of the nr of rows and cloumns
 * and should be found experimentally 
*/
#define DEBOUNCE_TIMER 10

/*#############################################################################################################

Section:                                          ~Pins used

#############################################################################################################*/

/* row pins */
#define ROW_PORT F // PF7..PF4, PF1, PF0

#define ROW0 0
#define ROW1 1
#define ROW2 4
#define ROW3 5
#define ROW4 6
/*
#define ROW5
#define ROW6
#define ROW7
*/

/* look-up table for the pins used, add or remove pins here */
uint8_t rowPinArray[ ROW_NR ] = { ROW0, ROW1, ROW2, ROW3, ROW4 /*, ROW5, ROW6, ROW7*/ };

/* column pins */
#define COL_PORT_1 B // x

#if COL_NR>8
# define COL_PORT_2 D // y
#endif

// assumes column pins in assending order, ex: column 0 to COL_NR-1 = PINx0 (-PINx7) to (PINy0-) PINy7
// NB: ground pins not in use to avoid floating input


/*-------------------------------------- END OF USER CONFIG  ---------------------------------------*/

/*#############################################################################################################

Section:                                          ~macros

#############################################################################################################*/

#define CONCAT( s1, s2 )  s1 ## s2 // concatenate tokens


// helper macros to easy port/pin handeling
#define PORT( s ) CONCAT( PORT, s )
#define DDR( s )  CONCAT( DDR, s )
#define PIN( s )  CONCAT( PIN, s )

// look-up corresponding pin
#define ROW_TO_PIN( d ) rowPinArray[ d ]

typedef unsigned char uchar;

/*#############################################################################################################

Section:                                          ~constants

#############################################################################################################*/

#define BYTES_PER_ROW  		( COL_NR/8 + (COL_NR%8 != 0) )// if remainder: round up

#define SWITCH_STATE_SIZE       ( BYTES_PER_ROW*ROW_NR )



/*#############################################################################################################

Section:                                          ~look-up table

#############################################################################################################*/



const uint16_t keys[ROW_NR][COL_NR] = // physical layout
{
  {KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, N_KEY_PLUS, KEY_BACKSLASH,  KEY_BACKSPACE, KEY_DELETE},
  {KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, N_KEY_AA, N_KEY_TILDE,  0, KEY_HOME},
  {KEY_CAPS_LOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, N_KEY_OE, N_KEY_AE, N_KEY_ASTERIX,  KEY_ENTER, KEY_PAGE_UP},
  {N_KEY_BAR, N_KEY_BRACKET, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, N_KEY_MINUS, MODIFIERKEY_SHIFT,  KEY_UP, KEY_PAGE_DOWN},
  {MODIFIERKEY_CTRL, MODIFIERKEY_GUI, MODIFIERKEY_ALT, 0, 0, 0, KEY_SPACE, 0, 0, MODIFIERKEY_ALTGR, 0/*FUNCTION_KEY*/, MODIFIERKEY_CTRL, KEY_LEFT,  KEY_DOWN, KEY_RIGHT}
};// keys




#endif// _KEYBOARDCONFIG_
