#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <iostream>
#include "Game.h"
#include "Snake.h"
#include <windows.h>

class SnakeGame : public Game
{
    public:
        SnakeGame();
        virtual ~SnakeGame();

    protected:

    private:
        static const int FPS = 30;
        static const int FRAME_DELAY = 1000/FPS;
        Snake snake;
        SDL_Rect food;

        void run();
        void handleEvents();
        void update();
        void render();
        void clean();
        void createFood();
};

#endif // SNAKEGAME_H
