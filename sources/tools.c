#include "../headers/constant.h"

int** init_map(int size_y, int size_x)
{
    int i, j;
    int **map = (int**) malloc(size_y * sizeof(int*));

    for (i = 0; i < size_y; i++)
    {
        map[i] = (int*) malloc(size_x * sizeof(int));
        for (j = 0; j < size_x; j++)
        {
            if(i == 0 || j == 0 || i == size_y - 1 || j == size_x - 1)
            {
                map[i][j] = WALL;
            }
            else if(i % 2 == 0 && j % 2 == 0)
            {
                map[i][j] = WALL;
            }
            else
            {
                map[i][j] = EMPTY;
            }
        }
    }

    return map;
}

Player* init_players(int nbr_player)
{
    int i, x, y;
    Player *players = (Player*) malloc(nbr_player * sizeof(Player));

    for(i = 0; i < nbr_player; i++)
    {
        players[i].id = i;
        do
        {
            x = rand() % NBR_BLOCK_X;
            y = rand() % NBR_BLOCK_Y;
        } while(x % 2 == 0 || y % 2 == 0 || x == 0 || y == 0);

        players[i].position.x = x;
        players[i].position.y = y;

    }

    return players;
}

void place_bombe(int **map, SDL_Rect position) // Le joueur place une bombe juste devant lui
{
    map[position.y][position.x] = BOMBE;
}
