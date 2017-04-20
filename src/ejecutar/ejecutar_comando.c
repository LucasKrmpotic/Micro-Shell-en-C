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
    
    add_path(&cmd[0]);

    if((child_pid = fork()) < 0){
        exit(-1);

    } else if (child_pid == 0) {
        //hijo
        if (execv(cmd[0], cmd ) < 0)
            perror("Error executing command");
            exit(1);

    } else {
        //padre
        waitpid(child_pid, &status, 0);
 
    }

    if ( WIFEXITED(status) && WEXITSTATUS(status) != 0 )
        return -1;             
    return 0;
}
