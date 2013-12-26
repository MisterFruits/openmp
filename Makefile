#CC = gcc 
CC = gcc-mp-4.8 
OPT = -g -Wall -fopenmp 
BIN = main

all:$(BIN)

#OBJETS
main.o : main.c
	$(CC) $(OPT) $< -c
timer.o : timer.c
	$(CC) $(OPT) $< -c
vector.o : vector.c
	$(CC) $(OPT) $< -c



#MAINS
main : main.o timer.o vector.o 
	$(CC) -o $@ $^ $(OPT)

clean:
	rm -r *.o $(BIN) 

