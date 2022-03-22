#pragma once

#include "ManiacApp.h"
#include "Window.h"

#define MANIAC_APPLICATION_START(name) \
\
int main()\
{\
	name game;\
	game.Run();\
}

