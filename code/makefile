CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc
LDFLAGS = -lm  # Link com a biblioteca matematica
BIN = main
FILE_PATH = https://github.com/Kreusch-Leo/tp1-alg-ii.git
DEST_DIR = copycode
CODE_DIR = $(DEST_DIR)/code

# Gera o executavel
all: $(BIN)

$(BIN): main.o analise.o search.o sort.o
	$(CC) -o $(BIN) main.o analise.o search.o sort.o $(LDFLAGS)

# Clona os arquivos de codigo e move-se para o diretorio code
clone-files: 
	@which git >/dev/null 2>&1 || { echo "Erro: git nao encontrado. Instale o git para continuar."; exit 1; }
	git clone $(FILE_PATH) $(DEST_DIR)
	@if [ -d "$(CODE_DIR)" ]; then \
		cd $(CODE_DIR); \
		echo "Entrando no diretorio $(CODE_DIR). Execute 'make' para compilar."; \
	else \
		echo "Clone realizado com sucesso. No entanto, o diretorio '$(CODE_DIR)' nao existe."; \
	fi

# Compila search.c
search.o: search.c search.h
	$(CC) -c $(CFLAGS) search.c -o search.o

# Compila analise.c
analise.o: analise.c analise.h
	$(CC) -c $(CFLAGS) analise.c -o analise.o

# Compila sort.c
sort.o: sort.c sort.h
	$(CC) -c $(CFLAGS) sort.c -o sort.o

# Compila main.c
main.o: main.c search.h sort.h analise.h
	$(CC) -c $(CFLAGS) main.c -o main.o

# Limpeza 
clean:
	rm -f *.o *~ $(BIN)
	@echo "Limpeza completa."

# Regra para executar o programa
run: all
	./$(BIN)
