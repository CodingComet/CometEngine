#pragma once
#include <vector>
#include <glad/glad.h>

class EBO
{
public:
	EBO(GLuint count);
	EBO(GLuint* indices, GLuint count, GLenum drawType); // count != size
	EBO(std::vector<GLuint>& indices, GLenum drawType);
	~EBO();

	void bind() const;
	void unbind() const;

	GLuint get_count() const { return count; };
private:
	GLuint id;
	GLuint count;
};
