# filler

* Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue
à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent de plus d’une seule case et sans qu’elles ne depassent de la grille.
* Si l’une de
ces conditions n’est pas remplie, la partie s’arrête.
* Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul
joueur, le but du jeu pourrait être d’obtenir le meilleur score possible.
* Chaque joueur a pour but de poser
un maximum de pièces tout en tentant d’empêcher son adversaire de le faire.

* A chaque tour, le joueur actif reçoit l’état de la grille et doit maximiser ses points tout en tentant de
minimiser ceux de l’adversaire en l’éliminant le plus vite possible.
* A la fin de la partie, celui avec le plus de point remporte le match...

# Standard usage

./filler_vm -f [map_path] -p1 [player_1_path] -p2 [player_2_path]
