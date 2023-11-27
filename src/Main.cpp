#include <Windows.h>

#include "Core/Application.hpp"
#include "Core/Window.hpp"


void Start()
{
    static constexpr char k_ConfigFilePath[] = ".\\config.ini";

    Core::Application::GetInstance().RegisterWindowClass();
    {
        Core::Window window(
            Core::WindowParams
            {
                .Name   = "Windows App",
                .Style  = WS_OVERLAPPEDWINDOW,
                .X      = static_cast<int>(GetPrivateProfileIntA("Window", "X", 100, k_ConfigFilePath)),
                .Y      = static_cast<int>(GetPrivateProfileIntA("Window", "Y", 100, k_ConfigFilePath)),
                .Width  = static_cast<int>(GetPrivateProfileIntA("Window", "Width", 1280, k_ConfigFilePath)),
                .Height = static_cast<int>(GetPrivateProfileIntA("Window", "Height", 720, k_ConfigFilePath)),
            }
        );
    }
    Core::Application::GetInstance().UnregisterWindowClass();

    ExitProcess(0);
}