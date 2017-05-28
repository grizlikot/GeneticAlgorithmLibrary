#ifndef WINDOW_H
#define WINDOW_H

#include <string>

    class Window {
    public:
        virtual void setTitle(const std::string title) = 0;
        virtual void setFullscreen(const bool fullscreen) = 0;
        virtual void setSize(const int width, const int height) = 0;
        virtual void setVisible(const bool visible) = 0;
        virtual void pollEvents() = 0;
        virtual bool shouldClose() = 0;
        virtual void destroy() = 0;
        virtual void create() = 0;
        virtual ~Window() {}
    };

#endif