#include "Window.h"

Window::Window(const char* title, int width, int height, Input* input_handler)
	: input_handler{input_handler}, window{ glfwCreateWindow(width, height, title, NULL, NULL)}
{
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl; // should create proper error reporting
	}

	glfwSetWindowUserPointer(window, this);

	// glfwSetScrollCallback(window, glfw_scroll_callback);
	// glfwSetCursorPosCallback(window, glfw_cursor_pos_callback);

	// input_handler.window = window;
}

GLFWwindow* Window::get_window() const
{
	return window;
}

void Window::glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	Window* user_window = (Window*)glfwGetWindowUserPointer(window);
	user_window->input_handler->keyboard.set_key(key, action);
}

// void Window::glfw_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
// {
// 	Window* user_window = (Window*)glfwGetWindowUserPointer(window);
// 	user_window->input_handler.cursor_scroll.deltas = { xoffset, yoffset };
// }

// void Window::glfw_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
// {
// 	Window* user_window = (Window*)glfwGetWindowUserPointer(window);
// 	user_window->input_handler.mouse_movement.deltas = user_window->input_handler.mouse_movement.pos - glm::dvec2{ xpos, ypos };
// 	user_window->input_handler.mouse_movement.pos = glm::dvec2{ xpos, ypos };
// }


bool Window::is_open() const
{
	return !glfwWindowShouldClose(window);
}

void Window::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::close() const
{
    glfwSetWindowShouldClose(window, true);
}

void Window::set_cursor_mode(int value) const
{
	glfwSetInputMode(window, GLFW_CURSOR, value);
}
