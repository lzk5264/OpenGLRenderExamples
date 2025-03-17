#include "application.h"

Application::Application(int width, int height, const std::string &title)
    : m_window(width, height, title)
{
}

Application::~Application()
{
}

bool Application::init()
{
    if (!m_window.init())
    {
        return false;
    }
    m_renderer.init();
    return true;
}

void Application::run()
{
    while (!m_window.shouldClose())
    {
        m_window.processInput();
        m_renderer.clear();
        m_renderer.render();
        m_window.swapBuffers();
        m_window.pollEvents();
    }
}
