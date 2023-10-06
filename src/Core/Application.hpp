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
        void RegisterWindowClass() const;
        void UnregisterWindowClass() const;
        const char* GetWindowClassName() const;

    private:
        inline static Application* s_Instance = nullptr;
    };
}