CC=gcc
CFLAGS=-Wall -Werror -g 
EXEC=essai_fap

essai_fap : essai_fap.o fap.o
	$(CC) $(CFLAGS) -o $(EXEC) essai_fap.o fap.o

essai_fap.o : essai_fap.c
	$(CC) $(CFLAGS) -c essai_fap.c

fap.o : fap.c fap.h
	$(CC) $(CFLAGS) -c fap.c

clean:
	rm -f *.o 


