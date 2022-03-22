#include "pch.h"
#include "Window.h"
#include "specificGLFW/GLFWWindow.h"

namespace Maniac
{
	void Window::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Window;
	}

	Window* Window::getWindow()
	{
		assert(mInstance);
		return mInstance;
	}

	bool Window::CreateWindow(int width, int height, const std::string& name)
	{
		return mWindow->CreateWindow(width, height, name);

	}

	void Window::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void Window::PollEvents()
	{
		mWindow->PollEvents();
	}

	int Window::getWidth() const
	{
		return mWindow->getWidth();
	}

	int Window::getHeight() const
	{
		return mWindow->getHeight();
	}

	Window::Window()
	{
#ifdef MANIAC_WINDOWS
	mWindow = new GLFWWindow;
#elif defined MANIAC_MACOS
	mWindow = new GLFWWindow;
#elif defined MANIAC_LINUX
	mWindow = new GLFWWindow;
#else
	#Unsupported_platform
#endif
	}
}