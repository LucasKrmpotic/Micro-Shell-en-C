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
* @file   ejecutar_comando.c
*
*
* @brief  crea un proceso para ejecutar un comando dado por parametro
* @param  { char *[] } - comando / cmd[0] = programa, cmd[1] = arg1 ...
* @return { int } status
*
*
*/

int ejecutar_comando (char * cmd[]){

    int status;
    pid_t child_pid;
    
    /*  Los comandos clear y cd se ejecutan sin fork() */
    if (strcmp(cmd[0], "clear")==0){

        system("clear");

    } else if (strcmp(cmd[0], "cd") == 0) {

        if(chdir(cmd[1])!= SUCCESS){
            perror("Error on directory change");
            exit(-1);
        }
        getcwd(env->PWD, sizeof(env->PWD)); 

    } else {

        /*  El comando no es ni cd ni clear */
        if((child_pid = fork()) < 0){
            perror("Error creating a process");
            exit(-1);

        } else if (child_pid == 0) {
            //hijo
            if (execvpe(cmd[0], cmd, env->PATH) < 0)
                perror("Error executing command");
                exit(1);

        } else {
            //padre
            waitpid(child_pid, &status, 0);
        }

        if ( WIFEXITED(status) && WEXITSTATUS(status) != 0 )
            return -1;

    }
    return 0;
}
