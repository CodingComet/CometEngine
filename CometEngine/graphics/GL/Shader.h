#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <optional>
#include <iostream>

class Shader
{
public:
	Shader(const char* vertex_code, const char* fragment_code);
	~Shader();

	Shader(Shader&& other) noexcept : id{std::exchange(other.id, 0)}  {}

	Shader& operator=(Shader&& other) noexcept {
		// Steal resources from other
		id = std::exchange(other.id, 0);
		return *this;
	}

	GLint get_uniform_location(const char* name) const { return glGetUniformLocation(id, name); } // SHOULD CACHE UNIFORM LOCATIONS

	static std::optional<Shader> load_shader(const char* vertex_path, const char* fragment_path);

	template<typename ... Args>
	void uniform(const char* name, const Args& ... args) const;

	void bind() const;

	GLuint get_id() const { return id; };

private:
	GLuint id = 0;
};

template<typename ...Args>
inline void Shader::uniform(const char* name, const Args & ...args) const
{
	std::cout << "SHOULD NEVER BE CALLED" << std::endl;
}

template<>
inline void Shader::uniform<int>(const char* name, const int& v) const
{
	glUniform1i(get_uniform_location(name), v);
}

template<>
inline void Shader::uniform<float>(const char* name, const float& v) const
{
	glUniform1f(get_uniform_location(name), v);
}

template<>
inline void Shader::uniform<glm::vec3>(const char* name, const glm::vec3& v) const
{
	glUniform3f(get_uniform_location(name), v.x, v.y, v.z);
}


template<>
inline void Shader::uniform<glm::mat4>(const char* name, const glm::mat4& v) const
{
	glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(v));
}
