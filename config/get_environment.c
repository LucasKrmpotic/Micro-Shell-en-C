#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "../includes.h"

/**
*
* @file   getEnvironment.c
*
*
* @brief  setea el ambiente 
* @param  { t_env * } - puntero a struct que contiene las variables de entorno
* @return { int } status
*
*
*/

static int flag = TRUE; 
int getEnvironment (t_env * env) {


    if (flag == TRUE) {

        char * path_args[] = { getenv("PATH") , NULL };
        env->PATH = path_args;
        getcwd(env->PWD, sizeof(env->PWD));
        strncpy(env->HOME, getenv("HOME"), strlen(getenv("HOME")));
        strncpy(env->USR, getenv("USER"), strlen(getenv("USER")));
        gethostname(env->HOST, sizeof(env->HOST));

        flag = FALSE;

    } else {
        return -1;
    }

    return 0;

}

