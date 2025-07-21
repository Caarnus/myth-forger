#pragma once

#ifdef MYTHFORGER_LINKED
#ifndef MYTHFORGER_ENTRYPOINT_DEFINED
#define MYTHFORGER_ENTRYPOINT_DEFINED
extern MythForger::Application* CreateApplication();

int main(int argc, char *argv[])
{
  auto app = CreateApplication();
  app->Run();
  delete app;
}

#endif
#endif