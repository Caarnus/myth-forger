#pragma once

#ifdef _WIN32
  #ifdef MYTHFORGER_EXPORTS
    #define MYTHFORGER_API __declspec(dllexport)
  #else
    #define MYTHFORGER_API __declspec(dllimport)
  #endif
#else
  #define MYTHFORGER_API
#endif
