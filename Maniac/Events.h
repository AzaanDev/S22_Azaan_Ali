#pragma once
#include "ManiacUtilities.h"

namespace Maniac 
{
	class MANIAC_API KeyPressedEvent
	{
	public:
		KeyPressedEvent() = delete;
		KeyPressedEvent(int Key);
		int GetKey() const;

	private:
		int m_Key;
	};

	class MANIAC_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent() = delete;
		KeyReleasedEvent(int Key);
		int GetKey() const;

	private:
		int m_Key;
	};
}

