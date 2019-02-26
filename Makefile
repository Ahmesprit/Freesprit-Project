prog:code.o
	gcc main.c -o prog -lSDL -lSDL_image -lSDL_mixer
code.o:code.c
	gcc -c main.c

