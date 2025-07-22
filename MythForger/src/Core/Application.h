#pragma once
#include <Core/Base.h>

namespace MythForger {
    class Application {
        public:
            Application();
            virtual ~Application();
            void Run();
    };

    // To be defined in client
    Application* CreateApplication();
}
