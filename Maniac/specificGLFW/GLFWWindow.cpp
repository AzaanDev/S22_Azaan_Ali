#include "pch.h"
#include "GLFWWindow.h"
#include "ManiacUtilities.h"

namespace Maniac
{
	GLFWWindow::GLFWWindow()
	{
		if (!glfwInit())
			MANIAC_LOG("Error: GLFW failed to initalize");
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
		glfwSwapInterval(1);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			MANIAC_LOG("Error: Glad failed to initalize");

		glfwSetWindowUserPointer(mGLFWWindow, &m_CallBacks);

		glfwSetKeyCallback(mGLFWWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					CallBacks* UserPointer{ (CallBacks*)glfwGetWindowUserPointer(window) };
					KeyPressedEvent event{ key };
					UserPointer->KeyPressedCallBack(event);
				}
				else if (action == GLFW_RELEASE)
				{
					CallBacks* UserPointer{ (CallBacks*)glfwGetWindowUserPointer(window) };
					KeyReleasedEvent event{ key };
					UserPointer->KeyReleasedCallBack(event);
				}
			});

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

	void GLFWWindow::SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> KeyPressedCallBack)
	{
		m_CallBacks.KeyPressedCallBack = KeyPressedCallBack;
	}
	void GLFWWindow::SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> KeyReleasedCallBack)
	{
		m_CallBacks.KeyReleasedCallBack = KeyReleasedCallBack;
	}
}