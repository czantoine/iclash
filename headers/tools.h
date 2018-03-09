#ifndef TOOLS
    #define TOOLS

    // Fonction qui crée la carte en fonction de la taille
    int** init_map(int size_y, int size_x);

    // crer un tableau avec les coord des joueurs
    Player* init_players(int nbr_player);

    // Fonction pour placer une bombe
    void place_bombe(int **map, SDL_Rect position);


#endif
