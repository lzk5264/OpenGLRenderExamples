#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
    Window(int width, int height, const std::string &title);
    ~Window();

    bool init();
    bool shouldClose();
    void swapBuffers();
    void pollEvents();
    void processInput();
    GLFWwindow *getHandle() { return m_window; }

private:
    int m_width;
    int m_height;
    std::string m_title;
    GLFWwindow *m_window;

    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
};