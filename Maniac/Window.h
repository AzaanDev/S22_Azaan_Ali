#pragma once

#include "WindowOS.h"
#include "ManiacUtilities.h"
#include "Events.h"

namespace Maniac
{
	class MANIAC_API Window
	{
	public:
		static void Init();
		static Window* getWindow();
		bool CreateWindow(int width, int height, const std::string& name);
		void SwapBuffers();
		void PollEvents();
		int getWidth() const;
		int getHeight() const;

		void SetKeyPressedCallBack(const std::function<void(const KeyPressedEvent&)>& KeyPressedCallBack);
		void SetKeyReleasedCallBack(const std::function<void(const KeyReleasedEvent&)>& KeyReleasedCallBack);

	private:
		inline static Window* mInstance{ nullptr };

		Window();

		WindowOS* mWindow{ nullptr };
	};
}

