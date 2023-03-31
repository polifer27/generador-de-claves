
/** csv.h: interfaz para biblioteca csv **/

extern char *csvgetline(FILE *f); /** lee la siguiente linea de entrada **/
extern char *csvfield(int n);     /** devuelve el campo n **/
extern int csvnfield(void);        /** devuelve el numero de campos **/

enum{ NOMEM = -2 }; /** Señal de memoria agotada **/

static char *line = NULL; /** caracteres de entrada **/
static char *sline = NULL; /** copia de linea utilizada por split **/
static int maxline = 0;    /** tamaño de line[] y sline[] **/
static char **field = NULL; /** apuntadores de campo **/
static int maxfield = 0;    /** tamaño de field[] **/
static int nfield = 0;      /** numero de campos en field[] **/
static char fieldsep[] = ","; /** caracteres de separacion de campos **/
