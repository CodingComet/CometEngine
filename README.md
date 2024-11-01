# CometEngine

This is an OpenGL based graphics engine and game development framework written in C++20, it uses a custom made [entity component system](https://github.com/CodingComet/ECS).


### Usage

- Download source
- Build projects using CMake
- Link built libraries

Initialize using ```comet_setup()``` glfw should also be initialized if it is used.

Create Window and Input object
```
Input input;
Window win("CometEngine", SCR_WIDTH, SCR_HEIGHT, &input);
```

Main loop
``` 
while (win.is_open()) 
{ logic }
```

ECS usage described in it's own repository.

### Features
- Entity Component System
- Template based uniforms
- Basic rendering functionality
- Main advantage is modern C++ features usage
- Can be added to existing projects, no special entry point or unnecessary fuss

### Dependencies (included in vendor)
- glad
- glfw
- glm
- stb (for image loading)