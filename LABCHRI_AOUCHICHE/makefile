####################
partie3: main3
	./main3 sequences_ADN
partie2: main2
	./main2 sequences_ADN 
partie1: main1
	./main1 sequences_ADN

#########################################

main3: main3.o alignement.o famille.o
	gcc -Wall -o main3 main3.o distance.o sequence.o famille.o alignement.o -g3
main3.o: main3.c alignement.h famille.h
	gcc -Wall -c main3.c -g3
alignement.o: alignement.c alignement.h famille.o
	gcc -Wall -c alignement.c -g3

#########################################

main2: main2.o famille.o
	gcc -Wall  sequence.o distance.o famille.o main2.o  -o main2 -g3
main2.o: main2.c famille.h
	gcc -Wall -c  main2.c -g3
famille.o: famille.c famille.h sequence.o distance.o 
	gcc -Wall -c famille.c -g3

##########################################

main1: main1.o sequence.o distance.o
	gcc -Wall -o main1 main1.o sequence.o distance.o -g3
main1.o: main1.c sequence.h distance.h
	gcc -Wall -c main1.c -g3
sequence.o: sequence.c sequence.h distance.h
	gcc -Wall -c  sequence.c -g3
distance.o: sequence.h distance.c  distance.h
	gcc -Wall -c  distance.c -g3

###########################################

clean:
	rm -f main3.o
	rm -f main1.o
	rm -f main2.o
	rm -f main3
	rm -f main1
	rm -f main2
	rm -f sequence.o
	rm -f distance.o
	rm -f famille.o
	rm -f alignement.o

zip:
	mkdir LABCHRI_AOUCHICHE
	mv main3.c ./LABCHRI_AOUCHICHE/
	mv main2.c ./LABCHRI_AOUCHICHE/
	mv main1.c ./LABCHRI_AOUCHICHE/
	mv sequence.c ./LABCHRI_AOUCHICHE/
	mv sequence.h ./LABCHRI_AOUCHICHE/
	mv distance.c ./LABCHRI_AOUCHICHE/
	mv distance.h ./LABCHRI_AOUCHICHE/
	mv famille.h ./LABCHRI_AOUCHICHE/
	mv famille.c ./LABCHRI_AOUCHICHE/
	mv alignement.h ./LABCHRI_AOUCHICHE/
	mv alignement.c ./LABCHRI_AOUCHICHE/
	mv sequences_ADN ./LABCHRI_AOUCHICHE/
	mv LABCHRI_AOUCHICHE. ./LABCHRI_AOUCHICHE/
	mv makefile ./LABCHRI_AOUCHICHE
	zip -r LABCHRI_AOUCHICHE LABCHRI_AOUCHICHE
