#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "utile.h"


void affichage(int **tabfinal, int x, int y){
	for (int i=0;i<x;i++){
		printf("|");
		for (int j=0;j<y;j++){
			if (tabfinal[i][j]==NOIRE)
				printf("O ");
			else if (tabfinal[i][j] == BLANCHE)
				printf("X ");
            else
              printf("? ");
		}
		printf("|\n");
	}
}

