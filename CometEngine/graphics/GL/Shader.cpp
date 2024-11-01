#include "Shader.h"
#include <fstream>

std::optional<std::string> read_file(const std::string& path)
{
	std::ifstream ifs(path);
	if (!ifs.is_open())
		return std::nullopt;

	return std::string((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
}

Shader::Shader(const char* vertex_code, const char* fragment_code)
{
	// build and compile our shader program
	// ------------------------------------
	// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_code, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_code, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);
	// check for linking errors
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
	glDeleteProgram(id);
}

std::optional<Shader> Shader::load_shader(const char* vertex_path, const char* fragment_path)
{

	// TODO: SHOULD USE MORE SOPHISTICATED WAY TO CHECK HERE
	auto vertex_code = read_file(vertex_path);
	auto fragment_code = read_file(fragment_path);

	if (!(vertex_code.has_value() && fragment_code.has_value())) return std::nullopt; // TODO: tell user of function!

	return std::move(Shader(vertex_code.value().c_str(), fragment_code.value().c_str()));
}

void Shader::bind() const
{
	glUseProgram(id);
}
