#include "Game.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}
void Game::setScreenWidth(int value)
{
    screenWidth = value;
}

int Game::getScreenWidth() const
{
    return screenWidth;
}

void Game::setScreenHeight(int value)
{
    screenHeight = value;
}

int Game::getScreenHeight() const
{
    return screenHeight;
}

void Game::setIsRunning(bool value)
{
    isRunning = value;
}

bool Game::getIsRunning() const
{
    return isRunning;
}

void Game::setWindow(SDL_Window* value)
{
    window = value;
}

SDL_Window* Game::getWindow() const
{
    return window;
}

void Game::setRenderer(SDL_Renderer* value)
{
    renderer = value;
}

SDL_Renderer* Game::getRenderer() const
{
    return renderer;
}

void Game::init(const char* title, int w, int h, bool fullScreen)
{
    int flags = 0;
    if (fullScreen)
          flags=SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        screenWidth = w;
        screenHeight = h;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
    renderer= SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        isRunning = true;
    }
    else
    {
        std::cout<<"couldn´t initialize the renderer"<<SDL_GetError();
    }
    }
}


