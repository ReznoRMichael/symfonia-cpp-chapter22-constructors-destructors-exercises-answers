#include <iostream>
#include "TscreenDevice.h"

extern TscreenDevice screen;

using namespace std;

/* ----------------------------------------------------------------------------- */
// helper function
void delay( int seconds );
/* ----------------------------------------------------------------------------- */

int main()
{
    screen.clearScreen();

    // objects definitions
    Tinstrument Velo( 2, 1, "Velocity", "knots", 110 );
    Tinstrument Asce( 2, 7, "Ascending", "ft/s" );
    Tinstrument A;
    Tinstrument B;
    volatile Tinstrument C;

    const Tinstrument Load( 2, 11, "Max load", "t", 15000 );

    // simulation of real time display
    for(int i=0; i < 30; i++)
    {
        Asce.changeIndication( i );
        Velo.changeIndication( 110 + i );
        A.changeIndication( -i );
        B.changeIndication( i % 4 );
//        C.changeIndication( i % 3 ); // volatile object
//        Load.changeIndication( 270 ); // const object

        // 1 second delay
        delay( 1 );
    }

    return 0;
}

/* ----------------------------------------------------------------------------- */
// helper function that waits for the given amount of seconds
void delay( int seconds )
{
    time_t startingTime = time( NULL );

    // this loop runs until the given seconds amount won't pass
    while( time( NULL ) - startingTime < seconds ); // empty while loop body
}
/* ----------------------------------------------------------------------------- */
