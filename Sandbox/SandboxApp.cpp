#include <MythForger.h>

class Sandbox : public MythForger::Application {
    public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

MythForger::Application* CreateApplication() {
    return new Sandbox();
};
