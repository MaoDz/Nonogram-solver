#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "lecture_fichier.h"
#include "resolution.h"
#include "utile.h"

bool estComplet(int **tab, int nbLignes, int nbColonnes){
  for(int i = 0; i < nbLignes; i++){
    for(int j = 0; j < nbColonnes; j++)
      if(tab[i][j] == INCONNUE)
        return false;
  }
  return true;
}

int test_1(int **tab, int **blocsLigne, int **blocsColonne, int nbLignes, int nbColonnes){
  bool test_ligne, test_colonne;
  int k =0;
  do{
    for(int i = 0; i < nbLignes; i++){
      test_ligne = colorationLigne(tab, nbLignes, i, blocsLigne);
      if(test_ligne == 0)
        return false;
    }
    for(int j = 0; j < nbColonnes; j++){
      test_colonne = colorationColonne(tab, nbColonnes, j, blocsColonne);
      if(test_colonne == 0)
        return false;
    }
  }while(k++ != 20);
  if(estComplet(tab, nbLignes, nbColonnes))
    return true;
  return false;
}


int main(){
  FILE * fichier = fopen("instances/0.tom", "r");
  int **tab, **blocsLigne, **blocsColonne, nbLignes = 0, nbColonnes = 0;

  tab = NULL;
  blocsColonne = NULL;
  blocsLigne = NULL;

  lecture(&tab, &blocsLigne, &blocsColonne, &nbLignes, &nbColonnes, fichier);

  fclose(fichier);
  //DEBUG printf("teszdadazdat");
  //DEBUG printf("%d\n",blocsLigne[0][0]);

  int ok = test_1(tab, blocsLigne, blocsColonne, nbLignes, nbColonnes);

  affichage(tab, nbLignes, nbColonnes);

  freeMatrice(tab, nbLignes);
  freeMatrice(blocsLigne, nbLignes);
  freeMatrice(blocsColonne, nbColonnes);
return 0;
}
