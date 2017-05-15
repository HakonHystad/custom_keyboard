/*15-05-17*****************************************************************************************************
***************************************************************************************************************
**                                                                                                           **
**                                               KeyMatrix.cpp                                                **
**                                                                                                           **
***************************************************************************************************************
**************************************************************************************************************/

#include "KeyMatrix.h"


/**************************************************************************************************************
 *
KeyMatrix - constructor 
 *
 *************************************************************************************************************/
KeyMatrix::KeyMatrix()
{
    /* set up pin configuration */
    
    // rows are input with pull-up enabled
    DDR( ROW_PORT ) = 0;
    PORT( ROW_PORT ) |= 0xFF;

    // columns are Hi-Z, {DDRxn,PORTxn}=0b00, meant to be set as low output, {DDRxn,PORTxn}=0b10, sequentially
    DDR( COL_PORT_1 ) = 0;
    DDR( COL_PORT_2 ) = 0;
    PORT( COL_PORT_1 ) = 0;
    PORT( COL_PORT_2 ) = 0;
    
}



/**************************************************************************************************************
 *
 scan
 *
 *************************************************************************************************************/
void KeyMatrix::scan()
{

    uint16_t debounce = 0;
    
    // debounce by setting a threshold of unchanged states
    while( debounce < DEBOUNCE_TIMER*ROW_NR )
    {
	for ( int r = 0; r < ROW_NR; ++r )
	{
	    uint8_t prevState1 = keyState[0][r];
	    uint8_t prevState2 = keyState[1][r];
	    
	    for (int c = 0; i < 8; ++c)
	    {
		// pull down column
		DDR( COL_PORT_1 ) |= ( 1<<c );
		// read row (and invert so pressed=high
		keyState[0][r] &= ~( 1<<ROW_TO_PIN(r) & PIN(ROW_PORT) );
		// back to tri-state
		DDR( COL_PORT_1 ) = 0;
		
	    }// for c

	    
	    // continue with other column port
	    for (int c = 0; c < COL_NR-8; ++c)
	    {
		
		// pull down column
		DDR( COL_PORT_2 ) |= ( 1<<c );
		// read row (and invert so pressed=high
		keyState[1][r] &= ~( 1<<ROW_TO_PIN(r) & PIN(ROW_PORT) );
		// back to tri-state
		DDR( COL_PORT_2 ) = 0;
		
	    }

	    /* check if state is unchanged from last iteration */
	    if( keyState[0][r] == prevState1 && keyState[1][r] == prevState2 )
		debounce++;
	    else
		debounce = 0;

	  
	}// for r
    }// while

    setKeys();
}


/**************************************************************************************************************
 *
 resetKeys
 *
 *************************************************************************************************************/
void Keymatrix::resetKeys()
{

    // null out
    for (int i = 0; i < keyCount; ++i)
    {
	pressedKeys[i] = Key();
    }

    keyCount = 0;


    modifier = 0;
    fn = false;

}



/**************************************************************************************************************
 *
 setKeys
 *
 *************************************************************************************************************/
void KeyMatrix::setKeys()
{
    cli();// ignore usb interrupt
    
    resetKeys();
    
    /* check if key is set, if so convert to keyMap index  */
    for (int r = 0; r < ROW_NR; ++r)
    {
	for (int c = 0; c < 2; ++c)
	{
	    
	    if( keyState[c][r] == 0 ) continue;// no keys pressed

	    /* stupid but effective..*/
	    if( keyState[c][r] & 0x01 )
		setKey( r, 0 );
	    if( keyState[c][r] & 0x02 )
		setKey( r, 1 );
	    if( keyState[c][r] & 0x04 )
		setKey( r, 2 );
	    if( keyState[c][r] & 0x08 )
		setKey( r, 3 );
	    if( keyState[c][r] & 0x10 )
		setKey( r, 4 );
	    if( keyState[c][r] & 0x20 )
		setKey( r, 5 );
	    if( keyState[c][r] & 0x40 )
		setKey( r, 6 );
	    if( keyState[c][r] & 0x80 )
		setKey( r, 7 );
	}// for c
	
    }// for r

    sei();
    
}


/**************************************************************************************************************
 *
 setKey
 *
 *************************************************************************************************************/
 void KeyMatrix::setKey( const uint8_t r, const uint8_t c )
 {
     auto key = keyMap( r, c );

     if( key.isModifier() )
     {
	 modifier |= key.getKey();
	 return;
     }

     if( key.isFn() )
     {
	 fn = true;
	 return;
     }

     
     if( keyCount >= 6 )// 6 key rollover
	 keyCount = 0;

    
     pressedKeys[keyCount++] = key;
 }


/**************************************************************************************************************
 *
 isPressed
 *
 *************************************************************************************************************/
bool KeyMatrix::isPressed( const Key &key )
{
    for (int i = 0; i < 6; ++i)
    {
	if( pressedKeys[i] == key ) return true;
    }

    return false;
}


/**************************************************************************************************************
 *
 getKeycodes
 *
 *************************************************************************************************************/
void KeyMatrix::getKeycodes( uint16_t a[] )
{
    /* fill in 1 modifier and 6 keys */

    a[0] = modifier;
	
    for (int i = 0; i < 6; ++i)
    {
	if( fn )
	    a[i+1] = pressedKeys[i].getAltKey();
	else
	    a[i+1] = pressedKeys[i].getKey();
    }
    
}








