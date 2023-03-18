#include "resolution.h"
#include "utile.h"
#include <stdbool.h>

bool est_blanc(int** tab,int x,int y){
	if (tab[x][y]==BLANCHE)
		return true;
	return false;
}

bool est_noir(int** tab,int x,int y){
	if (tab[x][y]==NOIRE)
		return true;
	return false;
}

//retourne 1 si vrai sinon 0
int test(int** tab,int j,int l,int *sl,int li){

	//cas 1
	if (l==0){
	// vrai/faux si case noire dans [0,i]
		for (int i=0;i<j;i++){
			if(est_noir(tab,li,i))
				return 0;
		}
		return 1;
	}
	//cas 2a
	if (j<sl[l]-1)
		return 0;

	//cas 2b
	if (j==sl[l]-1){
		if(l==1){
		//vrai/faux si cases noire dans [0,i]
			for (int i=0;i<j;i++){
				if(est_noir(tab,li,i))
					return 0;
			}

			return 1;
		}
	}
	//cas 2c

	else{
	//on test noir et blanc
	//noir
		int test_noir=1;
		for(int i=j-sl[l];i<j;i++){
			if (est_blanc(tab,li,j))
				test_noir=0;
		}
		if (test_noir==1){
			if(est_noir(tab,li,j-sl[l]-1))
				test_noir=0;
		}
		if (test_noir==1)
			return test(tab,j-1,l,sl,li);

	//blanc
		if (est_blanc(tab,li,j))
			return test(tab,j-1-sl[l],l,sl,li);
		else return 0;
	}
	return 0;
}

bool colorationLigne(int **tab, int M, int i, int **bloc){
  int resB, resN;

  for(int j=0; j<M; j++){
    if(tab[i][j] == INCONNUE){
      tab[i][j] = BLANCHE;
      resB = test(tab, j, bloc[i][0], bloc[i], i);
      tab[i][j] = NOIRE;
      resN = test(tab, j, bloc[i][0], bloc[i], i);

      if(resB != 1 && resN != 1)
        return false;

      if(resB == 1 && resN != 1)
        tab[i][j] = BLANCHE;
      else if(resB != 1 && resN == 1)
        tab[i][j] = NOIRE;
      else
        tab[i][j] = INCONNUE;
    }
  }
  return true;
}

bool colorationColonne(int **tab, int N, int j, int **bloc){
  int resB, resN;

  for(int i=0; i<N; i++){
    if(tab[i][j] == INCONNUE){
      tab[i][j] = BLANCHE;
      resB = test(tab, i, bloc[j][0], bloc[j], j);
      tab[i][j] = NOIRE;
      resN = test(tab, i, bloc[j][0], bloc[j], j);

      if(resB != 1 && resN != 1)
        return false;

      if(resB == 1 && resN != 1)
        tab[i][j] = BLANCHE;
      else if(resB != 1 && resN == 1)
        tab[i][j] = NOIRE;
      else
        tab[i][j] = INCONNUE;
    }
  }
  return true;
}
