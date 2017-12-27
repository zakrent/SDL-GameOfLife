#include <iostream>
#include "Program.h"

int main( int argc, char *argv[] ){
	SDL_Init(SDL_INIT_EVERYTHING);
	Program program;
	program.startMainLoop();
	return 0;
}
