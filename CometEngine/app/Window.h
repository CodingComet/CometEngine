#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include "io/Input.h"

class Window
{
public:
	Window(const char* title, int width, int height, Input* input_handler);

	void update();
	void close() const;
	bool is_open() const;
	void set_cursor_mode(int value) const;
	GLFWwindow* get_window() const;

private:
	static void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	// static void glfw_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	// static void glfw_cursor_pos_callback(GLFWwindow* window, double xoffset, double yoffset);

	Input* input_handler;
	GLFWwindow* window;
};

