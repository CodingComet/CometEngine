#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <glad/glad.h>

class Texture
{
public:
	Texture(const std::vector<std::string>& faces);
	Texture(const char* path, bool flip = true);
	Texture(GLenum format, GLsizei width, GLsizei height, GLint filter);
	~Texture();

	void bind(GLenum textureUnit) const;

	GLint get_width() const { return width; };
	GLint get_height() const { return height; };
	GLuint get_id() const { return id; };
	
	GLuint id = 0;
private:
	GLint width = 0;
	GLint height = 0;
};
