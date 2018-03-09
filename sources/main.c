#include "../headers/constant.h"
#include "../headers/tools.h"
#include "../headers/display.h"

void pause();

int main(int argc, char *argv[])
{
    int i, j;
    srand(time(NULL));

    SDL_Surface *screen = NULL; // principal screen
    SDL_Rect pos;
    pos.x = 7;
    pos.y = 7;

    int **map = init_map(NBR_BLOCK_Y, NBR_BLOCK_X);
    Player *players = init_players(NBR_PLAYERS);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Bomberman", NULL);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // main window init

    if (screen == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    place_characrters(map, players);
    place_bombe(map, pos);
    display_map(screen, map);



    SDL_Flip(screen); // Mise à jour de l'écran avec sa nouvelle couleur

    pause(); // pause de l'ecran

    // Liberation de la memoire
    for(i = 0; i < NBR_BLOCK_Y; i++)
        free(map[i]);
    free(map);
    SDL_Quit();
    return 0;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    continuer = 0;
                break;
        }
    }
}
