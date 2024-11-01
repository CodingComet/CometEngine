#pragma once
#include <glad/glad.h>

class FBO
{
public:
	FBO();

	void bind();

private:
	GLuint id = 0;
};

