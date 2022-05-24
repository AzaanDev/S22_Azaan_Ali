#pragma once

#include "WindowOS.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Events.h"

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
		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> KeyPressedCallBack) override;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> KeyReleasedCallBack) override;

	private:
		GLFWwindow* mGLFWWindow {nullptr};

		struct CallBacks {
			std::function<void(const KeyPressedEvent&)> KeyPressedCallBack{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> KeyReleasedCallBack{ [](const KeyReleasedEvent&) {} };
		}m_CallBacks;
	};
}