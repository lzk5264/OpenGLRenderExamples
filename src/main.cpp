#include <iostream>
#include "application.h"

int main()
{
    Application app(800, 600, "zeke's OpenGL render samples");

    if (!app.init())
    {
        std::cerr << "Application initialization failed!" << std::endl;
        return -1;
    }
    app.run();
}