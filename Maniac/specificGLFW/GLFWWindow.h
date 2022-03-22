#pragma once

#include "WindowOS.h"
#include "GLFW/glfw3.h"

namespace Maniac
{
	class GLFWWindow : public WindowOS
	{
	public:
		GLFWWindow();
		~GLFWWindow();
		virtual bool CreateWindow(int width, int height, const std::string& name) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int getWidth() const override;
		virtual int getHeight() const override;

	private:
		GLFWwindow* mGLFWWindow {nullptr};
	};
}