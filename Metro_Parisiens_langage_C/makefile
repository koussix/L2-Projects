run: compil
	./main
compil: main.o lecture.o graphe.o
	gcc -Wall lecture.o graphe.o main.o -o main -g
main.o: main.c lecture.h
	gcc -Wall -c main.c -g
lecture.o: lecture.c lecture.h util.h
	gcc -Wall -c lecture.c -g
graphe.o: graphe.c lecture.h graphe.h util.h
	gcc -Wall -c graphe.c -g
clean:
	rm -f main
	rm -f main.o
	rm -f lecture.o
	rm -f graphe.o
