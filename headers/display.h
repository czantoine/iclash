#ifndef DISPLAY
    #define DISPLAY

    // affiche la carte
    void display_map(SDL_Surface *screen, int **map);

    // donne a la carte la position des joueurs
    void place_characrters(int **map, Player *players);


#endif
