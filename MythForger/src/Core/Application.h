#pragma once
#include "Core.h"

namespace MythForger {
    class MYTHFORGER_API Application {
        public:
            Application();
            virtual ~Application();
            void Run();
            void Print();
    };

    // To be defined in client
    Application* CreateApplication();
}
