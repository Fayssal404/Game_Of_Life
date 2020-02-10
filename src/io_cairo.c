 /**
 *  \file io_cairo.c
 *  \brief Fichier contenant les codes pour l'affichage du jeu en mode Graphique
 *  \author Fayssal Abdallah
 *  \date 18/11/2019
 */

#include "io_cairo.h"

/**
 * \fn void grilleAffich(cairo_surface_t *surface, grille g);
 * \param surface : cairo_surface_t (la surface principale)
 * \param g : grille
 * \return Affichage de la structure de la grille
 */
void grilleAffich(cairo_surface_t *surface, grille g)
{
    int i, j;
    double divLigne = (GRILLEY-GRILLEX) / g.nbl;
    double divColon = (GRILLEY-GRILLEX) / g.nbc;

    cairo_t *cr;
    cr = cairo_create(surface);

    cairo_set_source_rgb (cr, 0.3, 0.3, 0.3);
    cairo_set_line_width (cr, 1);

        for (i=GRILLEX; i<=GRILLEY; i+=divColon)
        {
            cairo_move_to (cr, i, GRILLEX);
            cairo_line_to (cr, i, GRILLEY);
        }

        for (j=GRILLEX; j<=GRILLEY; j+=divLigne)
        {
            cairo_move_to (cr, GRILLEX, j);
            cairo_line_to (cr, GRILLEY, j);
        }

    cairo_stroke (cr);
    cairo_destroy(cr);
}

/**
 * \fn void ligne(cairo_surface_t *surface, grille g);
 * \param surface : cairo_surface_t (la surface principale)
 * \param g : grille
 * \return Affiche le contenue de la grille
 */
void ligne(cairo_surface_t *surface, grille g)
{
    cairo_t *cr;
    cr = cairo_create(surface);
    double divLigne = (GRILLEY-GRILLEX) / g.nbl ;   //taille des cellules en lignes
    double divColon = (GRILLEY-GRILLEX) / g.nbc;    //taille des cellules en colonnes
    double ordonnerCells;// = GRILLEX + (divLigne/2.);
    double abscisseCells;// = GRILLEX + (divColon/2.);

    cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 20);

    for(int i=0; i<g.nbl; ++i)
    {
        abscisseCells = GRILLEX+(divColon/2);
        ordonnerCells = GRILLEX+(divLigne/2)*(1+i*2);

        for(int j=0; j<g.nbc; ++j)
        {
            cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);

            if(g.cellules[i][j] == 0)
                cairo_show_text (cr, "");

            else if(g.cellules[i][j] == (-1))
            {
                cairo_set_source_rgb (cr, 0.7, 0.7, 0.7);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "X");
            }

            else if(g.cellules[i][j] == 1)
            {
                cairo_set_source_rgb (cr, 0.9, 0.29, 0.23);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "0");
            }

            else if(g.cellules[i][j] == 2)
            {
                cairo_set_source_rgb (cr, 0.6, 0.34, 0.71);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "1");
            }

            else if(g.cellules[i][j] == 3)
            {
                cairo_set_source_rgb (cr, 0.2, 0.59, 0.85);
                //cairo_show_text (cr, "2");
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "2");

            }

            else if(g.cellules[i][j] == 4)
            {
                cairo_set_source_rgb (cr, 0.1, 0.73, 0.61);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "3");

            }

            else if(g.cellules[i][j] == 5)
            {
                cairo_set_source_rgb (cr, 0.94, 0.76, 0.05);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "4");

            }

            else if(g.cellules[i][j] == 6)
            {
                cairo_set_source_rgb (cr, 0.61, 0.34, 0.03);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "5");

            }

            else if(g.cellules[i][j] == 7)
            {
                cairo_set_source_rgb (cr, 0.6, 0.9, 0);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "6");

            }

            else if(g.cellules[i][j] == 8)
            {
                cairo_set_source_rgb (cr, 0.81, 0.34, 0.83);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "7");

            }

            else if(g.cellules[i][j] == 9)
            {
                cairo_set_source_rgb (cr, 0.8, 0, 0);
                cairo_rectangle (cr, abscisseCells-(divColon/2)+2, ordonnerCells-(divLigne/2)+2, divColon-2, divLigne-2);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_move_to (cr, abscisseCells-6, ordonnerCells+8);
                cairo_show_text (cr, "8");

            }

            abscisseCells += divColon;
        }
    }

    cairo_stroke (cr);
    cairo_destroy(cr);
}


/**
 * \fn void clean(cairo_surface_t *surface);
 * \param surface : cairo_surface_t (la surface principale)
 * \return Effacement du contenu de la fenêtre
 */
void clean(cairo_surface_t *surface)
{
    cairo_t *cr;
    cr = cairo_create(surface);

    cairo_set_source_rgb (cr, 0.15, 0.15, 0.15);
    cairo_paint (cr);

    cairo_stroke (cr);
    cairo_destroy(cr);
}


/**
 * \fn void informations_cairo(cairo_surface_t *surface, int temps);
 * \param surface : cairo_surface_t (la surface principale)
 * \param temps : int (le temps de cycle)
 * \return Affiche les informations (temps, cyclique, vilisement)
 */
