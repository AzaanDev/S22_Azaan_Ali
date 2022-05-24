#pragma once 
#include "SpriteImplementation.h" 

namespace Maniac
{
	class OpenGLSprite : public SpriteImplementation
	{
	public:
		OpenGLSprite(const std::string& filename);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() const override;

	private:
		unsigned int m_VAO, m_VBO, m_EBO, m_Tex;
		int m_Width{ 0 }, m_Height{ 0 };
	};

}