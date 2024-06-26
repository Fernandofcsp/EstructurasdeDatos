#include "Snake.h"



Snake::Snake()
{
    //ctor
}

Snake::~Snake()
{
    //dtor
}
Snake::Snake(int x, int y, SDL_Renderer* r)
{
    SDL_Rect head;
    renderer = r;
    head.x = x;
    head.y = y;
    head.w = BLOCK_WIDTH;
    head.h = BLOCK_HEIGHT;
    xDir = 0;
    yDir = 0;

    body.push_back(head);
}

void Snake::setDirection(int xD, int yD)
{
    xDir = xD;
    yDir = yD;
}

void Snake::update()
{
    SDL_Rect head = body.front();
    SDL_Rect tail = body.back();
    tail.x = head.x + xDir * BLOCK_WIDTH;
    tail.y = head.y + yDir * BLOCK_HEIGHT;
    tail.w = BLOCK_WIDTH;
    tail.h = BLOCK_HEIGHT;

    body.insert(body.begin(), tail);
    body.erase(body.end()-1);
}

void Snake::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
     // habilitar c++11 para que funcione
    for (SDL_Rect r : body)
    SDL_RenderFillRect(renderer, &r);

    //for (int i(0); i < body.size(); ++i)
        //SDL_RenderFillRect(renderer, &body[i]);
        //metodo normal

}

bool Snake::eating(SDL_Rect food)
{
    SDL_Rect head = body.front();
    return(head.x ==food.x && head.y == food.y);
}

void Snake::grow()
{
    SDL_Rect tail = body.back();
    body.push_back(tail);
}

bool Snake::frameCollision(int w, int h)
{
    SDL_Rect head = body.front();
    return(head.x >= w || head.x < 0 || head.y >=h || head.y < 0);
}

bool Snake::bodyCollision()
{
    SDL_Rect head = body.front();
    for (int i(1); i< body.size(); ++i)
        if (head.x == body[i].x && head.y == body[i].y)
        return true;
    return false;
}
