//input.c
#include <stdio.h>
#include <SDL.h>
#include "../headers/defs.h"
#include "../headers/global.h"

void input()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            game_quit();
        break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                game_quit();
            }
        break;
        
        default:break;
    }
}