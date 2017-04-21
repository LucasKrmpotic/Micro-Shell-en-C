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
* @file   ejecutar_pipes.c
*
*
* @brief  ejecuta una serie de comandos concatenados a traves de tuberías (pipes)
* @param  { char * [] } - cmds[] / cmds[0] = "prog1 args", cmds[1] = "prog2 args"
* @return { int } status
*
*
*/

int ejecutar_pipes (char * cmds[]) {

    char * comando[MAX]; // para tokenizar por espacios
    pid_t pid;
    int status;

    /**  
    *  conectamos entrada y salida estandar a descriptores temporales para poder
    *  reestablecerla luego
    */
    int tmpin = dup(0);
    int tmpout = dup(1);

    /*  descriptores para la tubería    */
    int fdin = dup(tmpin); 
    int fdout;

    int i = 0;
    
    /**
    *   en este lup se crea un proceso por cada comando a ejecutar. Antes de ello
    *   se verifican las tuberías
    */
    while (cmds[i]) {

        /*  conectamos entrada estandar a fdin*/
        dup2(fdin,0);
        close(fdin);

        if (cmds[i+1] == NULL){
            /*  es el ultimo comando por lo tanto la salida no será a la tubería  */
            fdout = dup(tmpout);

        } else {

            /*  creamos la tubería y le conectamos fdin y fdout */
            int tub[2];
            pipe(tub);
            fdout = tub[1];
            fdin = tub[0];
            
        }

        dup2(fdout, 1); 
        close (fdout);

        if ((pid = fork()) < 0) {
            
            perror("Error creating a process");
            exit(-1);

        } else if (pid == 0 ) {
        /*    el hijo ejecuta los comandos    */
            
            init_tks(comando);
            tokenizar(cmds[i], delim_space, comando);
            //add_path(&comando[0]); 

            if (execvpe(comando[0], comando, env->PATH) < 0){

                perror("Error executing command"); 
                exit (-1);

            }
        }
        i++;

    }

    /*  reestablecemos la entrada y salida estandar */
    dup2 (tmpin, 0); 
    dup2 (tmpout, 1); 
    close (tmpin); 
    close (tmpout);

    /**
    * el padre espera y pregunta el estado de terminación ya que los comandos 
    * pueden ser parte de uno mas grende que contenga un &&
    */
    waitpid(pid, &status, 0);
    if ( WIFEXITED(status) && WEXITSTATUS(status) != 0 )
        return -1; 
    return 0;
}









        
