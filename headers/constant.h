#ifndef CONSTANT
    #define CONSTANT

    #include <stdlib.h>
    #include <stdio.h>
    #include <SDL/SDL.h>
    #include <time.h>

    // Map items
    #define EMPTY 0
    #define WALL 1
    #define BOMBE 2
    #define EXPLOSION 3
    #define CHARACTER0 4
    #define CHARACTER1 5
    #define CHARACTER2 6
    #define CHARACTER3 7

    // others
    #define NBR_PLAYERS 2
    #define BOMBE_RANGE 10

    // Size of the Map
    #define BLOCK_SIZE 32
    #define NBR_BLOCK_X 29
    #define NBR_BLOCK_Y 29
    #define SCREEN_WIDTH NBR_BLOCK_X * BLOCK_SIZE
    #define SCREEN_HEIGHT NBR_BLOCK_Y * BLOCK_SIZE

    typedef struct Player
    {
        int id;
        int nbr_boombe;
        SDL_Rect position;
    } Player;

    typedef struct Bombe
    {
        int countdown;
        SDL_Rect position;
    } Bombe;


#endif
