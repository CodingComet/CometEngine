#pragma once
#include "EBO.h"

EBO::EBO(GLuint count)
	: EBO(nullptr, count, GL_DYNAMIC_DRAW)
{}

EBO::EBO(GLuint* indices, GLuint count, GLenum drawType) :
	count(count)
{
	glGenBuffers(1, &id);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, drawType);
}

EBO::EBO(std::vector<GLuint>& indices, GLenum drawType)
	: EBO(indices.data(), indices.size(), drawType)
{}

EBO::~EBO()
{

	glDeleteBuffers(1, &id);
}

void EBO::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}