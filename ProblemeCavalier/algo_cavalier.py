dimensions = input("Nombre de lignes et de colonnes séparé par un espace : ").split(" ")
position_pion = input("Position du pion (ligne colonne) : ").split(" ")

NB_LIGNES = int(dimensions[0])
NB_COLONNES = int(dimensions[1])
NB_CASES = NB_COLONNES * NB_LIGNES  # Nombre de cases de la grille


def afficher_graphe(graphe):  # Affiche le graphe
    for key in graphe:
        print(key, ":", graphe[key])


def init_grille():  # Création de la grille selon les dimensions
    return [[0 for colonne in range(NB_COLONNES)] for ligne in range(NB_LIGNES)]


def init_case(case):  # Retourne la liste des cases voisines d'une case
    ligne, colonne = case
    liste_case_voisines = []
    mouv_cavalier = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]  # (ligne, colonne)

    for l_mouv, c_mouv in mouv_cavalier:
        if 0 <= colonne + c_mouv < NB_COLONNES and 0 <= ligne + l_mouv < NB_LIGNES:
            liste_case_voisines.append((ligne + l_mouv, colonne + c_mouv))

    return liste_case_voisines


def init_graphe():  # Création du graphe des cases et de leurs voisins
    graphe_voisin = {}

    for ligne in range(NB_LIGNES):
        for colonne in range(NB_COLONNES):
            graphe_voisin[(ligne, colonne)] = init_case((ligne, colonne))

    return graphe_voisin


def parcours_cavalier(pos_init, chemin, graphe, grille):
    grille[pos_init[0]][pos_init[1]] = 1  # On marque la case initiale comme visitée

    if len(chemin) == NB_CASES:  # Si le nombre de cases parcourues est égal au nombre de cases de la grille
        print("Chemin trouvé !")
        return chemin

    liste_nb_voisins = []
    for pos_voisin in graphe[pos_init]:
        if grille[pos_voisin[0]][pos_voisin[1]] == 0:
            liste_nb_voisins.append((pos_voisin, len(graphe[pos_voisin])))  # (case, nb cases voisines disponibles)

    liste_nb_voisins.sort(key=lambda x: x[1])  # On trie la liste en fonction du nombre de cases disponibles

    for pos_voisin, _ in liste_nb_voisins:  # Pour chaque case, on vérifie si un chemin est possible
        chemin.append(pos_voisin)
        grille[pos_voisin[0]][pos_voisin[1]] = 1

        resultat = parcours_cavalier(pos_voisin, chemin, graphe, grille)
        if resultat:
            return resultat

        chemin.pop()  # Sinon, on supprime la case de la liste et on continue
        grille[pos_voisin[0]][pos_voisin[1]] = 0

    return []


def main():
    graphe_cavalier = init_graphe()
    grille_cavalier = init_grille()

    x, y = int(position_pion[0]), int(position_pion[1])

    print(parcours_cavalier((x, y), [(x, y)], graphe_cavalier, grille_cavalier))


main()
