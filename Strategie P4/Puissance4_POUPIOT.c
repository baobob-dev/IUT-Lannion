// POUPIOT Timéo


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// les constantes
#define NB_LIGNES 6
#define NB_COLONNES 7
#define PION_A 'X'
#define PION_B 'O'
#define VIDE ' '
#define INCONNU ' '

// les types
typedef int Grille[NB_LIGNES][NB_COLONNES];

// prototypes des fonctions
void initGrille(Grille laGrille);
void afficher(Grille laGrille, char pion);
bool grillePleine(Grille laGrille);
void jouer(Grille laGrille, char pion, int * ligne, int * colonne);
void faireJouerA(Grille laGrille, char pion, int * ligne, int * colonne);
void faireJouerB(Grille laGrille, char pion, int * ligne, int * colonne);
int choisirColonne(Grille laGrille, char pion);
int choisirColonneStrat1(Grille laGrille);
int choisirColonneStrat2(Grille laGrille);
int chercherLigne(Grille laGrille, int col);
bool estVainqueur(Grille laGrille, int lig, int col);
void finDePartie(char vainqueur);
int aligne3(Grille laGrille, char pion, int line_p, int col_p);
int aligne2(Grille laGrille, char pion, int line_p, int col_p);
int choisirColTim(Grille laGrille);

// Programme principal. C'est le pion A qui commence à jouer
int main()
{
    Grille laGrille;
    char vainqueur=INCONNU;
    int ligne, colonne;
    initGrille(laGrille);
    afficher(laGrille, PION_A);

    while (vainqueur==INCONNU && !grillePleine(laGrille)){
        jouer(laGrille, PION_A, &ligne, &colonne);
        afficher(laGrille, PION_B);

        if (estVainqueur(laGrille, ligne, colonne)){
            vainqueur = PION_A;

        } else if (!grillePleine(laGrille)){
            faireJouerB(laGrille, PION_B, &ligne, &colonne);
            
            afficher(laGrille, PION_A);

            if (estVainqueur(laGrille, ligne, colonne)){
                vainqueur = PION_B;
            }
        }
    }
    finDePartie(vainqueur);
    system(EXIT_SUCCESS);
}


void initGrille(Grille laGrille){
    int l, c;
    for (l=0 ; l<NB_LIGNES ; l++){
        for (c=0 ; c<NB_COLONNES ; c++){
            laGrille[l][c] = VIDE;
        }
    }
}

void afficher(Grille laGrille, char pion){
    int l, c;
    //system("clear");
    printf("\t");
    printf("  %c\n", pion);
    printf("\t");
    for (c=0; c<NB_COLONNES ; c++){
        printf("----");
    }
    printf("-\n");
    for (l=0 ; l<NB_LIGNES ; l++){
        printf("\t");
        for (c=0; c<NB_COLONNES ; c++){
            printf("| %c ", laGrille[l][c]);
        }
        printf("|\n");
        printf("\t");
        for (c=0; c<NB_COLONNES ; c++){
            printf("----");
        }
        printf("-\n");
    }
    printf("\t");
    for (c=0; c<NB_COLONNES ; c++){
            printf("  %d ",c);
    }
    printf("\n\n");

}

bool grillePleine(Grille laGrille){
    bool plein = true;
    int c = 0;
    while (plein && c<NB_COLONNES){
        if (laGrille[0][c] == VIDE){
            plein = false;
        }
        c++;
    }
    return plein;
}

void jouer(Grille laGrille, char pion, int * ligne, int * colonne){
   *ligne = -1;
    do {
        *colonne = choisirColonne(laGrille, pion);
        *ligne = chercherLigne(laGrille, *colonne);
    }while (*ligne==-1);
    laGrille[*ligne][*colonne] = pion;
}

void faireJouerA(Grille laGrille, char pion, int * ligne, int * colonne ){
   *ligne = -1;
    do {
        *colonne = choisirColonneStrat1(laGrille);
        *ligne = chercherLigne(laGrille, *colonne);
    }while (*ligne==-1);
    laGrille[*ligne][*colonne] = pion;
}

void faireJouerB(Grille laGrille, char pion, int * ligne, int * colonne){
   *ligne = -1;

       do {
        *colonne = choisirColTim(laGrille);
        *ligne = chercherLigne(laGrille, *colonne);
    }while (*ligne==-1);
    laGrille[*ligne][*colonne] = pion;
}

int choisirColonne(Grille laGrille, char pion){
    int col;

    do{
        printf("Numero de colonne ? ");
        scanf("%d", &col);
    } while (col<0 ||col>6);
    return col;
}

int chercherLigne(Grille laGrille, int col){
    int ligne = -1;

    while (ligne<NB_LIGNES-1 && laGrille[ligne+1][col]==VIDE){
        ligne++;
    }
    return ligne;
}

