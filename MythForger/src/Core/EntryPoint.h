#pragma once

#ifdef MYTHFORGER_LINKED
#ifndef MYTHFORGER_ENTRYPOINT_DEFINED
#define MYTHFORGER_ENTRYPOINT_DEFINED
extern MythForger::Application* CreateApplication();

int main(int argc, char *argv[])
{
  //TODO: Move to system startup routine
  MythForger::Log::Init();
  MF_CORE_WARN("Core Logger");
  int a = 5;
  MF_INFO("Client Logger: {0}", a);

  auto app = CreateApplication();
  app->Run();
  delete app;
}

#endif
#endif