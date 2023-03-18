#ifndef LECTURE_FICHIER_H
#define LECTURE_FICHIER_H

void ligCol(int *nbLignes, int *nbColonnes, FILE** fichier);

int **initialiserMatrice(int nbLignes, int nbColonnes);

int **creerBloc(int nb, FILE** fichier);

void freeMatrice(int **tab, int n);

void lecture(int ***tab, int ***blocsLigne, int ***blocsColonne, int *nbLignes, int *nbColonnes, FILE* fichier);

#endif
