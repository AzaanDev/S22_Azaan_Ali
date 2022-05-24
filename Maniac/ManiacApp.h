#pragma once

#include "pch.h"
#include "ManiacUtilities.h"
#include "Events.h"
#define MANIAC_FRAME_RATE 60

namespace Maniac 
{
	class MANIAC_API ManiacApp
	{
	public:
		ManiacApp();
		void Run();
		virtual void onUpdate();
		void SetKeyPressedCallBack(std::function<void(const KeyPressedEvent&)> KeyPressedCallBack);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleasedEvent&)> KeyReleasedCallBack);

	private:
		std::chrono::milliseconds m_FrameDuration{1000/MANIAC_FRAME_RATE};
		std::chrono::steady_clock::time_point m_NextFrame;
	};
}

