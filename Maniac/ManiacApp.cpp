#include "pch.h"
#include "ManiacApp.h"
#include "Window.h"

namespace Maniac
{
	void ManiacApp::Run()
	{
		MANIAC_LOG("Maniac running");

		Maniac::Window::Init();
		Maniac::Window::getWindow()->CreateWindow(800, 600, "Window");

		while (true)
		{
			onUpdate();
			Maniac::Window::getWindow()->SwapBuffers();
			Maniac::Window::getWindow()->PollEvents();
		}
	}
	void ManiacApp::onUpdate()
	{
	}
}
