#ifndef _BALL_H
#define _BALL_H

static const int SPEED = 5;
static const int x_MIN_BOUNDS = 2;
static const int x_MAX_BOUNDS = 780;
static const int y_MIN_BOUNDS = 2;
static const int y_MAX_BOUNDS = 590;

typedef struct Ball 
{
    int x;
    int y;
    int w;
    int h;
    int xDir;
    int yDir;
} Ball;


void ballUpdate(Ball* ball)
{
    if( ball->x < x_MIN_BOUNDS | ball->x > x_MAX_BOUNDS )
    {
        ball->xDir = -ball->xDir;
        printf("x Flip \n");
    }

    if(ball->y < y_MIN_BOUNDS | ball->y > y_MAX_BOUNDS)
    {
        ball->yDir = -ball->yDir;
        printf("y Flip \n");
    }

    ball->x += ball->xDir * SPEED;
    ball->y += ball->yDir * SPEED;
}


#endif  //_GAME_H
