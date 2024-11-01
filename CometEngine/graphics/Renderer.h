#include <glad/glad.h>
#include <GLM/glm.hpp>

class Renderer
{
public:
    Renderer(GLADloadproc load);
    ~Renderer() = default;

    void set_clear_color(const glm::vec3& color);
    void clear();
private:
};

