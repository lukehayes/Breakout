#ifndef _GAME_H
#define _GAME_H


typedef struct Game 
{
    int width;
    int height;
    const char* title;

} Game;


void gameInit(Game* game)
{
    game->width = 800;
    game->height = 600;
    game->title = "Pong";
}


#endif  //_GAME_H
