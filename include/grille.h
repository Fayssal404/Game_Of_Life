/*!

    * \file grille.h


*/


#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SEUIL_OSCILLANT 500

//! structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules
typedef struct {
    int nbl;
    int nbc;
    int** cellules;} grille;

void alloue_grille(int i, int j, grille* g);

void libere_grille(grille* g);


/*!
 * \brief Alloue et initalise la grille g à partir d'un fichier

 * \param[in] filename  Pointeur, nom fichier
 * \param[in] g         Pointeur, une grille
*/
void init_grille_from_file (char * filename, grille* g);


/*!
 * \brief Rend vivante la cellule (i,j) de la grille g

 * \param[in] i     Entier, indice du ligne d'une cellules
 * \param[in] j     Entier, indice du colonne d'une cellues
 * \param[in] g     Grille
*/
static inline void set_vivante(int i, int j, grille g){
    if (!g.cellules[i][j])      //Si cellule vaut 0, càd cellule morte
        g.cellules[i][j] = 1;   //Evite de remettre l'age d'une cellule à 0 si elle est supérieur que 1
}

/*!
 *\brief Rend morte la cellule (i,j) de la grille g

 * \param[in] i     Entier, indice du ligne d'une cellules
 * \param[in] j     Entier, indice du colonne d'une cellues
 * \param[in] g     Grille
*/
static inline void set_morte(int i, int j, grille g){
    g.cellules[i][j] = 0;}

/*!
 * \brief Teste si la cellule (i,j) de la grille g est vivante

 * \param[in] i     Entier, indice du ligne d'une cellules
 * \param[in] j     Entier, indice du colonne d'une cellues
 * \param[in] g     Grille
*/
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] == 1;}

/*!
 * \brief recopie gs dans gd (sans allocation)

 * \param[in] g     Grille
 * \param[in] gs    Grille
*/
void copie_grille (grille gs, grille gd);



// teste l'égalite entre deux grilles
int egalite(grille gs, grille gd);


/**
 *  \fn static inline void set_age(int i, int j, grille g)
 *  \param i : int
 *  \param j : int
 *  \param g : grille
 *  \return void, mais effet de bord pour augmenter l'age d'une cellule
 */
static inline void set_age(int i, int j, grille g)
{
    if(g.cellules[i][j]<9)
        g.cellules[i][j]++;
    else
        set_morte(i, j, g);
}



/**
 *  \fn static inline void set_non_viable(int i, int j, grille g)
 *  \param i : int
 *  \param j : int
 *  \param g : grille
 *  \return void, mais effet de bord pour rendre une grille non viable
 */
static inline void set_non_viable(int i, int j, grille g){g.cellules[i][j] = -1;}


/**
 * \brief Pointeur de fonction sur set_vivant/set_age
 * \param int : les lignes
 * \param int : les colonnes
 * \param grille : une grille
 * \return void : Effet de bord pour rendre la celule (ligne,colonne) vivante(=1), ou pour augmenter son age(+1)
 */
void (*ptr_fct_cellule_vivante)(int, int, grille);



#endif
