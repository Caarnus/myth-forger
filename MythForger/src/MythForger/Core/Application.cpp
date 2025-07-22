#include <mfpch.h>
#include <MythForger/Core/Application.h>

#include <MythForger/Events/ApplicationEvent.h>

namespace MythForger {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {
    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
        }
    }
}
