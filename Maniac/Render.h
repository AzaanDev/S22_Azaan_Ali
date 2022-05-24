#pragma once
#include "Sprite.h"
#include "Shader.h"
#include "RenderImplementation.h"
#include "ManiacUtilities.h"
namespace Maniac 
{
	class MANIAC_API Render
	{
	public:
		static void Init();
		static void Draw(Maniac::Sprite& img, int x, int y, int z);
		static void Clear();
	private:
		inline static Render* m_Instance{ nullptr };
		Render();

		RenderImplementation* m_Implementation { nullptr };
		Maniac::Shader m_Shader;
	};
}

