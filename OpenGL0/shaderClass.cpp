#include "shaderClass.h"

std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	//###########SHADER
	//Create shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//Shader source link
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//Convert machine langage(assembly language)
	glCompileShader(vertexShader);

	//Create shader
	GLuint fragementshader = glCreateShader(GL_FRAGMENT_SHADER);
	//Shader source link
	glShaderSource(fragementshader, 1, &fragmentSource, NULL);
	//Convert machine langage(assembly language)
	glCompileShader(fragementshader);

	//Use two shader need to combine
	ID = glCreateProgram();//셰이더 프로그램이 한가지 이기에 기본타입으로 생성해준다.
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragementshader);

	glLinkProgram(ID);//프로그램을 쉐이더 프로그램을 참조로 넘겨서 링커 과정을 해준다.

	glDeleteShader(vertexShader);//이미 프로그램내에 들어갔기에 삭제해 준다.
	glDeleteShader(fragementshader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}