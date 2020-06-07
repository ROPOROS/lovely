libs = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

printObject =animation.o affichage.o time.o enigme.o save.o menu.o minimap.o

moveObject =player.o monster.o arduino.o

initObject =init.o input.o main.o collision.o font.o musique.o

allObjects = $(printObject) $(moveObject) $(initObject)

game: $(allObjects)
	gcc $(allObjects) -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm -ldl -g -o game

main.o:main.c main.h
	gcc -c main.c $(libs) -g

init.o:init.c init.h
	gcc -c init.c -lSDL -g

font.o:font.h font.c
	gcc -c font.c -lSDL -g

collision.o:collision.h collision.c
	gcc -c collision.c -lSDL -g

input.o:input.c input.h
	gcc -c input.c -lSDL -g

player.o:player.h player.c
	gcc -c player.c -lSDL -g

monster.o:monster.h monster.c
	gcc -c monster.c -lSDL -g

affichage.o:affichage.h affichage.c
	gcc -c affichage.c -lSDL -g

animation.o:animation.h animation.c
	gcc -c animation.c  -lSDL -g

enigme.o:enigme.h enigme.c
	gcc -c enigme.c -lSDL -g

time.o:time.h time.c
	gcc -c time.c -lSDL -g

musique.o:musique.h musique.c
	gcc -c musique.c -lSDL -g

save.o:save.h save.c
	gcc -c save.c -lSDL -g

menu.o:menu.h menu.c
	gcc -c menu.c -lSDL -g

minimap.o:minimap.h minimap.c
	gcc -c minimap.c -lSDL -g

arduino.o:arduino.h arduino.c
	gcc -c arduino.c -lSDL -g

clean:
	rm *.o
