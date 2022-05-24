#include "pch.h"
#include "Events.h"

namespace Maniac 
{
	KeyPressedEvent::KeyPressedEvent(int Key) : m_Key(Key)
	{
	}

	int KeyPressedEvent::GetKey() const
	{
		return m_Key;
	}

	KeyReleasedEvent::KeyReleasedEvent(int Key) : m_Key(Key)
	{
	}
	int KeyReleasedEvent::GetKey() const
	{
		return m_Key;
	}
}