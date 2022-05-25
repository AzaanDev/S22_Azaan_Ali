#pragma once 
#include "pch.h"
#include "glad/glad.h"
#include "SpriteImplementation.h" 
#include "OpenGLSprite.h"
#include "stb_image.h"
#include "ManiacUtilities.h"

namespace Maniac 
{
	OpenGLSprite::OpenGLSprite(const std::string& file)
	{
		stbi_set_flip_vertically_on_load(true);

		int numChannels;
		unsigned char* data = stbi_load(file.c_str(), &m_Width, &m_Height, &numChannels, 0);

		if (data == NULL)
			MANIAC_LOG("Error: Texture failed to load");


		float vertices[] = {
			0.0f,			0.0f, 0.0f, 0.0f,
			0.0f,			float(m_Height), 0.0f, 1.0f,
			float(m_Width), float(m_Height), 1.0f, 1.0f,
			float(m_Width), 0.0f, 1.0f, 0.0f
		};

		unsigned indeces[] = {
			0, 1, 2,
			0, 2, 3,
		};

		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);
		glGenBuffers(1, &m_EBO);

		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)8);
		glEnableVertexAttribArray(1);

		glGenBuffers(1, &m_Tex);
		glBindTexture(GL_TEXTURE_2D, m_Tex);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	int OpenGLSprite::GetWidth() const
	{
		return m_Width;
	}

	int OpenGLSprite::GetHeight() const
	{
		return m_Height;
	}

	void OpenGLSprite::Bind()
	{
		glBindVertexArray(m_VAO);
		glBindTexture(GL_TEXTURE_2D, m_Tex);
	}

	bool OpenGLSprite::IsBound() const
	{
		return false;
	}
}