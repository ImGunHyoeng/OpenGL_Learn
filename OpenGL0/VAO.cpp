#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);//배열 오브젝트
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);//외부에서 정점 셰이더와 통신하는 방법이다.
	glEnableVertexAttribArray(layout);//이렇게 하는 이유는 vertext Attribute의 위치 이기 때문이다.
	VBO.Unbind();
}

//void VAO::LinkVBO(VBO& VBO, GLuint layout)
//{
//	VBO.Bind();
//	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);//외부에서 정점 셰이더와 통신하는 방법이다.
//	glEnableVertexAttribArray(layout);//이렇게 하는 이유는 vertext Attribute의 위치 이기 때문이다.
//	VBO.Unbind();
//}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1,&ID);
}
