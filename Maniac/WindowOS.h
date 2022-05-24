#pragma once

#include "pch.h"
#include "Events.h"

namespace Maniac
{
	class WindowOS
	{
	public:
		virtual bool CreateWindow(int width, int height, const std::string& name) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> KeyPressedCallBack) = 0;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> KeyReleasedCallBack) = 0;

	}; 
}