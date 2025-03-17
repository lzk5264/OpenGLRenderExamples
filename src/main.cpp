#include <iostream>
#include "../include/application.h"

int main()
{
    Application app(800, 600, "zeke's OpenGLRenderExamples");

    if (!app.init())
    {
        std::cerr << "Application initialization failed!" << std::endl;
        return -1;
    }
    app.run();
}