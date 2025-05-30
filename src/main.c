//main.c
#include <stdio.h>
#include <SDL.h>
#include "./headers/defs.h"
#include "./headers/global.h"
#include "./headers/window.h"

#include "./headers/init.h"
#include "./headers/input.h"
#include "./headers/update.h"
#include "./headers/draw.h"

void game_loop()
{
    input();
    delta_calc_time();
    update();
    draw();

    window_title_set(GAME_TITLE);
    fps_cap();
}

int main(int argc, char *argv[])
{
    printf("Starting engine...\n");
    game_is_running = window_init(); //create the game window

    if (game_is_running == false)
    {
        fprintf(stderr, "Window init failed.");
        return 1;
    }

    init(); //initialize game settings

    while(game_is_running) game_loop(); //main game loop

    //program was terminated
    window_destroy();
    return 0;
}