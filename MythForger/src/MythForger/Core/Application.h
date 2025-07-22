#pragma once
#include "Window.h"
#include "MythForger/Events/ApplicationEvent.h"

namespace MythForger {
    class Application {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
    private:
        bool OnWindowCloseEvent(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client
    Application *CreateApplication();
}
