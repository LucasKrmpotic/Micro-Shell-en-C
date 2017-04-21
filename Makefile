##
#	Makefile principal de la  aplicacion
#	@author Lucas Krmpotic 
#	@date Abril 2017
#
#	Mini shell para Unix en c
#	Esta aplicación se hizo con el obetivo de ejercitar conceptos de sistemas operativos,
#	como señales, llamadas al sistema para creacion de procesos, pipes, etc.-
#
##


# Macros
CC = gcc
CFLAGS = -g -Wall

# Exec
EJECUTAR = ejecutar_comando.o ejecutar_pipes.o 

# Process
PROCESAR = procesar.o

# Tokenization
TOKENIZAR = tokenizar.o init_tks.o

# Config
CONFIG = get_environment.o

all: main clean

main: main.c $(TOKENIZAR) $(PROCESAR) $(EJECUTAR) $(CONFIG) includes.h
	$(CC) $(CFLAGS) main.c -o main $(TOKENIZAR) $(PROCESAR) $(EJECUTAR) $(CONFIG)

ejecutar_comando.o: src/ejecutar/ejecutar_comando.c includes.h
	$(CC) $(CFLAGS) -c src/ejecutar/ejecutar_comando.c

ejecutar_pipes.o: src/ejecutar/ejecutar_pipes.c includes.h
	$(CC) $(CFLAGS) -c src/ejecutar/ejecutar_pipes.c

procesar.o: src/procesar/procesar.c includes.h
	$(CC) $(CFLAGS) -c src/procesar/procesar.c

tokenizar.o: src/tokenizar/tokenizar.c includes.h
	$(CC) $(CFLAGS) -c src/tokenizar/tokenizar.c

init_tks.o: src/tokenizar/init_tks.c includes.h
	$(CC) $(CFLAGS) -c src/tokenizar/init_tks.c

get_environment.o: config/get_environment.c includes.h
	$(CC) $(CFLAGS) -c config/get_environment.c

clean:
	rm *.o

