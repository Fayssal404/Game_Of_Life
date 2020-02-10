/**
 *  \file io_cairo.h
 *  \brief Fichier contenant les headers de l'affichage du jeu en mode Graphique
 *  \author Fayssal Abdallah
 *  \date 18/11/2019
 */

#ifndef __IO_CAIRO_H__
#define __IO_CAIRO_H__

#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>  //Version plus récente, pour qu'il reconnait XLookupString
#include "grille.h"
#include "jeu.h"

#define SIZEX 800   //Taille fenêtre
#define SIZEY 800   //Taille fenêtre

#define GRILLEX 100
#define GRILLEY 700

// affichage de la structure de la grille
void grilleAffich(cairo_surface_t *surface, grille g);

// affichage du contenu de la grille
void ligne(cairo_surface_t *surface, grille g);

// debute le jeu
void init_cairo(grille *g, grille *gc);

// affiche les informations (temps, cyclique, viellisement)
void informations_cairo(cairo_surface_t *surface, int temps);

// affiche si la grille est oscillante ou pas
void affichage_oscillante(cairo_surface_t *surface, int periode, int essai, int premov);


#endif
