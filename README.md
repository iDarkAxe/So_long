# 2D Game #
Simple 2D Game, with the goal to make a playable character moving in a map. The map is filled at least by a collectible and an exit. 
The list of maps is in `map` folder. 

# How does it work #
The window of the game should be rendered exactly at the size of the map.
All the textures are modified by HAND (scaled and colored differently) but not 100% made by hand (original textures should be in GIMP project `.xcf` files). 
The textures are inspired by Terraria (player), and Minecraft (exit + collectibles) and by a well known Castle in Versailles (parquet for the floor).


# How to start the game #
Just start it using :
```sh
./so_long <PATH_to_MAP/><MAP>
```
`PATH_to_MAP` is the PATH where is stored the map.

`MAP` is the map file, with the `.ber` extension (other extensions should also work).

# How to play #
The controls of the player are the following :

`UP_ARROW` and `DOWN_ARROW` for vertical movements.

`LEFT_ARROW` and `RIGHT_ARROW` for horizontal movements.

## How to end the game ## 
To finish the game as intended, you need to collect all the `Eye of Ender`. 
When there is nothing left to collect, the Exit portal opens, and all the eyes are inserted in the portal, making the exit working.

If you need to end promptly, you can press `Esc` or the window cross.

---

# Jeu 2D #
Un simple jeu 2D, avec pour objectif de pouvoir jouer avec un personnage déplaçable sur une carte. La carte est remplie d'au moins un objet à collecter et une sortie.
La liste des maps est disponible dans le dossier `map`.

# Comment ça marche ? #
La fenêtre de jeu devrait être rendue exactement à la taille de la map.
Toutes les textures ont été modifiées à la main (mises à l'échelle et colorimétrie modifiée) mais ne sont pas 100% faites main (les textures originales devraient se trouver dans les fichiers projet GIMP en `.xcf`).
Les textures sont inspirées par le jeu Terraria (joueur), Minecraft (sortie et objets à collectionner) ainsi que par le bien-connu Château de Versailles (parquet).

# Comment lancer le jeu ? #
Lancer simplement la commande :
```sh
./so_long <CHEMIN_vers_MAP/><MAP>
```
`CHEMIN_vers_MAP` est le chemin absolu ou relatif vers le dossier de la map choisie.

`MAP` est le fichier de la map, avec une extension en `.ber` (les autres extensions devraient aussi fonctionner).

# Comment jouer au jeu ? #
Les contrôles du joueur sont les suivants :

`FLECHE_HAUT` et `FLECHE_BAS` pour les mouvements verticaux.

`FLECHE_GAUHE` et `FLECHE_DROITE` pour les mouvements horizontaux.

## Comment finir le jeu ? ## 
Pour finir le jeu comme prévu, il est nécessaire de collecter touts les `Yeux de l'Ender`.
Quand il n'y en a plus à ramasser, le Portal de sortie s'ouvre, tous les yeux sont insérés dans le portal, le rendant fonctionnel.

S'il est nécessaire de fermer le jeu, vous pouvez appuyer sur la touche `Échap` ou la croix de la fenêtre.
