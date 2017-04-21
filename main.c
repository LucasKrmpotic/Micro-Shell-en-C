#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "includes.h"

/** @mainpage
 *
 *  Esta aplicación, que emula un shell de linux, se hizo con el objetivo de ejercitar 
 *  conceptos de sistmas operativos como señales, creación de procesos, pipes, etc.  
 *
 *  No soporta redirecciones, ni ejecuciones condicionales por ||.
 *  Admite todo tipo de concatenaciones por && y | por ejemplo:
 *  
 *       " ls -l | grep foo && cat foo | grep bar && ... | ..." 
 *
 *
 * @author Lucas Krmpotic
 * @date abril 2017
 * @version 0.0.1
 *
 */
void printPrompt ();

int main (int argc, char const * argv[]) {

    char * comandos = malloc(sizeof(MAX));
    env = malloc (sizeof(t_env));
    
    if (getEnvironment(env) < 0) {
        perror("Environment error");
        exit(-1);
    }
    system("clear");
    printf("================================================\n");
    printf("  TP Nro 2 - Llamadas al sistema                \n");
    printf("================================================\n");
    printf("\n");
    while (1) {
        printPrompt();     
        scanf("%[^\n]", comandos);
        if (strlen(comandos) != 0)
            procesar(comandos);      
        getchar();

    }
    return 0;
}

void printPrompt () {
    
    char ppwd[sizeof (env->PWD)];
    int i;
    char sub[MAX];  
    strncpy(sub, env->HOME, strlen(env->HOME));
    size_t nc_sub = strlen(sub);
    char *p;
    char *q;

    p = env->PWD;
    i = 0;

    while ((q = strstr(p, sub)) != NULL){
        while (p < q)
            ppwd[i++] = *p++;
        p += nc_sub;
    }
    while ((ppwd[i++] = *p++) != '\0');


    printf(GREEN "%s@" RESET, env->USR);
    printf(GREEN "%s" RESET, env->HOST);
    printf(":");
    printf(BLUE "~%s" RESET, ppwd);
    printf("$ ");
    
}
