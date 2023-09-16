#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);//버퍼생성
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);//VBOs랑 Buffer을 연결해줌 객체를 연결해준 것
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
