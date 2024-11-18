CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc
LDFLAGS = -lm  # Link com a biblioteca matemática
BIN = main
FILE_PATH = https://github.com/Kreusch-Leo/tp1-alg-ii.git
DEST_DIR = copycode

# Clona os arquivos de código
clone-files: 
	git clone $(FILE_PATH) ~/$(DEST_DIR)
	echo "Mova-se para o diretorio copycode/code e execute make"

# Gera o executável
all: main.o analise.o search.o sort.o
	$(CC) -o $(BIN) main.o analise.o search.o sort.o $(LDFLAGS)

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
	rm -f *.o *~ $(BIN)

# Regra para executar o programa
run: all
	./$(BIN)