void informations_cairo(cairo_surface_t *surface, int temps)
{
    cairo_t *cr;
    cr = cairo_create(surface);

    cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 14);
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_move_to (cr, 370, 20);

    char convert[15] = "";
    sprintf(convert, "Temps : %d", temps);
    cairo_show_text(cr, convert);

    if ((compte_voisins_vivants == compte_voisins_vivants_non_cyclique))
    {
        cairo_move_to (cr, 330, 35);
        cairo_show_text(cr, "Bords cyclique : OFF");
    }
    else
    {
        cairo_move_to (cr, 330, 35);
        cairo_show_text(cr, "Bords cyclique : ON ");
    }

    if ((ptr_fct_cellule_vivante == set_vivante))
    {
        cairo_move_to (cr, 330, 50);
        cairo_show_text(cr, "Vieillissement : OFF");
    }
    else
    {
        cairo_move_to (cr, 330, 50);
        cairo_show_text(cr, "Vieillissement : ON ");
    }
}


/**
 * \fn void affichage_oscillante(cairo_surface_t *surface, int periode, int essai);
 * \param surface : cairo_surface_t (la surface principale)
 * \param periode : int représentant la période d'oscillemnt de la grille
 * \param essai : int representant le seuil max de période (=1000)
 * \return Affiche si la grille est oscillante ou pas (si oui, indique sa période)
 */
void affichage_oscillante(cairo_surface_t *surface, int periode, int essai, int premov)
{

    cairo_t *cr;
    cr = cairo_create(surface);

    cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 14);
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_move_to (cr, 330, 65);

    char convert[SEUIL_OSCILLANT] = "";

    if(premov == 0)
    {
        if(periode>1 && periode<essai)
        {
            sprintf(convert, "Oscillante de période : %d", periode);
            cairo_show_text(cr, convert);
        }
        else
        {
            if(periode == 1)
            {
                cairo_show_text(cr, "Grille statique");
            }
            else
            {
                cairo_show_text(cr, "Non oscillante");
            }
        }
    }
    else
    {
        if(periode>1 && periode<essai)
        {
            sprintf(convert, "Oscillante de période : %d (Dans %d temps)", periode, premov);
            cairo_show_text(cr, convert);
        }
        else
        {
            if(periode == 1)
            {
                sprintf(convert, "Grille statique (Dans %d temps)", premov);
                cairo_show_text(cr, convert);
            }
            else
            {
                sprintf(convert, "Non oscillante (Dans %d temps)", premov);
                cairo_show_text(cr, convert);
            }
        }
    }
}


/**
 * \fn void init_cairo(grille *g, grille *gc);
 * \param g : grille*
 * \param gc : grille*
 * \return Débute le jeu et gère les options
 */
void init_cairo(grille *g, grille *gc)
{
    Display *dpy;
    Window rootwin;
    Window win;
    XEvent e;
    int scr;

    if(!(dpy=XOpenDisplay(NULL)))       // init the display
    {
        fprintf(stderr, "ERROR: Could not open display\n");
        exit(1);
    }

    scr     = DefaultScreen(dpy);
    rootwin = RootWindow(dpy, scr);
    win     = XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0, BlackPixel(dpy, scr), BlackPixel(dpy, scr));

    XStoreName(dpy, win, "Jeu de la vie");
    XSelectInput(dpy, win, ExposureMask|ButtonPressMask|KeyPressMask);
    XMapWindow(dpy, win);

    cairo_surface_t *cs;
    cs = cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);

    compte_voisins_vivants = compte_voisins_vivants_non_cyclique;
    ptr_fct_cellule_vivante = set_vivante;


    char keybuf[8];
    KeySym key;
    int temps = 0;

    while(1)    // run the event loop
    {
        XNextEvent(dpy, &e);

        clean(cs);
        grilleAffich(cs, *g);
        ligne(cs, *g);
        informations_cairo(cs, temps);

        if(e.type==ButtonPress)
        {
            if(e.xbutton.button == 1)   //Clic gauche
            {
                temps++;
                clean(cs);
                evolue(g, gc);
                grilleAffich(cs, *g);
                ligne(cs, *g);
                informations_cairo(cs, temps);
            }
            else                        //Clic droit
            {
                break;
            }
        }

        if(e.type==KeyPress)
        {
            XLookupString(&e.xkey, keybuf, sizeof(keybuf), &key, NULL);
            if(key == 'q')
                break;

            else if(key == 'c')
            {
                if (compte_voisins_vivants == compte_voisins_vivants_non_cyclique)
                    compte_voisins_vivants = compte_voisins_vivants_cyclique;
                else
                    compte_voisins_vivants = compte_voisins_vivants_non_cyclique;

                clean(cs);
                grilleAffich(cs, *g);
                ligne(cs, *g);
                informations_cairo(cs, temps);
            }
            else if(key == 'v')
            {
                if(ptr_fct_cellule_vivante == set_vivante)
                    ptr_fct_cellule_vivante = set_age;
                else
                    ptr_fct_cellule_vivante = set_vivante;

                clean(cs);
                grilleAffich(cs, *g);
                ligne(cs, *g);
                informations_cairo(cs, temps);
            }
            else if(key == 65293)   // <=> '\n'
            {
                temps++;
                clean(cs);
                evolue(g, gc);
                grilleAffich(cs, *g);
                ligne(cs, *g);
                informations_cairo(cs, temps);
            }
            else if(key == 'n')
            {
                temps = 0;
                clean(cs);

                char finalName[50]="";
                FILE *pFinalName = NULL;
                pFinalName = fopen(finalName, "r");

                while ( pFinalName==NULL )          //Pour redemander si le fichier n'existe pas
                {
                    printf("\nEntre la nouvelle grille : \n");
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

                grilleAffich(cs, *g);
                ligne(cs, *g);
                informations_cairo(cs, temps);

            }
            else if(key == 'o')
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

                    affichage_oscillante(cs, periode, essai, premov);

                    libere_grille(&g2);
                    libere_grille(&g3);
            }
        }
    }

    cairo_surface_destroy(cs);
    XCloseDisplay(dpy);
}
