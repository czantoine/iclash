#include "../headers/constant.h"

void display_map(SDL_Surface *screen, int **map)
{
    int i, j;
    SDL_Rect position;
    SDL_Surface *ground = NULL, *wall = NULL, *bombe = NULL, *explosion = NULL; // Sprites

    SDL_Surface *perso1 = NULL, *perso2 = NULL;


    ground = SDL_LoadBMP("images/ground.bmp");
    wall = SDL_LoadBMP("images/wall.bmp");
    bombe = SDL_LoadBMP("images/bombe.bmp");
    explosion = SDL_LoadBMP("images/explosion.bmp");

    perso1 = SDL_LoadBMP("images/perso1.bmp");
    perso2 = SDL_LoadBMP("images/perso2.bmp");

    for(i = 0; i < NBR_BLOCK_Y; i++)
    {
        for(j = 0; j < NBR_BLOCK_X; j++)
        {
            position.x = j * BLOCK_SIZE;
            position.y = i * BLOCK_SIZE;

            switch(map[i][j])
            {
                case EMPTY:
                    SDL_BlitSurface(ground, NULL, screen, &position);
                    break;
                case WALL:
                    SDL_BlitSurface(wall, NULL, screen, &position);
                    break;
                case BOMBE:
                    SDL_BlitSurface(bombe, NULL, screen, &position);
                    break;
                case EXPLOSION:
                    SDL_BlitSurface(explosion, NULL, screen, &position);
                    break;
                case CHARACTER0:
                    SDL_BlitSurface(perso1, NULL, screen, &position);
                    break;
                case CHARACTER1:
                    SDL_BlitSurface(perso2, NULL, screen, &position);
                    break;

            }
        }
    }

    SDL_Flip(screen);

    SDL_FreeSurface(ground);
    SDL_FreeSurface(wall);
    SDL_FreeSurface(bombe);
    SDL_FreeSurface(explosion);
    SDL_FreeSurface(perso1);
    SDL_FreeSurface(perso2);
}


void place_characrters(int **map, Player *players)
{
    int i;
    for(i = 0; i < NBR_PLAYERS; i++)
    {
        map[players[i].position.y][players[i].position.x] = i +4;
    }
}
