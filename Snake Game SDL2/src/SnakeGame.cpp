#include "SnakeGame.h"
#include <time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
SnakeGame::SnakeGame()
{
    srand(time(NULL));
    //ctor
    init("SNAKE", 400, 400, false);
    snake = Snake(50, 50, getRenderer());
    createFood();
    run();
}

SnakeGame::~SnakeGame()
{
    //dtor
}
void SnakeGame::run()
{
    unsigned int frameStart;
    unsigned int frameTime;

    while(getIsRunning())
    {
        frameStart = SDL_GetTicks();
        handleEvents();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if(FRAME_DELAY>frameTime)
            SDL_Delay(FRAME_DELAY - frameTime);
    }
    clean();
}

void SnakeGame::handleEvents()
{
SDL_Event event;
SDL_PollEvent(&event);
switch(event.type)
{

case SDL_QUIT:
    setIsRunning(false);
    break;
case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
    {
    case SDLK_UP:
        //std::cout<<"Up"<<std::endl;
        snake.setDirection(0, -1);
        break;
    case SDLK_DOWN:
        //std::cout<<"Down"<<std::endl;
        snake.setDirection(0, 1);
        break;
    case SDLK_LEFT:
        //std::cout<<"Left"<<std::endl;
        snake.setDirection(-1, 0);
        break;
    case SDLK_RIGHT:
        //std::cout<<"Right"<<std::endl;
        snake.setDirection(1, 0);
        break;
    default:
        break;
    }
default:
    break;
}
}

void SnakeGame::update()
{

 if (snake.eating(food))
 {
    char soundfile[] = "F:\COIN.wav";
    cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
    Sleep(20);
    snake.grow();
    createFood();
 }
 snake.update();
 if(snake.frameCollision(getScreenWidth(), getScreenHeight()) || snake.bodyCollision())
{
   char soundfile[] = "F:\DIE.wav";
   cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
   Sleep(800);
   setIsRunning(false);
}


}

void SnakeGame::render()
{
    SDL_RenderClear(getRenderer());
    SDL_SetRenderDrawColor(getRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect(getRenderer(), &food);
;
    snake.render();
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);
    SDL_RenderPresent(getRenderer());
}

void SnakeGame::clean()
{
    SDL_DestroyWindow(getWindow());
    SDL_DestroyRenderer(getRenderer());
    SDL_Quit();
}

void SnakeGame::createFood()
{
    food.x = rand()%(getScreenWidth()/Snake::BLOCK_WIDTH)*Snake::BLOCK_WIDTH;
    food.y = rand()%(getScreenHeight()/Snake::BLOCK_HEIGHT)*Snake::BLOCK_HEIGHT;
    food.w = Snake::BLOCK_WIDTH;
    food.h = Snake::BLOCK_HEIGHT;
}

