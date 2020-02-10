
/*!
 * \file jeu.h
*/

#ifndef __JEU_H
#define __JEU_H

#include "grille.h"

/*!
 * \brief Modulo modifié
 * Traite correctement les bords i=0 et j=0 dans le calcul des voisins avec bords cycliques

 * \param[in] i     Entier
 * \param[in] m     Entier

 * \return i+m modulo m
*/
static inline int modulo(int i, int m) {return (i+m)%m;}


/*!
 * \brief Compte le nombre de voisins vivants de la cellule (i,j) les bords sont cycliques.

 * \param[in] i     Entier
 * \pram[in] j      Entier
 * \param[in] g     Grille
*/
int compte_voisins_vivants_cyclique (int i, int j, grille g);


// compte le nombre de voisins vivants de la cellule (i,j)
// les bords sont non cycliques.
int compte_voisins_vivants_non_cyclique(int i, int j, grille g);

/*!
 * \brief Fait évoluer la grille g d'un pas de temps

 * \param[in] g     Pointeur, grille
 * \param[in] gc    Pointeur, grille
*/
void evolue (grille *g, grille *gc);


/**
 * \brief Pointeur de fonction vers compte_voisins_vivant_cyclique/non_cyclique
 * \param int : les lignes
 * \param int : les colonnes
 * \param grille : une grille
 * \return int : le nombre de voisin vivant en cyclique ou en non cyclique de la cellule (ligne,colonne)
 */
int (*compte_voisins_vivants)(int, int, grille);

#endif
