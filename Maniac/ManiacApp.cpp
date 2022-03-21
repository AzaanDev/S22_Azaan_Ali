#include "pch.h"
#include "ManiacApp.h"

namespace Maniac
{
	void ManiacApp::Run()
	{
		MANIAC_LOG("Maniac running");
		while (true)
		{
			Update();
		}
	}
	void ManiacApp::Update()
	{
	}
}
