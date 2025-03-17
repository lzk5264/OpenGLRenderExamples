#pragma once
#include "window.h"
#include "renderer.h"

class Application
{
public:
    Application(int width, int height, const std::string &title);
    ~Application();

    bool init();
    void run();

private:
    Window m_window;
    // 成员变量的意思
    Renderer m_renderer;
};