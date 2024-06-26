#ifndef SNAKE_H
#define SNAKE_H
#include "SDL2/SDL.h"
#include <vector>

using namespace std;
class Snake
{
    public:
        Snake();
        Snake (int x, int y, SDL_Renderer* r);
        virtual ~Snake();
        static const int BLOCK_WIDTH = 10;
        static const int BLOCK_HEIGHT =10;


        void setDirection(int xD, int yD);
        void update();
        void render();
        bool eating(SDL_Rect food);
        void grow();
        bool frameCollision(int w, int h);
        bool bodyCollision();


    protected:

    private:
        vector<SDL_Rect> body;
        SDL_Renderer* renderer;
        int xDir;
        int yDir;
};

#endif // SNAKE_H