bool estVainqueur(Grille laGrille, int lig, int col){
    // consiste à regarder si une ligne de 4 pions s'est formée autour du pion qui vient de tomber en (lig, col)
    char lePion = laGrille[lig][col];
    int cpt,i,j;

    // regarder la verticale, en comptant le nombre de pions au Sud (inutile de regarder au Nord du pion qui vient de tomber)
    i = lig;
    cpt = 0;
    while (i<NB_LIGNES && laGrille[i][col]==lePion){
        cpt++;
        i++;
    }
    if (cpt>=4){
        return true;
    }
    // regarder l'horizontale, en comptant le nombre de pions à l'Est et à l'Ouest
    j = col;
    cpt = 0;
    // on regarde à l'est
    while (j>=0 && laGrille[lig][j]==lePion){
        cpt++;
        j--;
    }
    j = col+1;
    // on regarde à l'ouest
    while (j<NB_COLONNES && laGrille[lig][j]==lePion){
        cpt++;
        j++;
    }
    if (cpt>=4 ){
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Ouest et au Sud Est
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j>=0 && i>=0 && laGrille[i][j]==lePion){
        cpt++;
        i--;
        j--;
    }
    i = lig+1;
    j = col+1;
    // on regarde au Sud Est
    while (i<NB_LIGNES && j<NB_COLONNES && laGrille[i][j]==lePion){
        cpt++;
        i++;
        j++;
    }
    if (cpt>=4 ){
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Est et au Sud Ouest
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j<NB_COLONNES && i>=0 && laGrille[i][j]==lePion){
        cpt++;
        i--;
        j++;
    }
    i = lig+1;
    j = col-1;
    // on regarde au Sud Ouest
    while (i<NB_LIGNES && j<NB_COLONNES && laGrille[i][j]==lePion){
        cpt++;
        i++;
        j--;
    }
    if (cpt>=4 ){
        return true;
    }
    return false;
}

void finDePartie(char vainqueur){
    if (vainqueur != INCONNU){
        printf("Joueur %c vainqueur\n", vainqueur);
    } else {
        printf("MATCH NUL");
    }
}

int choisirColonneStrat1(Grille laGrille) {
    int colonne = 0;
    while (laGrille[0][colonne] != VIDE) {
        colonne++;
    }
    return colonne;
}

