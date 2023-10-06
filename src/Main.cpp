#include <Windows.h>

#include "Core/Application.hpp"


void Start()
{
    Core::Application::GetInstance().RegisterWindowClass();
    Core::Application::GetInstance().UnregisterWindowClass();

    ExitProcess(0);
}