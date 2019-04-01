prog : main.o background.o menubutton.o character.o collision.o enemy.o enigme.o management.o
	gcc main.c background.c menubutton.c character.c collision.c enemy.c enigme.c management.c -o prog -lSDL -lSDL_image -lm -lSDL_mixer -lSDL_ttf
