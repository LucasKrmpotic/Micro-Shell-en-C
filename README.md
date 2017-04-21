#  Cuasi Shell en C 

## Descripción

Esta aplicación, que emula un shell de linux, se hizo con el objetivo de ejercitar conceptos de sistmas operativos como                         señales, creación de procesos, pipes, etc. 

No soporta redirecciones, ni ejecuciones condicionales por ||. 

## Features

* Soporta ejecución de todos los comandos instalados.
    
* En la creacion de procesos para la ejecución de comandos, se envía el ambiente al proceso hijo, con lo cual NO es necesario ingresar los comandos con la ruta absoluta del ejecutable, con el nombre del  comando  basta.
    
* Soporta las concatenaciones por medio de pipes ( | ).

* Soporta ejecución condicionada de comandos por &&.

En definitiva admite el ingreso de comandos como:

    " ls -l | grep foo && cat foo | grep bar && ... | ..." 


Trabajo hecho a propuesta de la cátedra Sistemas Operativos de la UNPSJB.  
Docente a cargo: Lic. Marcelo Gómez  
JTP:    Lic Lucy Gutierrez Marticorena  
Auxiliar: APU Leandro Luque  

