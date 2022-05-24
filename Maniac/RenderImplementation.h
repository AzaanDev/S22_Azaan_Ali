#pragma once
#include "Sprite.h"
#include "Shader.h"

namespace Maniac 
{
	class RenderImplementation {
	public:
		virtual void Draw(Maniac::Sprite& img, int x, int y, int z, Maniac::Shader shader) = 0;
		virtual void Clear() = 0;
	};
}