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
    : modifier(0),fn(false)
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
 setKeys
 *
 *************************************************************************************************************/
void Keymatrix::setKeys()
{
    
}




