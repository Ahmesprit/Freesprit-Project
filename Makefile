all: prog excute clean
excute:
	@echo "excuting..."
	./prog
prog : main.o background.o menubutton.o character.o enemy.o enigme.o utilities.o
	@echo "Making program..."
	gcc main.c background.c menubutton.c character.c enemy.c enigme.c utilities.c -o prog -lSDL -lSDL_image -lm -lSDL_mixer -lSDL_ttf
clean:
	@echo "cleaning up..."
	rm *.o
