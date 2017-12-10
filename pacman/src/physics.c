#include <stdlib.h>
#include <time.h>
#include "physics.h"
#include "game.h"
#include "map.h"

Direction decideGhost(const Map* map, Ghost* ghost) {
    // fill me

    srand((unsigned int) time(0));
    ghost->dir= (Direction) (rand() % 5);
    if (ghost->dir==0)ghost->dir= (Direction) -1;//set random direction


    //handle possible errors
    if(ghost->dir==DIR_UP)
    {
        if(ghost->y==0&&map->cells[(int)ghost->x][map->height-1]==CELL_BLOCK)decideGhost(map,ghost);
        else if(map->cells[(int)ghost->x][(int)ghost->y-1]==CELL_BLOCK)decideGhost(map,ghost);
    }
    else if(ghost->dir==DIR_DOWN)
    {
        if(ghost->y==map->height-1&&map->cells[(int)ghost->x][0]==CELL_BLOCK)decideGhost(map,ghost);
        else if(map->cells[(int)ghost->x][(int)ghost->y+1]==CELL_BLOCK)decideGhost(map,ghost);
    }
    else if(ghost->dir==DIR_LEFT)
    {
        if(ghost->x==0&&map->cells[map->width-1][(int)ghost->y]==CELL_BLOCK)decideGhost(map,ghost);
        else if(map->cells[(int)ghost->x-1][(int)ghost->y]==CELL_BLOCK)decideGhost(map,ghost);
    }
    else if(ghost->dir==DIR_RIGHT)
    {
        if(ghost->x==map->width-1&&map->cells[0][(int)ghost->y]==CELL_BLOCK)decideGhost(map,ghost);
        else if(map->cells[(int)ghost->x+1][(int)ghost->y]==CELL_BLOCK)decideGhost(map,ghost);
    }

    //handle possible errors


    return ghost->dir;//return ghost move direction


}

Direction decidePacman(const Map* map, Pacman* pacman, Action action) {
    // fill me


    //check all possible conditions
    if(action==ACTION_UP)
    {
        if(pacman->y==0&&map->cells[(int)pacman->x][map->height-1]==CELL_BLOCK)return DIR_NONE;
        else if(map->cells[(int)pacman->x][(int)pacman->y-1]==CELL_BLOCK)return DIR_NONE;
        else return DIR_UP;
    }
    else if(action==ACTION_DOWN)
    {
        if(pacman->y==map->height-1&&map->cells[(int)pacman->x][0]==CELL_BLOCK)return DIR_NONE;
        else if(map->cells[(int)pacman->x][(int)pacman->y+1]==CELL_BLOCK)return DIR_NONE;
        else return DIR_DOWN;
    }
    else if (action==ACTION_LEFT)
    {
        if(pacman->x==0&&map->cells[map->width-1][(int)pacman->y]==CELL_BLOCK)return DIR_NONE;
        else if(map->cells[(int)pacman->x-1][(int)pacman->y]==CELL_BLOCK)DIR_NONE;
        else return DIR_LEFT;
    }
    else if(action==ACTION_RIGHT)
    {
        if(pacman->x==map->width-1&&map->cells[0][(int)pacman->y]==CELL_BLOCK)return DIR_NONE;
        else if(map->cells[(int)pacman->x+1][(int)pacman->y]==CELL_BLOCK)return DIR_NONE;
        else return DIR_RIGHT;
    }
    //check all possible conditions


    /*else if (action==ACTION_PAUSE)
    {

    }
    else if (action==ACTION_IDLE)
    {

    }
    else if (action==ACTION_EXIT)
    {

    }
     */
    return pacman->dir;


}
