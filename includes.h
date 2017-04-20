#define MAX_LINE 200

#define SUCCESS 0

#define TRUE 1
#define FALSE 0

#define delim_ampersand "&&"
#define delim_pipe "|"
#define delim_space " "


#define X_PATH "/bin/"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// /*  Execs  */
int ejecutar_comando (char *[]);
int ejecutar_pipes (char *[]);

// /*  Process   */
int procesar (char *);

// /*   Tokenize   */
void init_tks (char *[]);
int tokenizar (char *, char *, char *[]);
int add_path (char **);
