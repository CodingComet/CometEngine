#pragma once
#include <glad/glad.h>

class RBO
{
public:
	RBO(GLuint width, GLuint height);

	GLuint rbo = 0;
};

