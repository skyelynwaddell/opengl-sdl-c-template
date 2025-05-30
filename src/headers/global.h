#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct {
    float x;
    float y;
    float width;
    float height;
} Ball;
extern Ball ball;

extern int game_is_running;
extern int last_frame_time;
extern float delta;
extern int cap_fps;

float delta_calc_time();
void game_quit(); 
int fps_current();
void fps_cap();

#endif