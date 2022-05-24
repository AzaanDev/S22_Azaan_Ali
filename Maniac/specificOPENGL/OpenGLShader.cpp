#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

namespace Maniac
{
	OpenGLShader::OpenGLShader(const std::string& VertexFile, const std::string& FragFile)
	{
		unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		std::string code;
		std::ifstream VertInput{ VertexFile };
		while (VertInput)
		{
			std::string line;
			std::getline(VertInput, line);
			line.append("\n");
			code += line;
		}
		VertInput.close();

		const char* VStr = code.c_str();
		glShaderSource(vertex_shader, 1, &VStr, NULL);
		glCompileShader(vertex_shader);

		int success;
		char infolog[512];
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex_shader, 512, NULL, infolog);
			std::cout << "Error: Shader Vertex Compilation Failed" << infolog << std::endl;
		}


		unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		code = "";
		std::ifstream FragInput{ FragFile };
		while (FragInput)
		{
			std::string line;
			std::getline(FragInput, line);
			line.append("\n");
			code += line;
		}
		FragInput.close();
		const char* fStr = code.c_str();

		glShaderSource(fragment_shader, 1, &fStr, NULL);
		glCompileShader(fragment_shader);
		;
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment_shader, 512, NULL, infolog);
			std::cout << "Error: Shader Fragment Compilation Failed" << infolog << std::endl;
		}


		m_ShaderProgram = glCreateProgram();
		glAttachShader(m_ShaderProgram, vertex_shader);
		glAttachShader(m_ShaderProgram, fragment_shader);
		glLinkProgram(m_ShaderProgram);

		glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infolog);
			std::cout << "Error: Shader Program Linking Failed" << infolog << std::endl;
		}

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

	}

	void OpenGLShader::SetUniform3Ints(const std::string& UniformName, int v1, int v2, int v3)
	{
		int uniform_location{ glGetUniformLocation(m_ShaderProgram, UniformName.c_str()) };
		glUseProgram(m_ShaderProgram);
		glUniform3i(uniform_location, v1, v2, v3);
	}

	void OpenGLShader::SetUniform2Ints(const std::string& UniformName, int v1, int v2)
	{
		int uniform_location{ glGetUniformLocation(m_ShaderProgram, UniformName.c_str()) };
		glUseProgram(m_ShaderProgram);
		glUniform2i(uniform_location, v1, v2);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_ShaderProgram);
	}
}