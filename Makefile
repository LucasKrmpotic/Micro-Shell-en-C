# Macros
CC = gcc
CFLAGS = -g -Wall

# Exec
EJECUTAR = ejecutar_comando.o ejecutar_pipes.o 

# Process
PROCESAR = procesar.o

# Tokenization
TOKENIZAR = tokenizar.o add_path.o init_tks.o

all: main clean

main: main.c $(TOKENIZAR) $(PROCESAR) $(EJECUTAR) includes.h
	$(CC) $(CFLAGS) main.c -o main $(TOKENIZAR) $(PROCESAR) $(EJECUTAR)

ejecutar_comando.o: src/ejecutar/ejecutar_comando.c includes.h
	$(CC) $(CFLAGS) -c src/ejecutar/ejecutar_comando.c

ejecutar_pipes.o: src/ejecutar/ejecutar_pipes.c includes.h
	$(CC) $(CFLAGS) -c src/ejecutar/ejecutar_pipes.c

procesar.o: src/procesar/procesar.c includes.h
	$(CC) $(CFLAGS) -c src/procesar/procesar.c

tokenizar.o: src/tokenizar/tokenizar.c includes.h
	$(CC) $(CFLAGS) -c src/tokenizar/tokenizar.c

add_path.o: src/tokenizar/add_path.c includes.h
	$(CC) $(CFLAGS) -c src/tokenizar/add_path.c

init_tks.o: src/tokenizar/init_tks.c includes.h
	$(CC) $(CFLAGS) -c src/tokenizar/init_tks.c

clean:
	rm *.o

