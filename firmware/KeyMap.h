/*12-05-17*****************************************************************************************************
***************************************************************************************************************
**                                                                                                           **
**                                                 KeyMap.h                                                  **
**                                                                                                           **
***************************************************************************************************************
**************************************************************************************************************/

#ifndef _KEYMAP_H_
#define _KEYMAP_H_

/*#############################################################################################################

Section:                                          ~libs

#############################################################################################################*/

#include "keyboardConfig.h"

#include <stdint.h>

/*#############################################################################################################

Section:                                          ~declarations

#############################################################################################################*/

/* Hold key value and and alt value to be used with function keys */
class Key
{

public:
    Key()
	: key(0), altKey(0)
	{}
    Key( uint16_t key, uint16_t altKey = 0 )
	: key(key), altKey(altKey)
	{}

    uint16_t getKey() const{ return key; }
    uint16_t getAltKey() const{ return altKey; }

    void setKey( uint16_t key ){ this->key = key; }
    void setAltKey( uint16_t altKey ){ this->altKey = altKey; }

protected:

private:
    uint16_t key;
    uint16_t altKey;

};


/* Keeps track of the layout and return modifiable key objects */

class KeyMap
{

public:
    KeyMap()// initialize with layout specified in config file
	{
	    for (int r = 0; r < ROW_NR; ++r)
	    {
		for (int c = 0; c < COL_NR; ++c)
		{
		    keyList[r][c].setKey( keys[r][c] );
		}
	    }
	}

    Key& operator()( const int r, const int c )
	{  
	    return keyList[r][c];
	}  

protected:

private:

    Key keyList[ROW_NR][COL_NR];

};

#endif// header guard
