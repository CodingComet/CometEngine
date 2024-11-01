#pragma once
#include "VBO.h"
#include <glad/glad.h>


class VAO
{
public:
	VAO();
	~VAO();

	void bind() const;
	void unbind() const;

	void link_attribute(GLuint index, VBO& vbo, GLint nrComponents, GLenum type, GLsizei stride, void* offset) const;
private:
	GLuint id = 0;
};
