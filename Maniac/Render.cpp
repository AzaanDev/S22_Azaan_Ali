#include "pch.h"
#include "Render.h"
#include "Window.h"
#include "specificOPENGL/OpenGLRenderer.h"

namespace Maniac 
{
	void Render::Init()
	{
		if (m_Instance == nullptr)
			m_Instance = new Render;
	}

	void Render::Draw(Maniac::Sprite& img, int x, int y, int z)
	{
		assert(m_Instance != nullptr);
		m_Instance->m_Implementation->Draw(img, x, y, z, m_Instance->m_Shader);
	}

	void Render::Clear()
	{
		m_Instance->m_Implementation->Clear();
	}

	Render::Render() : 
		m_Shader("../Maniac/Assets/Shaders/defaultVertex.glsl", "../Maniac/Assets/Shaders/defaultFragment.glsl") 
	{
#ifdef MANIAC_OPENGL
		m_Implementation = new OpenGLRenderer;
#else
		#only_opengl_is_supported
#endif
	}
}