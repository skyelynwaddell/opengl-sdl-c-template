//draw.c
#include <stdio.h>
#include "../lib/glad/glad.h"
#include <SDL.h>
#include "../headers/defs.h"
#include "../headers/window.h"
#include "../headers/global.h"

// Clears the screen drawing frame
void draw_clear()
{
    if (window_is_running() == false) return;

    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //SDL_RenderClear(renderer);
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
    
}

// Called when all the correct objects have been drawn to the screen
void draw_present()
{
    if (window_is_running() == false) return;
    //SDL_RenderPresent(renderer);
}

// Draw Event
void draw()
{
    if (window_is_running() == false) return;
    draw_clear();

    // Your stuff you draw goes below

    //Draws a ball for example
    // SDL_Rect ball_rect = {
    //     (int)ball.x, 
    //     (int)ball.y,
    //     (int)ball.width, 
    //     (int)ball.height
    // };
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderFillRect(renderer, &ball_rect);

    //draw_present();
}