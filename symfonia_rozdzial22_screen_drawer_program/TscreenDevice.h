#ifndef TSCREENDEVICE_H
#define TSCREENDEVICE_H

#include <iostream>
#include <string>
#include <cmath> // for log, pow
#include <ctime> // for time

using namespace std;

/* ----------------------------------------------------------------------------- */
// The whole screen device
class TscreenDevice
{
    private:

        string screenText;
        char backgroundChar;

    public:

        enum { screenWidth = 76, screenHeight = 19 };

        // constructor
        TscreenDevice( char character = ' ' )
        {
            backgroundChar = character;
            clearScreen();
        }

        // fill the whole screen with just the background character (space)
        void clearScreen()
        {
            int howManyChars = screenWidth * screenHeight;
            screenText.assign( howManyChars, backgroundChar );

            // after the end of each line (screenWidth) insert a new line character
            for(int i=0; i < screenHeight; i++)
            {
                screenText[ (i+1) * screenWidth - 1 ] = '\n';
            }
        }

        // show the whole screen text
        void viewScreen()
        {
            cout << screenText << flush;
        }

        // view a specific text on the screen in a specific place
        void viewText( int column, int row, string text )
        {
            screenText.replace( (screenWidth * row) + column, text.length(), text );
        }

};

/* ----------------------------------------------------------------------------- */
// Instruments that will be shown on the screen
class Tinstrument
{
    private:

        string instrumentName;
        string instrumentUnits;
        int instrumentShows;
        int x, y; // where is the instrument on the screen placed
        // static variables are shared among all class objects and members
        // static data members have to be defined outside the class body
        static int howManyUnknown;

    public:

        // constructors
        Tinstrument( int, int, string, string, int = 0 );
        Tinstrument( void );

        // normal member functions
        void changeIndication( int w );
        void viewInstrument ( void );
};

#endif // TSCREENDEVICE_H
