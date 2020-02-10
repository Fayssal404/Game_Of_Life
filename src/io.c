/*!

    * \file io.c

    * \brief Contient les fonctions responsables de la configuration d'une grille

*/

#include "io.h"


/*!
 * \brief Affiche "|---" un nombre de fois, construite colonne

 * \param[in] c     Entier, nombre de colonne

*/

void affiche_trait (int c){
    int i;
    for (i=0; i<c; ++i) printf ("|---");
    printf("|\n");
    return;
}



/*!
 * \brief Affichage ligne d'une grille
 * Imprime vide si la cellule est mort sinon imprime un 0

 * \param[in] c     Entier, nombre de colonne
 * \param[in] ligne Pointeur, ligne grille
*/


void affiche_ligne (int c, int* ligne){
    int i;
    for (i=0; i<c; ++i)
        if (ligne[i] == 0 ) printf ("|   "); else printf ("| O ");
    printf("|\n");
    return;
}


/*!
 * \brief Affiche d'une grille


 * \param[in] g     Grille

*/


void affiche_grille (grille g){
    int i, l=g.nbl, c=g.nbc;
    printf("\n");
    affiche_trait(c); //Limite supérieur du grille
    for (i=0; i<l; ++i) {
        affiche_ligne(c, g.cellules[i]);
        affiche_trait(c); //Limite inférieur du grille
    }
    printf("\n");
    return;
}


/*!
 * \brief Efface grille

 * \param[in] g Grille

*/

void efface_grille (grille g){
    printf("\n\e[%dA",g.nbl*2 + 5);
}




/**
 * \fn void affiche_information(grille g, int temps)
 * \param g : grille
 * \param temps : int représentant le temps
 * \return : Void, affiche les informations (temps, cyclique, vieillsement)
 */
void affiche_information(grille g, int temps)
{
    printf("\e[1;1H\e[%dC", g.nbc*4 + 3);       //Place le curseur sur le coté droit, ligne 1
    printf("Temps d'évolution : %d", temps);

    printf("\e[1;1H\e[1B\e[%dC", g.nbc*4 + 3);  //Place le curseur sur le coté droit, ligne 2
    if ((compte_voisins_vivants == compte_voisins_vivants_non_cyclique) || (!temps))
        printf("Bords cyclique : OFF");
    else
        printf("Bords cyclique : ON ");

    printf("\e[1;1H\e[2B\e[%dC", g.nbc*4 + 3);  //Place le curseur sur le coté droit, ligne 3
    if ((ptr_fct_cellule_vivante == set_vivante) || (!temps))
        printf("Vieillissement : OFF");
    else
        printf("Vieillissement : ON ");


    printf("\e[1;1H\e[%dB", g.nbl*2+2); //Remet le curseur en bas de grille
    return;
}



/*!
 * \brief Commencer le jeu

 * \param[in] g     Pointeur, une grille
 * \param[in] gc    Pointer, une grille

*/


void debut_jeu(grille *g, grille *gc){
    char c = getchar();
    int temps=1;
    compte_voisins_vivants = compte_voisins_vivants_non_cyclique;
    ptr_fct_cellule_vivante = set_vivante;

    while (c != 'q') // touche 'q' pour quitter
    {
        switch (c)
        {
            case '\n' :
            { // touche "entree" pour évoluer
                printf("\ec");  // => Reset l'écran : Pas d'historique

                evolue(g, gc);

                temps++;

                efface_grille(*g);
                affiche_grille(*g);
                affiche_information(*g, temps);
                printf("\e[0m");
                break;
            }
            case 'n':   // Changer de grille
            {
                char finalName[50]="";
                FILE *pFinalName = NULL;
                pFinalName = fopen(finalName, "r");

                while ( pFinalName==NULL )          //Pour redemander si le fichier n'existe pas
                {
                    scanf("%s", finalName);
                    pFinalName = fopen(finalName, "r");
                        if(pFinalName==NULL)
                            printf("Fichier inexistant. Reesayez:\n");
                }
                fclose (pFinalName);

                libere_grille(g);
                libere_grille(gc);
                init_grille_from_file(finalName ,g);
                alloue_grille (g->nbl, g->nbc, gc);

                affiche_grille(*g);                 //Affiche la grille au temps t=0
                temps=0;
                affiche_information(*g, temps);
                printf("\e[1;1H\e[%dB", g->nbl*2+2);    //Remet le curseur en bas de grille
                getchar();                          //Pour eviter de sauter l'étape 0
                break;
            }
            case 'c':   // Activer/Désactiver le voisinage cyclique
            {
                printf("\e[A\e[2K");    //Efface le c

                if (compte_voisins_vivants == compte_voisins_vivants_non_cyclique)
                    compte_voisins_vivants = compte_voisins_vivants_cyclique;

                else
                    compte_voisins_vivants = compte_voisins_vivants_non_cyclique;

                affiche_information(*g, temps);
                printf("\e[1;1H\e[%dB", g->nbl*2+2);    //Remet le curseur en bas de grille
                getchar();                              //Pour eviter de sauter une étape
                break;
            }
            case 'v':
            {
                printf("\e[A\e[2K");    //Efface le v

                if(ptr_fct_cellule_vivante == set_vivante)
                    ptr_fct_cellule_vivante = set_age;
                else
                    ptr_fct_cellule_vivante = set_vivante;

                affiche_information(*g, temps);
                printf("\e[1;1H\e[%dB", g->nbl*2+2);    //Remet le curseur en bas de grille
                getchar();                              //Pour eviter de sauter une étape
                break;
            }

            case 'o':
            {
                int quit = 1;
                int periode = 1;
                int essai = SEUIL_OSCILLANT;
                int premov = 0;
                grille g2, g3;

                    alloue_grille (g->nbl, g->nbc, &g2);
                    alloue_grille (g->nbl, g->nbc, &g3);
                    copie_grille (*g,g3);
                    copie_grille (*g,g2);

                    while(quit != 0)
                    {
                            while(quit && essai)
                            {
                                evolue(&g2, gc);

                                    if(!egalite(g2,g3))
                                    {
                                        periode++;
                                        essai--;
                                    }
                                    else
                                        quit = 0;
                            }

                        if(quit!=0)
                        {
                            evolue(&g3, gc);
                            copie_grille(g3,g2);
                            premov++;
                            essai = SEUIL_OSCILLANT;
                            periode = 1;
                        }
                    }

                    if(premov == 0)
                    {
                        if(periode>1 && periode<essai)
                            printf("Oscillante de période : %d", periode);
                        else
                        {
                            if(periode == 1)
                                printf("Grille statique");
                            else
                                printf("Non oscillante");
                        }
                    }
                    else
                    {
                        if(periode>1 && periode<essai)
                            printf("Oscillante de période : %d (Dans %d temps)", periode, premov);
                        else
                        {
                            if(periode == 1)
                                printf("Grille statique (Dans %d temps)", premov);
                            else
                                printf("Non oscillante (Dans %d temps)", premov);
                        }
                    }

                    libere_grille(&g2);
                    libere_grille(&g3);

                getchar();
                break;
            }

            default :
            { // touche non traitée
                printf("\n\e[1A");
                break;
            }
        }
        c = getchar();
    }
    return;
}
