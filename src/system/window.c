//window.c
#include <stdio.h>
#include "../lib/glad/glad.h"
#include <SDL.h>
#include "../headers/defs.h"
#include "../headers/global.h"
#include "../headers/window.h"

SDL_Window* window = NULL;
SDL_GLContext* context = NULL;


int window_init()
{

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //Initialize SDL & Game Window
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return false;
    };

    window = SDL_CreateWindow(
        GAME_TITLE,
        SDL_WINDOWPOS_CENTERED, //window x_pos
        SDL_WINDOWPOS_CENTERED, //window y_pos
        WINDOW_WIDTH, WINDOW_HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    if (!window)
    {
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
        return false;
    }

    SDL_version sdl_compiled_version;
    SDL_VERSION(&sdl_compiled_version);
    printf("SDL Initialized: %d.%d.%d\n", sdl_compiled_version.major, sdl_compiled_version.minor, sdl_compiled_version.patch);

    //Initialize OpenGL

    context = SDL_GL_CreateContext(window);
    if (!context){
        fprintf(stderr, "OpenGL context creation failed: %s\n", SDL_GetError());
        return false;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        fprintf(stderr, "Failed to initialize GLAD.\n");
        return false;
    }
    printf("OpenGL Initialized: %s\n", glGetString(GL_VERSION));

    return true;
}

void window_destroy()
{
    //SDL_DestroyRenderer(renderer);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//sets the current window title
void window_title_set(const char *text)
{
    char title[128];
    snprintf(title, sizeof(title), "%s | %i FPS", text, fps_current());
    SDL_SetWindowTitle(window, title);
}

//validate the SDL window and open GL context are running
int window_is_running(){ 
    if (window == NULL) return false;
    if (context == NULL) return false;

    return true;
}