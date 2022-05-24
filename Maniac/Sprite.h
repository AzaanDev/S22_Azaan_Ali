#pragma once
#include "SpriteImplementation.h"
#include "ManiacUtilities.h"

namespace Maniac 
{
	class MANIAC_API Sprite
	{
	public:
		Sprite(const std::string& filename);
		int GetWidth() const;
		int GetHeight() const;
		
		void Bind();
	private:
		SpriteImplementation* m_SpriteImp;
	};
}


