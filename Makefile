EXEC=main

all: $(EXEC)

main: resolution.o affichage.o lecture_fichier.o main.o
	gcc -o main -g resolution.o affichage.o lecture_fichier.o main.o

lecture_fichier.o: lecture_fichier.c
	gcc -o lecture_fichier.o -g -c lecture_fichier.c -Wall

resolution.o: resolution.c
	gcc -o resolution.o -g -c resolution.c -Wall

affichage.o: affichage.c
	gcc -o affichage.o -g -c affichage.c -Wall

main.o: main.c resolution.h utile.h affichage.h lecture_fichier.h
	gcc -o main.o -g -c main.c -Wall

clean :
	rm *.o $(EXEC)
