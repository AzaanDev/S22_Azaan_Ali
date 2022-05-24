#pragma once

#include "RenderImplementation.h"

namespace Maniac 
{
	class OpenGLRenderer : public RenderImplementation {
		virtual void Draw(Maniac::Sprite& img, int x, int y, int z, Maniac::Shader shader) override;
		virtual void Clear() override;
	};
}