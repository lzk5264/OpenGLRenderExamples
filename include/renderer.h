#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void init();
    void clear();
    void render();

private:
};