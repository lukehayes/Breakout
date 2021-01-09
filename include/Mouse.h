#ifndef _MOUSE_H
#define _MOUSE_H


typedef struct Mouse 
{
    int x;
    int y;
} Mouse;


void mouseUpdate(Mouse* mouse, int x, int y)
{
    mouse->x = x;
    mouse->y = y;
}


#endif  //_GAME_H
