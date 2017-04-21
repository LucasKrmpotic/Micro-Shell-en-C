#include <stdio.h>
#include <stdlib.h>

#include "../../includes.h"

/**
*
* @file   init_tks.c
*
*
* @brief  inicializa a NULL un arreglo de punteros (para los arreglos de tokens)
*
* @param  { char *[] }  
* @return { - } 
*
*
*/
void init_tks (char * cmd_tks[]) {
    int i;
    for (i = 0; i < MAX; i++){
        cmd_tks[i] = NULL;
    }
}
