#pragma once

#include "WindowOS.h"

namespace Maniac
{
	class Window
	{
	public:
		static void Init();
		static Window* getWindow();
		bool CreateWindow(int width, int height, const std::string& name);
		void SwapBuffers();
		void PollEvents();
		int getWidth() const;
		int getHeight() const;

	private:
		inline static Window* mInstance{ nullptr };

		Window();

		WindowOS* mWindow{ nullptr };
	};
}

