#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

//struct Vertex {
//	glm::vec3 position;
//	glm::vec3 color;
//	glm::vec3 normal;
//	glm::vec2 texture_coords;
//};

struct Vertex {
	glm::vec3 position;
	//glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 texture_coords;
};


class VBO
{
public:
	VBO(GLsizeiptr size);
	VBO(const void* vertices, GLsizeiptr size, GLenum drawType);
	VBO(const std::vector<Vertex>& vertices, GLenum drawType);
	~VBO();

	void bind() const;
	void unbind() const;
private:
	GLuint id;
};
