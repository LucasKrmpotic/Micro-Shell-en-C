#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../includes.h"

/**
*
* @file   add_path.c
*
*
* @brief  agrega "/bin/" a la primera posicion de un arreglo que contiene 
*         nombrePrograma y argumentos
*
* @param  { char **} - comando_sinPath / *comando_sinPath = "nombrePrograma" y luego 
*         de la ejecución *comando_sinPath = "/bin/nombrePrograma" 
* 
* @return { int } status
*
*
*/
int add_path ( char **comando_sinPath){

    char * aux = malloc(strlen(*comando_sinPath)); 
    
    strcat(aux, X_PATH);
    strcat(aux, *comando_sinPath);
    *comando_sinPath = malloc(strlen(aux));
    strcpy(*comando_sinPath, aux);
    free(aux);

    return 0;

}
