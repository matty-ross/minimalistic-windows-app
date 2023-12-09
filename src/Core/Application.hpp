#pragma once


#include <Windows.h>

#include "Window.hpp"


namespace Core
{
    class Application
    {
    private:
        Application() = default;
        ~Application() = default;

    public:
        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator =(const Application&) = delete;
        Application& operator =(Application&&) = delete;

    public:
        static Application& GetInstance();

    public:
        void Initialize();
        void Shutdown();
        bool Run();

        const Window& GetMainWindow() const;

    private:
        static Application s_Instance;

    private:
        Window m_Windows[5];
    };
}