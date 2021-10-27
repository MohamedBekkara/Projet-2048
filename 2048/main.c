#include <stdio.h>                                                                  // Inclusion des librairies nécessaire à l'execution
#include <stdlib.h>                                                                 // du programme
#include <windows.h>
#include <time.h>
#include "definition.h"



int main(void){

  int plateau[4][4];

  int largeur;
  int hauteur;

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){                                         // Initialisation du plateau
    for( largeur=0 ; largeur<4 ;largeur++ ){
      plateau[largeur][hauteur]=0;
    }
  }


  int plateau2[4][4];

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){
    for( largeur=0 ; largeur<4 ;largeur++ ){
      plateau2[largeur][hauteur]=0;
    }
  }

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);                   // Texte rouge (C) sur fond noir (0)
  printf ("                              -2048-\n");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);                   // Texte blanc (F) sur fond noir (0)

  printf("\n\n");

  printf("Saississez le nombre de joueur\n\n");
  printf("Tapez 1 ou 2;\n\n");

  int nb_j,rep,cpt;

  cpt=0;

  scanf("%d", &nb_j);                                     // Sélection du nombre de joueur

  srand(time(NULL));

  if(nb_j==1){                                                // Si 1 joueur :

    printf("\nVoulez vous charger une partie precedemment sauvegarder ? Tapez 1 pour charger sinon un autre chiffre pour continuer \n");
    scanf("%d",&rep);

    if(rep==1){                                     // Charge la partie précedente.

    chargerpartie(plateau);
    affiche_ligne(plateau);

    int tour;
    int pos=0;

    for(tour=0;tour<10000;tour++){


    for(largeur=0;largeur<4;largeur++){
      for(hauteur=0;hauteur<4;hauteur++){
        if(plateau[largeur][hauteur]!=0){
          cpt++;
        }
      }
    }
              
    if(cpt==16){                             
      
      fin_2(plateau);

      SaisieDirection(plateau);

      fin(plateau);

      for(largeur=0;largeur<4;largeur++){
                  for(hauteur=0;hauteur<4;hauteur++){
                    if(plateau[largeur][hauteur]!=0){
                      cpt++;
                    }  
                      if(cpt!=16){
                        spawn(plateau);
                        affiche_ligne(plateau);
                      }

                      else{
                        affiche_ligne(plateau);
                      }
                
              }
            }
      }

      else{
        SaisieDirection(plateau);
        fin(plateau);
        spawn(plateau);
        affiche_ligne(plateau);
      
      }
      
      
  
  }


}

    
  
  
    if(rep!=1){                         // Crée une nouvelle partie
      int nbgen=rand()%3;
      int nbgen2=rand()%3;

      int nbgen3=rand()%3;
      int nbgen4=rand()%3;

      plateau[nbgen][nbgen2]=2;
      plateau[nbgen3][nbgen4]=2;
    
      affiche_ligne(plateau);
  
      int tour;
      int pos=0;

      for(tour=0;tour<10000;tour++){

        for(largeur=0;largeur<4;largeur++){                   // Compte le nombre de cases remplies 
      for(hauteur=0;hauteur<4;hauteur++){
        if(plateau[largeur][hauteur]!=0){
          cpt++;
        }
      }
    }
              
    if(cpt==16){                                              // Si plateau est plein :
      
      fin_2(plateau);                                         // Vérifie s'il reste des déplacements possibles !

      SaisieDirection(plateau);                               // Demande la saisie d'une direction, ou si le joueur veut sauvegarder sa partie

      fin(plateau);                                           // Vérifie si la partie est gagnée ! (ou non)

      for(largeur=0;largeur<4;largeur++){
          for(hauteur=0;hauteur<4;hauteur++){
              if(plateau[largeur][hauteur]!=0){
                cpt++;
              }                                                         //(Plateau est plein :)
                      
              if(cpt!=16){                                                      // Si le plateau a été libéré :
                spawn(plateau);                                                 // Apparition d'une valeur aléatoire !
                affiche_ligne(plateau);                                         // Affiche le plateau de jeu 
              }

              else{                                                             // Si le plateau n'est pas encore libéré
                affiche_ligne(plateau);                                         // Affiche ce plateau, en vue de s'améliorer au tour suivant !
              }
        }
      }
    }

    else{                                             // Si le plateau n'est pas plein, alors déroulement classique et;
        SaisieDirection(plateau);
        fin(plateau);
        spawn(plateau);                               // Apparition d'une valeur aléatoire
        affiche_ligne(plateau);                        
      
      }

        

      }
    }

  } 

  if(nb_j==2){                                                  // Si 2 joueur :

    int nbgen=rand()%3;     
    int nbgen2=rand()%3;

    int nbgen3=rand()%3;    
    int nbgen4=rand()%3;

    int nbgen5=rand()%3;        
    int nbgen6=rand()%3;

    int nbgen7=rand()%3;    
    int nbgen8=rand()%3;

    plateau[nbgen][nbgen2]=2;
    plateau[nbgen3][nbgen4]=2;

    plateau2[nbgen5][nbgen6]=2;
    plateau2[nbgen7][nbgen8]=2;

    printf("Plateau Joueur 1  ");
    affiche_ligne(plateau);

    printf("Plateau Joueur 2  ");
    affiche_ligne(plateau2);

    int cp;
    int tour;
    int pos=0;

    cp=0;

    for(tour=0;tour<10000;tour++){
        printf("%d \n",tour);
      

      if(cp==0){                                                 // Joueur 1 qui joue ici,

        printf("\nJoueur 1, joue  \n");

        for(largeur=0;largeur<4;largeur++){                     // Compte le nombre de cases remplies
          for(hauteur=0;hauteur<4;hauteur++){
            if(plateau[largeur][hauteur]!=0){
              cpt++;
            }
          }
        }
              
        if(cpt==16){                                             // Si plateau est plein : ( Voir explication pour le module 1 joueur )
      
          fin_2(plateau);

           SaisieDirection(plateau);

         fin(plateau);

          for(largeur=0;largeur<4;largeur++){
                  for(hauteur=0;hauteur<4;hauteur++){
                    if(plateau[largeur][hauteur]!=0){
                      cpt++;
                    }  
                      if(cpt!=16){
                        spawn(plateau);
                        printf("Plateau Joueur 1:\n");
                        affiche_ligne(plateau);
                      }

                      else{
                        printf("Plateau Joueur 1:\n");
                        affiche_ligne(plateau);
                      }
                
              }
            }
      }

      else{                                                 // Si le plateau n'est pas plein, alors déroulement classique et;
        SaisieDirection(plateau);
        fin(plateau);
        spawn(plateau);
        printf("Plateau Joueur 1:\n");
        affiche_ligne(plateau);
      
      }
        
      }

      else{                                                 // Joueur 2 qui joue ici
    

        printf("\nJoueur 2, joue   \n");

       for(largeur=0;largeur<4;largeur++){                  // Compte le nombre de cases remplies
      for(hauteur=0;hauteur<4;hauteur++){
        if(plateau2[largeur][hauteur]!=0){
          cpt++;
        }
      }
    }
              
    if(cpt==16){                                            // Si plateau est plein : ( Voir explication pour le module 1 joueur )
      
      fin_2(plateau2);

      SaisieDirection(plateau2);

      fin(plateau2);

      for(largeur=0;largeur<4;largeur++){
                  for(hauteur=0;hauteur<4;hauteur++){
                    if(plateau2[largeur][hauteur]!=0){
                      cpt++;
                    }  
                      if(cpt!=16){
                        spawn(plateau2);
                        printf("Plateau Joueur 2:\n");
                        affiche_ligne(plateau2);
                      }

                      else{
                        printf("Plateau Joueur 2:\n");
                        affiche_ligne(plateau2);
                      }
                
              }
            }
      }

      else{                                                   // Si le plateau n'est pas plein, alors déroulement classique ;
        SaisieDirection(plateau2);
        fin(plateau2);
        printf("Plateau Joueur 2:\n");
        spawn(plateau2);
        affiche_ligne(plateau2);
      
      }

        
      }
      cp=(cp+1)%2;                                            // Alterne entre les joueurs
    }
  }
}

