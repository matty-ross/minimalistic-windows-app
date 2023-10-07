#include <Windows.h>

#include "Core/Application.hpp"
#include "Core/Window.hpp"


void Start()
{
    Core::Application::GetInstance().RegisterWindowClass();

    {
        Core::Window mainWindow(
            {
                .Name   = "Test",
                .Style  = WS_OVERLAPPEDWINDOW,
                .X      = 100,
                .Y      = 100,
                .Width  = 1280,
                .Height = 720,
            }
        );
        
        mainWindow.Show();
        while (mainWindow.ProcessMessage())
        {
        }
    }

    Core::Application::GetInstance().UnregisterWindowClass();

    ExitProcess(0);
}