#include "Application.hpp"


namespace Core
{
    static constexpr char k_ConfigFilePath[] = ".\\config.ini";


    Application Application::s_Instance;


    Application& Application::GetInstance()
    {
        return s_Instance;
    }
    
    void Application::Initialize()
    {
        Window::RegisterWindowClass();

        int n = 1;
        for (Window& window : m_Windows)
        {
            char windowName[] = "Windows App # ";
            windowName[sizeof(windowName) - 2] = n + '0';
            ++n;
            
            window.Create(Core::WindowParams
                {
                    .Name   = windowName,
                    .Style  = WS_OVERLAPPEDWINDOW,
                    .X      = static_cast<int>(GetPrivateProfileIntA("Window", "X", 100, k_ConfigFilePath)),
                    .Y      = static_cast<int>(GetPrivateProfileIntA("Window", "Y", 100, k_ConfigFilePath)),
                    .Width  = static_cast<int>(GetPrivateProfileIntA("Window", "Width", 1280, k_ConfigFilePath)),
                    .Height = static_cast<int>(GetPrivateProfileIntA("Window", "Height", 720, k_ConfigFilePath)),
                }
            );
        }
    }

    void Application::Shutdown()
    {
        for (Window& window : m_Windows)
        {
            window.Destroy();
        }

        Window::UnregisterWindowClass();
    }

    bool Application::Run()
    {
        bool continueRunning = true;

        MSG msg = {};
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);

            if (msg.message == WM_QUIT)
            {
                continueRunning = false;
                break;
            }
        }

        return continueRunning;
    }
    
    const Window& Application::GetMainWindow() const
    {
        return m_Windows[0];
    }
}