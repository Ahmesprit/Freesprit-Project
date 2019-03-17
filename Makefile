prog : main.o background.o
	gcc main.c background.c -o prog -lSDL -lSDL_image -lSDL_mixer

