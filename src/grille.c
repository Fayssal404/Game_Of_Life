#include "grille.h"

/*!

 * \file grille.c
*/


/*!
 * \brief Lire un fichier contenant les informations d'une grille, et alloue une nouvelle grille contenant ces informations

 * \param[in] filename  Pointeur, nom du fichier
 * \param[in] g         Pointeur, une grille
*/

void init_grille_from_file (char * filename, grille* g){
    FILE * pfile = NULL;
    pfile = fopen(filename, "r"); //Lire un fichier
    assert (pfile != NULL); //Evalue si le fichier est vide, affiche un message

    int i,j,n,l,c,vivantes=0;

    fscanf(pfile, "%d", & l); //Lire ligne d'un fichier
    fscanf(pfile, "%d", & c); //Lire colonne d'un fichier

    alloue_grille(l,c,g); //Alloue une grille l*c

    fscanf(pfile, "%d", & vivantes);
    for (n=0; n< vivantes; ++n){
        fscanf(pfile, "%d", & i);
        fscanf(pfile, "%d", & j);
        set_vivante(i,j,*g); //Celulle[i][j] est vivant
    }

    fclose (pfile); //Ferme fichier
    return;
}


/*!
 * \brief Copie les données d'une grille g dans une nouvelle grille gs

 * \param[in] gs    Grille, grille à copier
 * \param[in] gd    Grille, copie d'une grille
*/

void copie_grille (grille gs, grille gd){
    int i, j;
    for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
    return;
}


/*!
 * \brief Alloue une grille de taille l*c, et initialise toutes les cellules à mortes

 * \param[in] l     Entier, nombre des lignes
 * \param[in] c     Entier, nombre des colonnes
 * \param[in] g     Pointeur, une grille
*/
void alloue_grille (int l, int c, grille* g){
    //Crée une grille
    (*g).nbl = l;
    (*g).nbc = c;
    (*g).cellules = malloc(c * sizeof (int*)); //Allouer memoire
    for(int i=0; i<c; i++){ //Iterer les collonnes
        (*g).cellules[i] = calloc(1, sizeof(int));
    }

}





/*
 * \fn int egalite(grille gs, grille gd);
 * \param gs grille
 * \param gd grille
 * \return Teste l'égalite entre deux grilles (1:Egale ; 0:Non Egale)
 */
int egalite(grille gs, grille gd)
{
    int i, j;
    int result = 0;

    for (i=0; i<gs.nbl; ++i)
        for (j=0; j<gs.nbc; ++j)
            result += (gd.cellules[i][j]==gs.cellules[i][j]) ? 1 : 0;

    return (result==gs.nbl*gs.nbc) ? 1 : 0;
}
















/*:
 * \brief Libère une grille

 * \param[in] g     Pointeur, une grille
*/
void libere_grille (grille* g){
    for (int i=0; i < (*g).nbc; i++) //Iterer les colonnes
    {
        free((*g).cellules[i]);
    }
    free((*g).cellules);
    free(g);
}
