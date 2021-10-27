#include <stdio.h>                                                                  // Inclusion des librairies nécessaire à l'execution
#include <stdlib.h>                                                                 // du programme
#include <windows.h>
#include <time.h>
#include "definition.h"

int score =0;
void affiche_ligne(int plateau[4][4]){
  
  int hauteur ;
  int largeur ;
  printf("SCORE : %d", score);                                                      // Affiche le score du joueur !

  printf("\n___________________________\n");
  printf("\n");

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){


    for( largeur=0 ; largeur<4 ;largeur++ ){                    




      switch( plateau[largeur][hauteur] ) {                                         // Affiche la valeur d'une case donnée, en fonction de celle-ci

        case 0 :

          printf("|     |" ) ;
          if(largeur==3){

            printf("\n___________________________\n");
      
          }

        break ;

        case 2 :                                                              

          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);  
          printf("|  2  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("\n___________________________\n");
      
          }

        break ;

        case 4 :

          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);  
          printf("|  4  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break ;

        case 8 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("|  8  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

 

            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break ;

        case 16 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("| 16  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break ;

        case 32 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("| 32  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 64 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
          printf("| 64  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 128 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
          printf("| 128 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 256 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
          printf("| 256 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 512 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
          printf("| 512 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 1024 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
          printf("|1024 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

    

            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 2048 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
          printf("|2048 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

           

            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

      }
  
    }

  }
  
}

void spawn(int plateau[4][4]){

    srand(time(NULL));
    
    int nbgens;
    int nbgene;

    int gener;
    do {                                                        // Cherche une case libre, afin d'y ajouter la valeur '2' ou '4'
      nbgens=rand()%3;
      nbgene=rand()%3;
    }while(plateau[nbgens][nbgene]!=0);
    


    int alea;
	  alea=rand()%2+1;                                            // En fonction de la valeur d'alea :
    int val;                                                    // On aura soit '2' ou '4' dans la case libre crée ci-dessus
	  
    if(alea==1){

		  val=4;
    }

    else{

		  val=2;

    }

    plateau[nbgens][nbgene]=val;
  
}



void entasser_d(int plateau[4][4])
{
	int i,j,z;
	for(j=0;j<4;j++)
	{
		z=3;
		for (i=3;i>=0;i--)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)	
			{
				plateau[z][j]=plateau[i][j];
				if(z>i)
					{plateau[i][j]=0;}
				z--;
			}
	}

}

void deplace_d(int plateau[4][4])
{
	int i,j;
	for(i=3;i>0;i--)
		for(j=0;j<4;j++)
			if(plateau[i][j]==plateau[i-1][j])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i-1][j];        // Fusion des cases égales
				score=score+2*plateau[i-1][j];                      // Augmentation du score
				plateau[i-1][j]=0;
			}
}


void entasser_h(int plateau[4][4])
{
	int i,j,z;
	for (i=0;i<4;i++)
	{
		z=0;
		for(j=0;j<4;j++)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)
			{
				plateau[i][z]=plateau[i][j];
				if(z<j)
					{plateau[i][j]=0;}
				z++;
			}
		}

}

void deplace_h(int plateau[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			if(plateau[i][j]==plateau[i][j+1])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i][j+1];        // Fusion des cases égales
				score=score+2*plateau[i][j+1];                      // Augmentation du score
				plateau[i][j+1]=0;
			}

}


void entasser_b(int plateau[4][4])
{
	int i,j,z;
	for (i=0;i<4;i++)
	{	
		z=3;
		for(j=3;j>=0;j--)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)
			{
				plateau[i][z]=plateau[i][j];
				if(z>j)
					{plateau[i][j]=0;}		
				z--;
			}
	}			

}

void deplace_b(int plateau[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=3;j>0;j--)
			if(plateau[i][j]==plateau[i][j-1])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i][j-1];        // Fusion des cases égales
				score=score+2*plateau[i][j-1];                      // Augmentation du score
				plateau[i][j-1]=0;
			}
}


void entasser_g(int plateau[4][4])
{
	int i,j,z;
	for (j=0;j<4;j++)
	{
		z=0;
		for(i=0;i<4;i++)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)	
			{
				plateau[z][j]=plateau[i][j];
				if(z<i)
					{plateau[i][j]=0;}
				z++;
			}
	}

}

void deplace_g(int plateau[4][4])
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(plateau[i][j]==plateau[i+1][j])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i+1][j];        // Fusion des cases égales
				score=score+2*plateau[i+1][j];                      // Augmentation du score
				plateau[i+1][j]=0;
			}

}




