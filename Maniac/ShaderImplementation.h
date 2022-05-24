#pragma once


namespace Maniac
{
	class ShaderImplementation
	{
	public:
		virtual void SetUniform3Ints(const std::string& UniformName, int v1, int v2, int v3) = 0;
		virtual void SetUniform2Ints(const std::string& UniformName, int v1, int v2) = 0;
		virtual void Bind() = 0;
	};
}