// fonction qui vérifie si la case visé et des alignements de 3 autour d'elle et retourne 1 si c'est le cas
int aligne3(Grille lagrille, char pion, int line, int col) {
    int alignement=0;
    int i,j=0;
    int cmpt=0;

    // vérifie un alignement vertical 
    if (line < 3) {
        i = line+1;

        while (cmpt<3 && i<=line+3) {
            if (lagrille[i][col] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;
        }
        if (cmpt == 3) {
            printf("vert");
            alignement = 1;
            
        }        
    }

    cmpt=0;
    // vérifie un alignement horizontal à gauche
    if (col > 2) {
        i = col-1;

        while (cmpt<3 && i>=col-3) {
            if (lagrille[line][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i--;
        }
        if (cmpt == 3) {
            printf("hgauche");
            alignement = 1;
            
        }   
    }

    cmpt=0;
    // vérifie un alignement horizontal à droite
    if (col < 4) {
        i = col+1;

        while (cmpt<3 && i<=col+3) {
            if (lagrille[line][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;       
        }
        if (cmpt == 3) {
            printf("hdroit");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale SUD-OUEST
    if (col > 2 && line < 3) {
        i = col-1;
        j = line+1;
        
        while (cmpt<3 && i>=col-3 && j <= line+3) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i--;
            j++;       
        }
        if (cmpt == 3) {
            printf("dso");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale SUD-EST
    if (col < 4 && line < 3) {
        i = col+1;
        j = line+1;
        
        while (cmpt<3 && i<=col+3 && j <= line+3) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;
            j++;       
        }
        if (cmpt == 3) {
            printf("dse");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale NORD-OUEST
    if (col > 2 && line > 2) {
        i = col-1;
        j = line-1;
        
        while (cmpt<3 && i>=col-3 && j >= line-3) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i--;
            j++;       
        }
        if (cmpt == 3) {
            printf("dno");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale NORD-EST
    if (col < 4 && line > 2) {
        i = col+1;
        j = line-1;
        
        while (cmpt<3 && i<=col+3 && j >= line-3) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;
            j++;       
        }
        if (cmpt == 3) {
            printf("dne");
            alignement = 1;
        }   
    }
    return alignement;
}

// fonction qui vérifie si la case visé et des alignements de 2 autour d'elle et retourne 1 si c'est le cas
int aligne2(Grille lagrille, char pion, int line, int col) {
    int alignement=0;
    int i,j=0;
    int cmpt=0;

    // vérifie un alignement vertical 
    if (line < 4) {
        i = line+1;

        while (cmpt<2 && i<=line+2) {
            if (lagrille[i][col] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;
        }
        if (cmpt == 2) {
            printf("vert");
            alignement = 1;
            
        }        
    }

    cmpt=0;
    // vérifie un alignement horizontal à gauche
    if (col > 1) {
        i = col-1;

        while (cmpt<2 && i>=col-2) {
            if (lagrille[line][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i--;
        }
        if (cmpt == 2) {
            printf("hgauche");
            alignement = 1;
            
        }   
    }

    cmpt=0;
    // vérifie un alignement horizontal à droite
    if (col < 5) {
        i = col+1;

        while (cmpt<2 && i<=col+2) {
            if (lagrille[line][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;       
        }
        if (cmpt == 2) {
            printf("hdroit");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale SUD-OUEST
    if (col > 1 && line < 4) {
        i = col-1;
        j = line+1;
        
        while (cmpt<2 && i>=col-2 && j <= line+2) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i--;
            j++;       
        }
        if (cmpt == 2) {
            printf("dso");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale SUD-EST
    if (col < 5 && line < 4) {
        i = col+1;
        j = line+1;
        
        while (cmpt<2 && i<=col+2 && j <= line+2) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;
            j++;       
        }
        if (cmpt == 2) {
            printf("dse");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale NORD-OUEST
    if (col > 1 && line > 1) {
        i = col-1;
        j = line-1;
        
        while (cmpt<2 && i>=col-2 && j >= line-2) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i--;
            j++;       
        }
        if (cmpt == 2) {
            printf("dno");
            alignement = 1;
        }   
    }

    cmpt=0;
    // vérifie un alignement diagonale NORD-EST
    if (col < 5 && line > 1) {
        i = col+1;
        j = line-1;
        
        while (cmpt<2 && i<=col+2 && j >= line-2) {
            if (lagrille[j][i] == pion) {
                cmpt++;
            }
            else {
                cmpt=0;
            }
            i++;
            j++;       
        }
        if (cmpt == 2) {
            printf("dne");
            alignement = 1;
        }   
    }
    return alignement;
}

int choisirColTim(Grille laGrille) {
    int col = NB_COLONNES/2;
    int start = 0;
    int i = 0;
    int pos_pion[] = {5, 5, 5, 5, 5, 5, 5};
    char monpion = PION_B;
    char sonpion = PION_A;
    int alignement = 0;

    // ####### RECUPERATION DES POSITIONS DES PIONS #######
    for (int pos=0; pos<NB_COLONNES; pos++) {
        pos_pion[pos] = chercherLigne(laGrille, pos);
    }
    
    // ####### COMMENCEMENT DE LA PARTIE #######

    // ---- Recherche si un pion est déjà posé pour savoir qui commence ----
    for (i=0; i<7; i++){
        start = start+pos_pion[i];
    }
    if (start == 35) {
        monpion = PION_A;
        sonpion = PION_B;
        return col;
    }
    else if (start == 34) {
        i=0;
        while (pos_pion[i] == 5) {
            i++;
        }
        return i;
    }

    // ####### NIEME COUPS #######

    // ---- Si 3 pions alliés sont alignés et qu’il y a possibilité de gagner ----
    i=0;

    while (i<7 && alignement==0) {
        alignement = aligne3(laGrille, monpion, pos_pion[i], i);
        i++;
    }
    if (alignement == 1) {
        printf("\n aligne 2 marche mon pion \n");
        return i-1;
    }

    // ---- Si 3 pions adverses sont alignés et qu’il y a possibilité de défendre ----
    i=0;

    while (i<7 && alignement==0) {
        alignement = aligne3(laGrille, sonpion, pos_pion[i], i);
        i++;
    }
    if (alignement == 1) {
        printf("\n aligne 3 marche \n");
        return i-1;
    }
    
     // ---- Si 2 pions adverses sont alignés et qu’il y a possibilité de défendre ----
    i=0;

    while (i<7 && alignement==0) {
        alignement = aligne2(laGrille, sonpion, pos_pion[i], i);
        i++;
    }
    if (alignement == 1) {
        printf("\n aligne 2 marche \n");
        return i-1;
    }

    // ---- Sinon jouer au dessus du dernier pion rouge placé ET non obstrué par un pion adverse par le dessus ----

    i=0;
    bool trouve=false;
    
    while (i<7 && trouve==false){
        if (laGrille[pos_pion[i]-1][i] == monpion) {
            return i;
        }
        i++;
    }

    // ---- Sinon jouer à la première colonne ou encore a droite ----
    if (i==7){
        col = 0;
        while (pos_pion[col] < 0) {
            col++;
        }
        printf("derniere possibilité");
        return col;
    }
}