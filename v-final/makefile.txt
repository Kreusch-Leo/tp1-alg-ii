# Flags de compilação
CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc
LDFLAGS = -lm  # Link com a biblioteca matemática
BIN = main

# Gera o executável
all: main.o analise.o search.o sort.o
	$(CC) -o main main.o analise.o search.o sort.o $(LDFLAGS)  

# Compila search.c
search.o: search.c search.h
	$(CC) -c $(CFLAGS) search.c

# Compila analise.c
analise.o: analise.c analise.h
	$(CC) -c $(CFLAGS) analise.c

# Compila sort.c
sort.o: sort.c sort.h
	$(CC) -c $(CFLAGS) sort.c

# Compila tp1.c
main.o: main.c search.h sort.h analise.h
	$(CC) -c $(CFLAGS) main.c

# Limpeza dos arquivos objeto e executável
clean:
	rm -f *.o *~ main

valgrind: main
	valgrind --leak-check=full --track-origins=yes ./$(BIN)


