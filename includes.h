#define MAX 256

#define SUCCESS 0

#define TRUE 1
#define FALSE 0

#define delim_ampersand "&&"
#define delim_pipe "|"
#define delim_space " "

#define GREEN  "\033[1m\033[32m"
#define BLUE   "\033[1m\033[34m"
#define RESET  "\x1b[0m"


typedef struct {

    char PWD[MAX];
    char HOME[MAX];
    char USR[MAX];
    char HOST[MAX];
    char ** PATH;

} t_env;

/* Environment */
t_env * env;

 /*  Execs  */
int ejecutar_comando (char *[]);
int ejecutar_pipes (char *[]);

 /*  Process   */
int procesar (char *);

 /*   Tokenize   */
void init_tks (char *[]);
int tokenizar (char *, char *, char *[]);

/*  config    */
int getEnvironment (t_env *);
