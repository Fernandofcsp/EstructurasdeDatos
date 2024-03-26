#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "SDL2/SDL.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void setScreenWidth(int value);
        int getScreenWidth()const;
        void setScreenHeight(int value);
        int getScreenHeight()const;
        void setIsRunning(bool value);
        bool getIsRunning()const;
        void setWindow(SDL_Window* value);
        SDL_Window* getWindow() const;
        void setRenderer(SDL_Renderer* value);
        SDL_Renderer* getRenderer()const;

        void init(const char* title, int w, int h, bool fullScreen);
        virtual void run() = 0;
        virtual void handleEvents() = 0;
        virtual void update() = 0;
        virtual void render () = 0;
        virtual void clean () = 0;
            protected:

    private:
        int screenWidth;
        int screenHeight;
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif // GAME_H
