#include <SDL.h>
#include "../headers/defs.h"
#include "../headers/global.h"

int game_is_running = true;
int last_frame_time = 0;
float delta = 0.0;
int should_cap_fps = true;

Ball ball = { .x=20, .y=20, .width=16, .height=16 };

// returns the current fps the game is running at
int fps_current()
{
    return (int)(1.0f / delta);
}

//Limits the frame rate to the #define FPS variable in defs.h
//to be called every game tick
void fps_cap()
{
    if (should_cap_fps == false) 
    {
        return;
    }

    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
}

// Calculates and returns delta time
float delta_calc_time()
{
    // get delta time factor converted to seconds
    delta = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks(); 
    return delta;
}

// Quits the game 
void game_quit()
{
    game_is_running = false;
}