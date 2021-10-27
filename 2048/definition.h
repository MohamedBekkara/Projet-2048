#ifndef DEFINITION_H
#define DEFINITION_H 
#endif                            // ifn et endif pour eviter une boucle d'inclusion infinie
#include <stdio.h>                                                                  // Inclusion des librairies nécessaire à l'execution
#include <stdlib.h>                                                                 // du programme
#include <windows.h>
#include <time.h>                                                                      // Initialisation du score (variable globale)

#define MAXCARAC 1000                                                               // Maximum de caractère d'une ligne récupérée (Fct chargerpartie)

void deplace_d(int plateau[4][4]);
void deplace_g(int plateau[4][4]);
void deplace_h(int plateau[4][4]);
void deplace_b(int plateau[4][4]);
void affiche_ligne(int plateau[4][4]);
void spawn(int plateau[4][4]);
void entasser_d(int plateau[4][4]);
void deplace_d(int plateau[4][4]);
void entasser_g(int plateau[4][4]);
void deplace_g(int plateau[4][4]);
void entasser_h(int plateau[4][4]);
void deplace_h(int plateau[4][4]);
void entasser_b(int plateau[4][4]);
void deplace_b(int plateau[4][4]);
void sauvegardepartie(int plateau[4][4]);
int chargerpartie(int plateau[4][4]);
char SaisieDirection(int plateau[4][4]);
void fin(int plateau[4][4]);
void fin_2(int plateau[4][4]);

