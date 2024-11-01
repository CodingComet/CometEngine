#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &id);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &id);
}


void VAO::bind() const
{
	glBindVertexArray(id);
}

void VAO::unbind() const
{
	glBindVertexArray(0);
}

void VAO::link_attribute(GLuint index, VBO& vbo, GLint nrComponents, GLenum type, GLsizei stride, void* offset) const
{
	vbo.bind();
	glVertexAttribPointer(index, nrComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(index);
	vbo.unbind();
}