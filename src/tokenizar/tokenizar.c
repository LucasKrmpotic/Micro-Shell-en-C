#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <syscall.h>
#include <sys/wait.h>

#include "../../includes.h"

/**
*
* @file   tokenizar.c
*
*
* @brief  tokeniza una linea de texto en funcion de un delimitador y copia en un 
*         arreglo cuya dirección de memoria viene dada por parámetro
*
* @param  { char *, char *, char *[] } - lineaDeTexto, delimitador, arreglo de tokens  
* @return { int } status
*
*
*/

int tokenizar (char * comandos, char * delim, char * cmd_tks[]) {

    char * tokens = malloc(strlen(comandos));
    int i = 0;

    tokens = strtok(comandos, delim);
    while (tokens){

        cmd_tks[i] = malloc(strlen(tokens));
        strncpy(cmd_tks[i], tokens, strlen(tokens));
        i++;
        tokens = strtok(NULL, delim);

    }
    free(tokens);
    return 0;
}


