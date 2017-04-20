#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <syscall.h>
#include <sys/wait.h>

#include "includes.h"

/** @mainpage
 *
 * ..... bla bla 
 *
 * @author Lucas Krmpotic
 * @date abril 2017
 * @version 0.0.1
 *
 */
int main (int argc, char const * argv[]) {

    char * comandos = malloc(sizeof(MAX_LINE));
    
    while (1) {
	    
        printf("~$");
        scanf("%[^\n]", comandos);
        if (procesar(comandos)!= SUCCESS) {
            printf("Termino para el orto\n");
            return 1;
        }
        
        getchar();

    }
    return 0;
}

