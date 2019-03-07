#pragma once
#include "ofMain.h"
#include <iostream>

namespace Core
{
	class Shader_Loader
	{
	private:
		std::string ReadShader(char *filename);
		GLuint CreateShader(GLenum shaderType, std::string source, char* shadername);

	public:
		GLuint CreateProgram(char* VertexShaderFilename, char* FragmentShaderFilename);
	};
}


