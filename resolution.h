#include <stdbool.h>

bool est_blanc(int** tab,int x,int y);

bool est_noir(int** tab,int x,int y);

int test(int** tab,int j,int l,int *sl,int li);

bool colorationLigne(int **tab, int M, int i, int **bloc);

bool colorationColonne(int **tab, int N, int j, int **bloc);
