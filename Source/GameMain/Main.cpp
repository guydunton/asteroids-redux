//-----------------------------------------------------------
// File: Main.cpp
// Description: Windows starting point for the program
//				Creates and intializes a game and runs it
//-----------------------------------------------------------

#include "STD.h"
#include "Game.h"

#ifdef RELEASE
#define TIME_SEEDED_RANDOM
#endif

#ifdef TIME_SEEDED_RANDOM
	#include <time.h>
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
#ifdef TIME_BASED_RANDOM
    // seed the randon number funtion using the start time
	srand( time(NULL) );
#endif

	Game game;
	game.Initialize( hInstance );

	return game.Run();
}