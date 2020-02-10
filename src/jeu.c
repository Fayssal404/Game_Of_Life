/*!
 * \file jeu.c
*/

#include "jeu.h"


/*!
 * \brief


 * \param[in] i     Entier, Indice ligne du cellule
 * \param[in] j     Entier, Indice Colonne du cellule
 * \param[g] g      Grille

 * \return Nombre des vivant autour du cellule[i][j]
*/
int compte_voisins_vivants_cyclique (int i, int j, grille g){
    int v = 0, l=g.nbl, c = g.nbc;
    v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
    v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
    v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
    v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
    v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
    v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
    v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
    v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

    return v;
}


/**
 * \fn int compte_voisins_vivants_non_cyclique (int i, int j, grille g);
 * \param i : position i
 * \param j : position j
 * \param g : grille
 * \return Compte le nombre de voisins vivants de la cellule (i,j) avec bords non cycliques
 */
int compte_voisins_vivants_non_cyclique(int i, int j, grille g)
{
    int v = 0;
    int l = g.nbl;
    int c = g.nbc;


        if((i-1)>=0 && (j-1)>=0 && est_vivante(i-1, j-1, g))
            v++;
        if((i-1)>=0 && est_vivante(i-1, j, g))
            v++;
        if((i-1)>=0 && (j+1)<c && est_vivante(i-1, j+1, g))
            v++;
        if((j-1)>=0 && est_vivante(i, j-1, g))
            v++;
        if((j+1)<c && est_vivante(i, j+1, g))
            v++;
        if((i+1)<l && (j-1)>=0 && est_vivante(i+1, j-1, g))
            v++;
        if((i+1)<l && est_vivante(i+1, j, g))
            v++;
        if((i+1)<l && (j+1)<c && est_vivante(i+1, j+1, g))
            v++;

    return v;
}


/**
 * \fn evolue (grille *g, grille *gc)
 * \param g : grille
 * \param gc : grille
 * \return Fait évoluer la grille g d'une étape de temps
 */
void evolue (grille *g, grille *gc)
{
    copie_grille (*g,*gc); // copie temporaire de la grille
    int i, j, v;
    int l = g->nbl;
    int c = g->nbc;

    for (i=0; i<l; i++)
    {
        for (j=0; j<c; ++j)
        {
            v = (*compte_voisins_vivants)(i, j, *gc);

            if (est_vivante(i,j,*g))    // evolution d'une cellule vivante
            {
                ptr_fct_cellule_vivante(i, j, *g);
                if ( v!=2 && v!= 3 ) set_morte(i,j,*g);
            }
            else                        // evolution d'une cellule morte
            {
                if ( v==3 ) set_vivante(i,j,*g);
            }
        }
    }
    return;
}
