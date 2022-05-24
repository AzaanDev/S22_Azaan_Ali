#pragma once

#include "ManiacUtilities.h"
#include "ShaderImplementation.h"

namespace Maniac 
{
	class MANIAC_API Shader
	{
	public:
		Shader(const std::string &VertexFile, const std::string& FragFile);
		void SetUniform3Ints(const std::string& UniformName, int v1, int v2, int v3);
		void SetUniform2Ints(const std::string& UniformName, int v1, int v2);
		void Bind();
	private:
		ShaderImplementation* m_Implementation;
	};
}

