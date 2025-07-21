#include <cstdio>
#include <iostream>
#include "Application.h"
#include "../Util/PlatformDetection.h"

namespace MythForger {
    Application::Application() {
    }

    Application::~Application() {
    }

    void Application::Run() {
        while (true);
    }

    void Application::Print() {
        printf("Welcome to MythForger!\n");
        std::cout << "Running on " << MYTH_PLATFORM_NAME << "\n";
    }
}