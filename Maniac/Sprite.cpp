#include "pch.h"
#include "Sprite.h"
#include "specificOPENGL/openglSprite.h"
namespace Maniac
{
	Sprite::Sprite(const std::string& filename)
	{
#ifdef MANIAC_OPENGL
		m_SpriteImp = new OpenGLSprite{filename};
#else
	#only_opengl_is_supported
#endif
	}

	int Sprite::GetWidth() const
	{
		return m_SpriteImp->GetWidth();
	}
	int Sprite::GetHeight() const
	{
		return m_SpriteImp->GetHeight();
	}
	void Sprite::Bind()
	{
		m_SpriteImp->Bind();
	}
}