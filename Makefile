prog:init.o affichage.o main.o
	gcc init.c affichage.c main.c -o prog -lSDL -lSDL_image -lSDL_mixer
