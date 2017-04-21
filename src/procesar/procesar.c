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
* @file   procesar.c
*
*
* @brief  recibe una linea de texto e interpreta y rutea los comandos a ejecutarse
*         controlando existencia de pipes y && 
*
* @param  { char * } - comandos / comandos = "prog1 args | prog2 args && prog3 args.." 
* @return { int } status
*
*
*/

int procesar (char * comandos) {

    /*  arreglos para los comandos  */
    char * cmd_ampersand[MAX]; // para tokenizar por &&
    char * cmd_pipes[MAX]; // para tokenizar por pipes
    char * cmd_spaces[MAX];    // para tokenizar por espacios

    /*  iterador y bandera  */
    int i = 0, flag = FALSE;

    /*  inicializamos los arregos   */
    init_tks (cmd_ampersand);
    init_tks (cmd_pipes); 
    init_tks (cmd_spaces);

    if (strstr(comandos, delim_ampersand)) {
    /*  el comando tiene al menos un && */

        tokenizar(comandos, delim_ampersand, cmd_ampersand);
        while (cmd_ampersand[i] && (flag == FALSE)){
        /*  hay comandos y los anteriores han terminado bien    */

            if (strstr(cmd_ampersand[i], delim_pipe)){
                /*  en el token actual hay al menos un pipe     */

                tokenizar(cmd_ampersand[i], delim_pipe, cmd_pipes);
                if(ejecutar_pipes(cmd_pipes) < 0)
                    flag = TRUE;

            } else {
                /*  en el token actual no hay pipes     */
                
                tokenizar(cmd_ampersand[i], delim_space, cmd_spaces);
                if (ejecutar_comando(cmd_spaces) < 0)
                    flag = TRUE;   
            }
            i++;
       }
       return 0;
    } else {
        /* el comando no tiene  &&   */

        if (strstr(comandos, delim_pipe)) {
            /*      el comando tiene pipes      */

            tokenizar(comandos, delim_pipe, cmd_pipes);
            if (ejecutar_pipes(cmd_pipes)!=SUCCESS)
                return 1
                ;
            
            return 0;

        } else {
            /*      el comando no tiene pipes   */

            tokenizar(comandos, delim_space, cmd_spaces);
            if (ejecutar_comando(cmd_spaces) != SUCCESS)
                return 1
                ;

            return 0;
        }
    }
}


