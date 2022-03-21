#pragma once

#include "pch.h"

#ifdef MANIAC_LIB
	#define MANIAC_API __declspec(dllexport)
#else
	#define MANIAC_API __declspec(dllimport)
#endif 

#ifdef MANIAC_DEBUG
	#define MANIAC_LOG(x) std::cout << x << std::endl;
#else
	#define MANIAC_LOG(x)
#endif // MANIAC_DEBUG
