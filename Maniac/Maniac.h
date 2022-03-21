#pragma once

#include "ManiacApp.h"

#define MANIAC_APPLICATION_START(name) \
\
int main()\
{\
	name game;\
	game.Run();\
}

