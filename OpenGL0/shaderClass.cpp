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
	//파일에서 읽어서 이를 넣어줌
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	//c_str()은 string을 const char로 바꿔주는 것이다. string으로 하면은 내부의 것을 건들수 있기에 const char형으로 바꿔서 처리해주는 것 같다.
	const char* fragmentSource = fragmentCode.c_str();

	//###########SHADER
	//Create shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//이제 쉐이더를 받을 객체들을 생성해서 만들어주며 소스코드와 연결해서 이를 작동하도록 설정함
	//Shader source link
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//Convert machine langage(assembly language)
	glCompileShader(vertexShader);
	compileErrors(vertexShader, "VERTEX");
	//컴파일로 기계가 알아듣도록 설정

	//Create shader
	GLuint fragementshader = glCreateShader(GL_FRAGMENT_SHADER);
	//Shader source link
	glShaderSource(fragementshader, 1, &fragmentSource, NULL);
	//Convert machine langage(assembly language)
	glCompileShader(fragementshader);
	compileErrors(fragementshader, "FRAGMENT");

	//Use two shader need to combine
	ID = glCreateProgram();//셰이더 프로그램이 한가지 이기에 기본타입으로 생성해준다.
	// ID로 프로그램을 넣어준다.
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragementshader);
	compileErrors(ID, "PROGRAM");

	glLinkProgram(ID);//프로그램을 쉐이더 프로그램을 참조로 넘겨서 링커 과정을 해준다.

	glDeleteShader(vertexShader);//이미 프로그램내에 들어갔기에 삭제해 준다.
	glDeleteShader(fragementshader);
}

void Shader::Activate()
{
	glUseProgram(ID);//프로그램을 사용할 것이다를 설정한다.
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for" << type << "\n" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for" << type << "\n" << std::endl;
		}
	}
}
