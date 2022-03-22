#include "pch.h"
#include "GLFWWindow.h"
#include "ManiacUtilities.h"

namespace Maniac
{
	GLFWWindow::GLFWWindow()
	{
		if(!glfwInit())
			MANIAC_LOG("Error: GLFW failed to initalize")
	}

	GLFWWindow::~GLFWWindow()
	{
		if (mGLFWWindow != nullptr)
			glfwDestroyWindow(mGLFWWindow);
		glfwTerminate();
	}

	bool GLFWWindow::CreateWindow(int width, int height, const std::string& name)
	{
		mGLFWWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		if (mGLFWWindow == nullptr)
		{
			MANIAC_LOG("Error: Failed to create glfw window");
			return false;
		}

		glfwMakeContextCurrent(mGLFWWindow);
		return true;
	}

	void GLFWWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGLFWWindow);
	}

	void GLFWWindow::PollEvents()
	{
		glfwPollEvents();
	}

	int GLFWWindow::getWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGLFWWindow, &width, &height);
		return width;
	}

	int GLFWWindow::getHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGLFWWindow, &width, &height);
		return height;
	}
}