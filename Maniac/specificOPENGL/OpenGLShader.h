#pragma once

#include "ShaderImplementation.h"

namespace Maniac
{
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& VertexFile, const std::string& FragFile);
		virtual void SetUniform3Ints(const std::string& UniformName, int v1, int v2, int v3) override;
		virtual void SetUniform2Ints(const std::string& UniformName, int v1, int v2) override;
		virtual void Bind() override;
	private:
		unsigned int m_ShaderProgram;
	};
}
