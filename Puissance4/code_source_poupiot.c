/*
POUPIOT Timéo
1B2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char PION_A = 'O';
const char PION_B = 'X';
const char VIDE = ' ';
const char INCONNU = ' ';
const int PUISSANCE = 4;
const int COL_MIN = 0;
const int COL_MAX = 6;

#define NBLIG 6
#define NBCOL 7
typedef char grille[NBLIG][NBCOL];

const int COLONNE_DEBUT = NBCOL/2;

void afficherTitre();
void initGrille(grille);
void afficher(grille, char, int);
bool grillePleine(grille);
void jouer(grille, char, int*, int*);
int choisirColonne(grille, char, int);
int trouverLigne(grille, int);
bool estVainqueur(grille, int, int);
void finDePartie(char);

int main() {
    char vainqueur;
    int ligne, colonne;
    grille g;

    initGrille(g);
    vainqueur = INCONNU;
    afficherTitre();

    while ((vainqueur==INCONNU) && (grillePleine(g) == false)) {
        jouer(g, PION_A, &ligne, &colonne);
        afficher(g, PION_B, COLONNE_DEBUT);

        if (estVainqueur(g, ligne, colonne) == true) {
            vainqueur = PION_A;
        }
        else if (grillePleine(g) == false) {
            jouer(g, PION_B, &ligne, &colonne);
            afficher(g, PION_A, COLONNE_DEBUT);
            if (estVainqueur(g, ligne, colonne) == true) {
                vainqueur = PION_B;
            }
        }
    }
    finDePartie(vainqueur);
}

void afficherTitre(){
    printf("███ █ █ █ ███ ███ ███ █  █ ███ ███     █\n");
    printf("█ █ █ █ █ █   █   █ █ ██ █ █   █      ██\n");
    printf("███ █ █ █ ███ ███ ███ █ ██ █   ██    █ █\n");
    printf("█   █ █ █   █   █ █ █ █  █ █   █    █████\n");
    printf("█   ███ █ ███ ███ █ █ █  █ ███ ███     █\n");
    printf("\n\n");
}

void initGrille(grille matrice) {
    for (int i=0; i<NBLIG; i++) {
        for (int j=0; j<NBCOL; j++) {
            matrice[i][j] = VIDE;
        }
    }
}

void afficher(grille matrice, char pion, int colonne) {
    printf("\n\n\n");
    printf("  0   1   2   3   4   5   6\n");
    printf("╔═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n");
    for (int i=0; i<5; i++) {
        printf("║ %c ║ %c ║ %c ║ %c ║ %c ║ %c ║ %c ║\n", matrice[i][0], matrice[i][1], matrice[i][2], matrice[i][3], matrice[i][4], matrice[i][5], matrice[i][6]);
        printf("╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    }
    printf("║ %c ║ %c ║ %c ║ %c ║ %c ║ %c ║ %c ║\n", matrice[5][0], matrice[5][1], matrice[5][2], matrice[5][3], matrice[5][4], matrice[5][5], matrice[5][6]);
    printf("╠═══╩═══╩═══╩═══╩═══╩═══╩═══╣\n");
    printf("║                           ║\n");
    printf("╨                           ╨\n");
    printf("\n");
    printf("――――――――――――――――\n   Tour des %c  \n――――――――――――――――\n", pion);
}

bool grillePleine(grille matrice) {
    bool booleen = true;
    for (int i=0; i<NBLIG; i++) {
        for (int j=0; j<NBCOL; j++) {
            if (matrice[i][j] == VIDE) {
                booleen = false;
            }
        }
    }
    return booleen;
}

void jouer(grille matrice, char pion, int *ligne, int *colonne) {
    *colonne = choisirColonne(matrice, pion, *colonne);
    *ligne = trouverLigne(matrice, *colonne);
    matrice[*ligne][*colonne] = pion;
}

int choisirColonne(grille matrice, char pion, int colonne) {
    char touche, surtouche;
    int col = COLONNE_DEBUT;
    
    afficher(matrice, pion, colonne);
    printf("\n");
    
    printf("Colonne actuelle : %d\n", col);
    do {
        printf("Se déplacer ('q', 'd' ou ' ') : ");
        scanf("%c%c", &touche, &surtouche);
    } while (touche != 'd' && touche != 'q' && touche != ' ');
    
    
    while (touche != ' ') {
        if (touche == 'q') {
            if (col > COL_MIN) {
                col--;
            }
            afficher(matrice, pion, col);
            printf("Colonne actuelle : %d\n", col);
        }
        else {
            if (col < COL_MAX) {
                col++;
            }
            afficher(matrice, pion, col);
            printf("Colonne actuelle : %d\n", col);
        }
    do {
        printf("Se déplacer ('q', 'd' ou ' ') : ");
        scanf("%c%c", &touche, &surtouche);
    } while (touche != 'd' && touche != 'q' && touche != ' ');
    } 
    return col;
}

int trouverLigne(grille matrice, int colonne) {
    int i = NBLIG;
    int res = -1;

    while ((i >=0 ) && (matrice[i][colonne] != VIDE)) {
        i=i-1;
    }
    if (matrice[i][colonne] == VIDE) {
        res = i;
        return res;
    }
    else {
        return res;
    }
}

bool estVainqueur(grille matrice, int ligne, int colonne) {
    int compt_col=0;
    int compt_lig=0;
    int compt_diag_hg=0; // Compteur diagonal qui commence en haut à gauche
    int compt_diag_hd=0; // Compteur diagonal qui commence en haut à droite
    int i=0;
    int j=0;
    bool vainqueur = false;

    // Vérification pour la colonne
    while (i<NBLIG) {
        while (matrice[i][colonne] == VIDE){
            i++;
        }
        if (i < NBLIG) {
            if (matrice[i][colonne] == matrice[ligne][colonne]) {
                compt_col++;
                i++;
            }
            else {
                if (compt_col >= PUISSANCE) {
                    vainqueur = true;
                }
                else {
                    compt_col = 0;
                    i++;
                }
            }
        }
    }
    
    // Vérification pour la ligne
    i=0;
    while (i < NBCOL) {
        while (matrice[ligne][i] == VIDE) {
            i++;
        }
        if (i < NBCOL) {
            if (matrice[ligne][i] == matrice[ligne][colonne]) {
                compt_lig++;
                i++;
            }
            else {
                if (compt_lig >= PUISSANCE) {
                    vainqueur = true;
                }
                else {
                    compt_lig = 0;
                    i++;
                }
            }
        }
    }

    // Vérification pour la diagonale HAUT-GAUCHE vers BAS-DROITE
    i=ligne;
    j=colonne;
    while(j>0 && i>0) {
        i--;
        j--;
    }

    while ((i < NBLIG) && (j < NBCOL)) {
        while (matrice[i][j] == VIDE) {
            i++;
            j++;
        } 
        if (matrice[i][j] == matrice[ligne][colonne]) {
            compt_diag_hg++;
            i++;
            j++;
        }
        else {
            if (compt_diag_hg >= PUISSANCE) {
                vainqueur = true;
                printf("gagne en diag hg");
            }
            else {
                compt_diag_hg = 0;
                i++;
                j++;
            }
        }
    }
    
    // Vérification pour la diagonale HAUT-DROITE vers BAS-GAUCHE
    i=ligne;
    j=colonne;
    while(j<NBCOL-1 && i>0) {
        i--;
        j++;
    }

    while ((i < NBLIG) && (j < NBCOL)) {
        while (matrice[i][j] == VIDE) {
            i++;
            j--;
        } 
        if (matrice[i][j] == matrice[ligne][colonne]) {
            compt_diag_hd++;
            i++;
            j--;
        }
        else {
            if (compt_diag_hd >= PUISSANCE) {
                vainqueur = true;
                printf("gagne en diag hd");
            }
            else {
                compt_diag_hd = 0;
                i++;
                j--;
            }
        }
    }

    if (compt_col >= PUISSANCE || compt_lig >= PUISSANCE || compt_diag_hg >= PUISSANCE || compt_diag_hd >= PUISSANCE) {
        vainqueur = true;
    }
    return vainqueur;
}

void finDePartie(char pion) {
    printf("\n\n═══════════════════════════\n    ⋆ GAGNANT : les %c ⋆\n═══════════════════════════", pion);
}