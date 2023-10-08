#include <Windows.h>

#include "Core/Application.hpp"
#include "Core/Window.hpp"


void Start()
{
    Core::Application::GetInstance().RegisterWindowClass();

    {
        Core::Window window(
            {
                .Name   = "Windows App",
                .Style  = WS_OVERLAPPEDWINDOW,
                .X      = 100,
                .Y      = 100,
                .Width  = 1280,
                .Height = 720,
            }
        );
        
        window.Show();
        while (window.ProcessMessage())
        {
        }
    }

    Core::Application::GetInstance().UnregisterWindowClass();

    ExitProcess(0);
}