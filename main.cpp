#include <iostream>

int main() {
    // init
    bool game_won = false;
    int players[2] = {1, 2};
    char place[2] = {'X', 'O'};
    int p = 0;
    char colonne = 'Z';
    int col = 0;
    char grid[6][7] = {
        //"A" "B" "C" "D" "E" "F" "G" 
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},        
    };

    // boucle principale
    while (game_won == false){
        
        // fonction de display
        std::cout << "    A   B   C   D   E   F   G \n";
        for (int j = 0; j < 6; ++j){
            std::cout << j+1 << " | ";
            for (int i = 0; i < 7; ++i){
                std::cout << grid[j][i] << " | ";
            }
            std::cout << "\n";
            std::cout << "  -----------------------------\n";
        }
        // end fonction

        round:
        // start gestion des tours des joueurs
        std::cout << "Tour de Player " << players[p%2] << " : \n";
        
        // get colonne
        std::cout << "Choix de la colonne : ";
        std::cin >> colonne;
        colonne = toupper(colonne);

        // verif de la valeur
        while (int(colonne) < 65 || int(colonne) > 71) {
            std::cout << "Choix non valide\n";
            std::cout << "Choix de la colonne : ";
            std::cin >> colonne;
            colonne = toupper(colonne);
        }

        std::cout << "Choix voulu : " << colonne << "\n";
        
        col = int(colonne) - 65;

        // gestion gravité
        for (int i = 5; i >= 0; i--) {
            if (grid[i][col] == ' ') {
                // saisie en fonction du joueur
                if (players[p%2] == 1) {
                    grid[i][col] = place[0];
                } else {
                    grid[i][col] = place[1];
                }
                break;
            } else if (i == 0 ) {
                std::cout << "la colonne est remplie\n";
                goto round;
            }
        }

        // gestion victoire

        // gestion victoire lignes
        int count = 0;
        for (int i = 0; i <= 6; ++i){
            for (int j = 0; j <= 6; ++j){
                if (grid[i][j] == grid[i][j+1] && grid[i][j] == place[p%2]){
                    count ++;
                    if (count >= 3){
                        game_won = true;
                        std::cout << "\n\nPlayer " << players[p%2] << " gagne la partie\n";
                        break;
                    }
                } else {
                    count = 0;
                }
            }
        }

        // gestion victoire colonnes
        count = 0;
        for (int i = 0; i <= 6; ++i){
            for (int j = 0; j <= 6; ++j){
                if (grid[i][j] == grid[i+1][j] && grid[i][j] == place[p%2]){
                    count ++;
                    if (count >= 3){
                        game_won = true;
                        std::cout << "\n\nPlayer " << players[p%2] << " gagne la partie\n";
                        break;
                    }
                }
            }
        }

        // gestion victoire diagonale decroissante
        count = 0;
        for (int i = 1; i <= 5; ++i){
            for (int j = 1; j <= 5 ; ++j){
                if (grid[i][j] == grid[i-1][j-1] && grid[i][j] == place[p%2]){
                    count ++;
                    std::cout << "count decroissant = " << count << "\n";
                    if (count >= 4){
                        game_won = true;
                        std::cout << "\n\nPlayer " << players[p%2] << " gagne la partie\n";
                        break;
                    }
                }else{
                    count = 0;
                }
            }
        }

        // gestion victoire diagonale croissante
        count = 0;
        for (int i = 1; i <= 5; ++i){
            for (int j = 1; j <= 5 ; ++j){
                if (grid[i][j] == grid[i+1][j+1] && grid[i][j] == place[p%2]){
                    count ++;
                    std::cout << "count croissant = " << count << "\n";
                    if (count >= 4){
                        game_won = true;
                        std::cout << "\n\nPlayer " << players[p%2] << " gagne la partie\n";
                        break;
                    }
                }else {
                    count = 0;
                }
            }
        }

        p++;

        std::cout << "\n\ngame_won : " << game_won <<"\n\n";
    }

        // fonction de display
        std::cout << "    A   B   C   D   E   F   G \n";
        for (int j = 0; j < 6; ++j){
            std::cout << j+1 << " | ";
            for (int i = 0; i < 7; ++i){
                std::cout << grid[j][i] << " | ";
            }
            std::cout << "\n";
            std::cout << "  -----------------------------\n";
        }
        // end fonction

    return 0;
}