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
        void RegisterWindowClass();
        void UnregisterWindowClass();

    private:
        inline static Application* s_Instance = nullptr;
    };
}