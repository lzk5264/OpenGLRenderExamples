#include "renderer.h"
#include <mesh.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::init()
{
    vector<Vertex> vertices(3);
    vertices[0].Position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertices[1].Position = glm::vec3(0.5f, -0.5f, 0.0f);
    vertices[2].Position = glm::vec3(0.0f,  0.5f, 0.0f);
    uint32_t mask = Mesh::POSITION;
    Mesh triangle = Mesh(vertices, {}, {}, mask);
    
}

void Renderer::clear()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render()
{
}
