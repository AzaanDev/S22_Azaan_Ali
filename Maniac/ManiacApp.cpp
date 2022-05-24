#include "pch.h"
#include "ManiacApp.h"
#include "Window.h"
#include "Sprite.h"
#include "Shader.h"
#include "Render.h"
#include "Events.h"
#include "KeyCodes.h"

namespace Maniac
{
	ManiacApp::ManiacApp()
	{
		MANIAC_LOG("Maniac running");

		Maniac::Window::Init();
		Maniac::Window::getWindow()->CreateWindow(1000, 800, "Window");
		Maniac::Render::Init();
	}

	void ManiacApp::Run()
	{

		m_NextFrame = std::chrono::steady_clock::now() + m_FrameDuration;

		while (true)
		{
			Render::Clear();
			onUpdate();

			std::this_thread::sleep_until(m_NextFrame);

			Maniac::Window::getWindow()->SwapBuffers();
			Maniac::Window::getWindow()->PollEvents();

			m_NextFrame += m_FrameDuration;
		}
	}

	void ManiacApp::onUpdate()
	{
	}

	void ManiacApp::SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> KeyPressedCallBack)
	{
		Window::getWindow()->SetKeyPressedCallBack(KeyPressedCallBack);
	}
	void ManiacApp::SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> KeyReleasedCallBack)
	{
		Window::getWindow()->SetKeyReleasedCallBack(KeyReleasedCallBack);
	}
}