void sauvegardepartie(int plateau[4][4]){

  FILE* ecriture;                               
  char* nomfichier= "test.txt";

  for (int i = 0; i < 4; ++i)                   // On sauvegarde les cases du plateau dans un fichier externe
  {
    for (int j = 0; j < 4; ++j)
    {
      ecriture= fopen(nomfichier,"a");
      fprintf(ecriture,"%d\n",plateau[i][j]);
      fclose(ecriture);
    }
  }
}

int chargerpartie(int plateau[4][4]){

  FILE* lecture;
  char* nomfichier= "test.txt";
  char ligne[MAXCARAC];
  lecture=fopen(nomfichier,"r");
  int i=0;
  int j=0;


     while(fgets(ligne,MAXCARAC,lecture)!= NULL){     // Boucle qui récupère les cases sauvegarder dans la partie précédente

      plateau[i][j] = atoi(ligne);

      if(j==3){

        j=0;
        i=i+1; 
      
      }

      else{

        j=j+1; 
      
      }

     
    } 
    
  fclose(lecture);
  return plateau[i][j]; 
}


char SaisieDirection(int plateau[4][4]){    

  char key;
  printf("choisir la direction \n");
	key=getchar();                        // getchar(), récupère une touche, correspondant à une action
  key=getchar();                        //
	switch (key)                          //Dans chaque cas, on lance les procédures correspondant au caractère donné.
	{
		case 'z':                           // Déplacement haut

      entasser_h(plateau);
			deplace_h(plateau);
      
      break;

		case 's':                           // Déplacement bas

      entasser_b(plateau);
			deplace_b(plateau);

      break;

		case 'q':                           // Déplacement gauche
			
      entasser_g(plateau);
			deplace_g(plateau);
      
      break;

		case 'd':                           // Déplacement droite

      entasser_d(plateau);
			deplace_d(plateau);


      break;
    
    case 'c':                           // Sauvegarde

      sauvegardepartie(plateau);

      break;
	}	
}

void fin(int plateau[4][4]){

  int hauteur;
  int largeur;

  for(largeur=0;largeur<4;largeur++){
    for(hauteur=0;hauteur<4;hauteur++){

      if(plateau[largeur][hauteur]==2048){    // Vérifie la condition que '2048' soit présent sur le plateau 

        affiche_ligne(plateau);

        printf("Gagner !");                   // Si condition est vérifié, partie gagné :)

        exit(0);

      }

    }

  }

}

void fin_2(int plateau[4][4]){
  
  int i,j;

  int ct;

  int a,b;

  int cpt=0;

 
          for(i=0;i<4;i++){
            for(j=0;j<4;j++){

              a=i;
              b=j;

             if(ct==16){                                    // Condition : Si toutes les cases sont bloqués, alors le jeu est perdu
               printf("Perdu!\n");                          // Si toutes les cases bloqués, jeu perdu :(
               exit(0);
             } 

             if(i==0 && j==0){                                                                      // On vérifie si une case est bloquée : En fonction de sa position
                                                                                                    // sur le plateau. Ici, il s'agit de la première case en haut à gauche
              if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b+1]) ){
                ct++;                                                                               // Si la case est bloqué, on la compte comme étant bloqué via le compteur
              }                                                                                     // ct

             } 


            if (i==3 && j==0)  {                                                                    // Même processus

              if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b+1]) ){
                
                ct++;
              }}
              
               
               
            }                   

              if(i==3 && j==3){
                if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b-1]) ){
                  ct++;
                }
              }

            if(i==0 && j==3){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b-1]) ){
                  ct++;
                }
              }
              
            if( (i==3 && j==1) || (i==3 && j==2) ){
                if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a][b+1]) ){
                  ct++;
                }
              }

              if( (i==2 && j==3) || (i==3 && j==3) ){
                if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a+1][b]) ){
                  ct++;
                }
              }  


              if( (i==1 && j==0) || (i==2 && j==0) ){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b+1]) && (plateau[a][b]!=plateau[a-1][b]) ){
                  ct++;
                }
              }

              if( (i==1 && j==3) || (i==2 && j==3) ){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a-1][b]) ){
                  ct++;
                }
              }

              if( (i==1 && j==2) || (i==2 && j==2) || (i==2 && j==1) || (i==1 && j==1) ){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b+1]) ){
                  ct++;
                }
              }


            }
          

}