/*!
 * \file main.c

 * \version 2.0
 * \date 13/10/2019
 * \author Fayssal Abdallah
*/

#include <stdio.h>

#include "grille.h"
#include "io.h"
#include "jeu.h"

#ifdef TEXTE
#include "io.h"
#else
#include "io_cairo.h"
#endif

/*!
 * \mainpage Jeu de Vie: Un automate cellulaire défini en 1970 par John Conway
* \content L’univers est défini sur une grille à deux dimensions, de taille variable, où chaque case est une cellule pouvant prendre deux états différents : morte ou
vivante.
*/


int main (int argc, char ** argv) {

    if (argc != 2 )
    {
        printf("usage : main <fichier grille>");
        return 1;
    }


    grille g, gc;
    init_grille_from_file(argv[1],&g);
    alloue_grille (g.nbl, g.nbc, &gc);

#ifdef TEXTE
    affiche_grille(g);
    affiche_information(g, 0);
    debut_jeu(&g, &gc);
else
    init_cairo(&g,&gc);
#endif
    libere_grille(&g);
    libere_grille(&gc);
    return 0;
}
