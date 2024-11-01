#include "VBO.h"

VBO::VBO(const void* vertices, GLsizeiptr size, GLenum drawType)
{
	glGenBuffers(1, &id);
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, drawType);
}

VBO::VBO(const std::vector<Vertex>& vertices, GLenum drawType)
	:VBO(vertices.data(), vertices.size() * sizeof(Vertex), drawType)
{}


VBO::VBO(GLsizeiptr size) :
	VBO(nullptr, size, GL_DYNAMIC_DRAW)
{}

VBO::~VBO()
{
	glDeleteBuffers(1, &id);
}

void VBO::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
