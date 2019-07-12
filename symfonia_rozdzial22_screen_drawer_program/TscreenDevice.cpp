#include "TscreenDevice.h"
#include <sstream>

// define the global screenDevice object with a . as a default blank screen character
TscreenDevice screen('.');

// helper member function declaration for int -> text conversion
string numberIntoText( int value );

/* ----------------------------------------------------------------------- */
// constructor definitions
Tinstrument::Tinstrument( int xPos, int yPos, string iName, string iUnits, int iShows )
{
    instrumentName = iName;
    instrumentUnits = iUnits;
    instrumentShows = iShows;
    x = xPos;
    y = yPos;

    viewInstrument();
}

/* ----------------------------------------------------------------------- */
Tinstrument::Tinstrument( void )
{
    // just another unknown instrument (uses static variable to share the same value)
    ++howManyUnknown;
    instrumentUnits = " ";

    // fill the instrument with text Pointer no. n
    instrumentName = "Display no. ";
    instrumentName += numberIntoText( howManyUnknown );

    // the instrument's position on the screen
    x = 38;
    y = 1 + (howManyUnknown - 1) * 4;

    // what the instrument has to show
    instrumentShows = 0;

    viewInstrument();
}

/* ----------------------------------------------------------------------- */
// member functions
void Tinstrument::changeIndication( int w )
{
    instrumentShows = w;

    viewInstrument();
}

/* ----------------------------------------------------------------------- */
void Tinstrument::viewInstrument()
{
    // draws the instrument's frame on the screen

    // the drawing of an empty frame has to be done first
    screen.viewText( x, y,   "_______________________" );
    screen.viewText( x, y+1, "|                     |" );
    screen.viewText( x, y+2, "|                     |" );
    screen.viewText( x, y+3, "_______________________" );

    // now we can replace the inside frame string with some text
    screen.viewText( x+2, y+1, instrumentName );
    screen.viewText( x+3, y+2, numberIntoText( instrumentShows ) );
    screen.viewText( x+9, y+2, instrumentUnits );

    // view the updated screen
    screen.viewScreen();
}

/* ----------------------------------------------------------------------- */
// static variable (shared among all objects)
int Tinstrument::howManyUnknown;
/* ----------------------------------------------------------------------- */
// convert int into string in two ways (manually and through ostringstream)
/* ----------------------------------------------------------------------- */
string numberIntoText( int value )
{
#define I_AM_ADVANCED 1

#if I_AM_ADVANCED == 0

// version for the beginners (do everything manually)

    if( value == 0 ) return "0"; // just zero

    string conversionResult;

    // if the value is lower than zero, then just append a minus and work like with a positive number
    if( value < 0 )
    {
        conversionResult += '-';
        value = -value;
    }

    int valueTemp = value;

    // lower floor is a power of 10 that is no higher than the given value.
    // for example for 852 it will be 100.
    int lowerFloor = (int) pow( 10.0,  (int) log10( (double) value ) );

    for( ; lowerFloor > 0; lowerFloor /= 10 )
    {
        int digit = valueTemp / lowerFloor;
        valueTemp = valueTemp % lowerFloor;

        conversionResult += char( '0' + digit );
    }

    return conversionResult;

#else

// version for advanced is more simpler using ostringstream

    ostringstream stringS;
    stringS << value;

    return stringS.str();

#endif // I_AM_ADVANCED
}
