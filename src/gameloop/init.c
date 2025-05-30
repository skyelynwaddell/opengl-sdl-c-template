//init.c
#include <stdio.h>
#include "../headers/global.h"
#include "../headers/defs.h"

void init()
{
    printf("########## ");
    printf(GAME_TITLE);
    printf(" %.2f", GAME_VERSION);
    printf(" ##########\n");
}