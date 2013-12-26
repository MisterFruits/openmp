CC = gcc-mp-4.8 
OPT = -g -Wall -fopenmp 
BINDIR = ./bin
SRCDIR = ./src
BIN = $(BINDIR)/main

all:$(BIN)

#OBJETS
$(OBJDIR)/main.o : $(SRCDIR)/main.c
	$(CC) $(OPT) $< -c

$(OBJDIR)/timer.o : $(SRCDIR)/timer.c
	$(CC) $(OPT) $< -c

$(OBJDIR)/vector.o : $(SRCDIR)/vector.c
	$(CC) $(OPT) $< -c



#MAINS
$(BINDIR)/main : $(OBJDIR)/main.o $(OBJDIR)/timer.o $(OBJDIR)/vector.o 
	$(CC) -o $@ $^ $(OPT)

clean:
	rm -r $(OBJDIR)/* $(BINDIR)/* 

