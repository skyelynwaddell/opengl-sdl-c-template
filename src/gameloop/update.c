//update.c
#include <stdio.h>
#include <SDL.h>
#include "../headers/defs.h"
#include "../headers/global.h"

void update()
{
    int spd = 50;
    ball.x += spd * delta;
}