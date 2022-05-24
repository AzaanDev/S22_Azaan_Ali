#include "pch.h"
#include "OpenGLRenderer.h"
#include "Window.h"
#include "glad/glad.h"

namespace Maniac 
{
	void OpenGLRenderer::Draw(Maniac::Sprite& img, int x, int y, int z,Maniac::Shader shader)
	{
		shader.SetUniform2Ints("windowSize", Window::getWindow()->getWidth(), Window::getWindow()->getHeight());
		shader.SetUniform3Ints("spriteCoord", x, y, z);
		shader.Bind();
		img.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void OpenGLRenderer::Clear()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
