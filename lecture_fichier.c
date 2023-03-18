#include <stdio.h>
#include <stdlib.h>
#include "utile.h"
#include "lecture_fichier.h"

void ligCol(int *nbLignes, int *nbColonnes, FILE** fichier){
  char *premiereLigne;
  premiereLigne = malloc(sizeof(char)*SIZE);
  fgets(premiereLigne, SIZE, *fichier);
  sscanf(premiereLigne, "%d %d", nbLignes, nbColonnes);
  free(premiereLigne);
}

int **initialiserMatrice(int nbLignes, int nbColonnes){
  int **tab;
  tab = (int**) malloc(sizeof(int*)* nbLignes); // creer le nb de lignes dans le tableau
  for (int i = 0; i < nbLignes; i++){
    tab[i] =  (int*)malloc(sizeof(int)* nbColonnes); // creer le nb de colonnes dans le tableau
    for(int j = 0; j < nbColonnes; j++)
      tab[i][j] = INCONNUE;
  }
  return tab;
}


int **creerBloc(int nb, FILE** fichier){
  // initialisation des variables pour lire le fichier
  int **tab;

  char *chaine;
  chaine = (char*)malloc(sizeof(char)*SIZE);
  char *chaineDeb;
  chaineDeb = chaine;

  int nBlocs;
  int nCourant;
  tab = (int**) malloc(sizeof(int*) * nb); //allocation des lignes du blocs

  for(int i = 0; i<nb; i++){
    fgets(chaine, SIZE, *fichier);
    //printf("%s\n", chaine);
    nBlocs = strtol(chaine, &chaine, 10);
    nCourant = nBlocs;
    tab[i] = (int*)malloc(sizeof(int)*(nBlocs+1)); // allocation pour chaque colonnes

    for(int j = 0; j < nBlocs+1; j++){
      tab[i][j] = nCourant;
      //DEBUG printf("%d\t", tab[i][j]);
      nCourant = strtol(chaine, &chaine, 10);
    }
    //DEBUG printf("\n");
  }
  free(chaineDeb);
  return tab;
}

void freeMatrice(int **tab, int n){
  for(int i = 0; i < n; i++)
    free(tab[i]);
  free(tab);
}

void lecture(int ***tab, int ***blocsLigne, int ***blocsColonne, int *nbLignes, int *nbColonnes, FILE* fichier){
  ligCol(nbLignes, nbColonnes, &fichier);
  *tab = initialiserMatrice(*nbLignes, *nbColonnes);
  *blocsLigne = creerBloc(*nbLignes, &fichier);
  //DEBUG printf("\n \n \n %d", *blocsLigne[0][0]);
  getc(fichier);
  //DEBUG printf("\n");
  *blocsColonne = creerBloc(*nbColonnes, &fichier);
}
