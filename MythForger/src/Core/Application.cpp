#include <Core/Application.h>

#include <Events/ApplicationEvent.h>
#include <Logger/Log.h>

namespace MythForger {
    Application::Application() {
    }

    Application::~Application() {
    }

    void Application::Run() {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
            MF_TRACE(e.ToString());
        if (e.IsInCategory(EventCategoryInput))
            MF_TRACE(e.ToString());

        while (true);
    }
}
