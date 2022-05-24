#include "pch.h"
#include "Shader.h"
#include "specificOPENGL/OpenGLShader.h"

namespace Maniac 
{
	Shader::Shader(const std::string& VertexFile, const std::string& FragFile)
	{
#ifdef MANIAC_OPENGL
		m_Implementation = new OpenGLShader{ VertexFile, FragFile };
#else
		#only_opengl_is_supported
#endif

	}
	void Shader::SetUniform3Ints(const std::string& UniformName, int v1, int v2, int v3)
	{
		m_Implementation->SetUniform3Ints(UniformName, v1, v2, v3);
	}

	void Shader::SetUniform2Ints(const std::string& UniformName, int v1, int v2)
	{
		m_Implementation->SetUniform2Ints(UniformName, v1, v2);
	}

	void Shader::Bind()
	{
		m_Implementation->Bind();
	}
}

