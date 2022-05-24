#pragma once

#include "ManiacApp.h"
#include "Window.h"
#include "Sprite.h"
#include "Shader.h"
#include "Render.h"
#include "KeyCodes.h"
#include "Events.h"

#define MANIAC_APPLICATION_START(name) \
\
int main()\
{\
	name game;\
	game.Run();\
}

