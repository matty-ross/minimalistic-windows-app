#include <Windows.h>

#include "Core/Application.hpp"


void Start()
{
    Core::Application::GetInstance().Initialize();
    while (Core::Application::GetInstance().Run());
    Core::Application::GetInstance().Shutdown();

    ExitProcess(0);
}