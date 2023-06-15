# Fonction qui vérifie si la case est valide
def case_valide(plateau, x, y):
    if x >= 0 and x < len(plateau) and y >= 0 and y < len(plateau) and plateau[x][y] == -1:
        return True
    return False


# Fonction qui résout le problème du cavalier
def resoudre_cavalier(n):
    # Initialisation du plateau
    plateau = [[-1 for _ in range(n)] for _ in range(n)]

    # Définition des mouvements du cavalier
    mouvements_x = [2, 1, -1, -2, -2, -1, 1, 2]
    mouvements_y = [1, 2, 2, 1, -1, -2, -2, -1]

    # La case de départ est initialisée à (0, 0)
    plateau[0][0] = 0

    # Empiler les positions de départ
    positions = [(0, 0)]

    # Boucle principale
    while positions:
        # Obtenir les coordonnées de la dernière position dans la pile
        x, y = positions[-1]

        # Rechercher la prochaine case à partir des mouvements possibles
        trouve = False
        for i in range(8):
            prochaine_x = x + mouvements_x[i]
            prochaine_y = y + mouvements_y[i]
            if case_valide(plateau, prochaine_x, prochaine_y):
                plateau[prochaine_x][prochaine_y] = plateau[x][y] + 1
                positions.append((prochaine_x, prochaine_y))
                trouve = True
                break

        # Si une case valide n'est pas trouvée, revenir en arrière
        if not trouve:
            positions.pop()

    # Afficher le plateau
    for ligne in plateau:
        for case in ligne:
            print(str(case).rjust(2), end=" ")
        print()

resoudre_cavalier(20)