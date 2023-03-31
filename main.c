#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

#define MAXLINE 300

//void ver_clave(int argumento, char *cad);
//void agregar_clave(int argumento, char *cad);
void borrar_clave(void);
void salir(void);


int llena_arreglo(char *s, int lim);
void agrega_terminador(char *s);
void agregar_datos(int argumento, char *arch);
void ver_datos(int argumento, char *arch);
static void reset(void);
static int endofline(FILE *fin, int c);
static int split(void);
static char *advquoted(char *p);
char cad[MAXLINE];

FILE *fp;

int main(int argc, char *argv[])
{
    char opcion;
    //int c;
    //int largo = 0; /** Recibe la cantidad de elementos hasta el momento
       //                en el arreglo **/

    do{
        printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf(" A- Agregar app-usuario-contraseña\n");
        printf(" B- Ver app-usuario-contraseña\n");
        printf(" C- Borrar clave\n");
        printf(" D- Salir del programa\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++\n");

        scanf("%c", &opcion);
        while(getchar() != '\n'); //Limpia el buffer de entrada de stdin

        printf("opcion = %c \n", opcion);
        switch(opcion){
			case 'A':
			case 'a':
                //ver_clave(argc, argv[1]);
                printf("Ingrese la página o aplicacion:\n");
                llena_arreglo(cad, MAXLINE);

                printf("Ingrese el usuario:\n");
                llena_arreglo(cad, MAXLINE);

                printf("Ingrese la contraseña:\n");
                llena_arreglo(cad, MAXLINE);

    //printf("\n");
                agrega_terminador(cad);
                agregar_datos(argc, argv[1]);

            break;

            case 'b':
            case 'B':
                //agregar_clave(argc, argv[1]);
                ver_datos(argc, argv[1]);
            break;

            case 'c':
            case 'C':
                borrar_clave();
            break;

            case 'd':
            case 'D':
                salir();
            break;

            default: //Opción que no está disponible en el menú
                printf("Opcion no valida");
            break;
            }

        }while(opcion!='e' || opcion!='E');
	    //Hacer mientras el usuario no selecciona la opción de salir...
    //}
    return 0;
}
/***********************************************************/
/**void ver_clave(int argumento, char *cad)
{
    char car;
    if(argumento != 2){
                    printf("Has olvidade introducir el nombre del archivo.\n");
                    exit(1);
                }
                if((fp = fopen(cad, "r")) == NULL){
                    printf("No se puede abrir el archivo.\n");
                    exit(1);
                }**/

/**	car = getc(fp); Leer un caracter **/
 /**   while(car != EOF){**/
  /**      putchar(car);  Lo muestra en la pantalla **/
  /**      car = getc(fp);
    }
    fclose(fp);
}**/
/*********************************************************/
/**void agregar_clave(int argumento, char *cad)
{
    char ch;
    char cadena[80];
    if(argumento != 2){
        printf("Has olvidade introducir el nombre del archivo.\n");
        exit(1);
    }
    if((fp = fopen(cad, "a")) == NULL){
        printf("No se puede abrir el archivo.\n");
        exit(1);
    }

    //while((ch = getchar()) != '\n' && ch != EOF);

    do{
        printf("Introduce tu cadena(Intro para terminar):\n");
        gets(cadena);**/
/**        strcat(cadena, "\n");   añade un salto de línea **/
  /**      fputs(cadena, fp);**/
/**    }while(*cadena != '\n');**/
 /**   fclose(fp);
}**/
/*********************************************************/
void borrar_clave(void)
{

}
/*********************************************************/
void salir(void)
{

}
/*************************************************************/
/** llena_arreglo: va metiendo los datos ingresados en un arreglo que
    porsteriormente seran volcados en un archivo tipo csv **/
int llena_arreglo(char *s, int lim)
{
    char c;
    static int i;

    /** Adelanta el puntero para no pisar el dato ingresado anteriormente **/
    s += i;

    for(; i < lim-1 && (c = getchar()) !='\n'; ++i, ++s){
        *s = c;
    }
    if(c == '\n'){
        *s = ','; /** Se agrega la coma como separador **/
        ++s;      /** se adelanta el puntero **/
        ++i;
    }
    *s = '\0';
    ++s;
    *s = '\n';
    return i;  /** Retorna la cantidad de caracteres ingresados **/
}
/** Agrega_terminador **/
void agrega_terminador(char *s)
{
    int i;
    for(i = 0; *s != '\0'; ++i, ++s)
        ;

    s--; /** Se va un lugar para atras y se agrega el terminador nulo en
         lugar de la ultima coma **/
    *s = '\0';
}
/** Agregar_datos: funcion que va agregando los datos ingresados en un
    archivo csv **/
void agregar_datos(int argumento, char *arch)
{
    char *p;
    p = cad;
    if(argumento != 2){
        printf("Has olvidade introducir el nombre del archivo.\n");
        exit(1);
    }
    if((fp = fopen(arch, "a")) == NULL){
        printf("No se puede abrir el archivo.\n");
        exit(1);
    }

    do{
        fputc(*p, fp);
        p++;
    }while(*p);

    fputc('\n', fp);

    fclose(fp);
}
/** csvtest main: prueba de la biblioteca CSV **/


/**int main(int argc, char *argv[])
{
    int i;
    char *line;
    FILE *fp;

    if(argc != 2){
        printf("Has olvidade introducir el nombre del archivo.\n");
        exit(1);
    }**/
    /** Funciona con r, r+, rb, ab, a+, a solo no funciona **/
 /**   if((fp = fopen(argv[1], "rb")) == NULL){
        printf("No se puede abrir el archivo.\n");
        exit(1);
    }
    while((line = csvgetline(fp)) != NULL){
        printf("line = '%s'\n", line);
        for(i = 0; i < csvnfield(); i++)
            printf("campo[%d] = '%s'\n", i, csvfield(i));
    }
    return 0;
}**/
void ver_datos(int argumento, char *arch)
{
    int i;
    char *line;

    if(argumento != 2){
        printf("Has olvidade introducir el nombre del archivo.\n");
        exit(1);
    }
    if((fp = fopen(arch, "r+")) == NULL){
        printf("No se puede abrir el archivo.\n");
        exit(1);
    }

    while((line = csvgetline(fp)) != NULL){
        printf("line = '%s'\n", line);
        for(i = 0; i < csvnfield(); i++)
            printf("campo[%d] = '%s'\n", i, csvfield(i));
    }
}
/** csvgetline: lee una línea, crece según se requiera **/
/** entrada de muestra: "LU",86.25,"11/4/1998","2:19PM",+4.0625 **/
char *csvgetline(FILE *fin)
{
    int i, c;
    char *newl, *news;
    if(line == NULL){ /** Se asigna en la primera llamada **/
        maxline = maxfield = 1;
        line = (char *)malloc(maxline);
        sline = (char *)malloc(maxline);
        field = (char **)malloc(maxfield*sizeof(field[0]));
        if(line == NULL || sline == NULL || field  == NULL){
            reset();
            return NULL;   /** Memoria agotada **/
        }
    }
    //getc: devuelve el sig. caracter de la entrada como un entero

    for(i =0; (c = getc(fin))!=EOF && !endofline(fin, c); i++){
        if(i >= maxline-1){ /** Crece la línea **/
            maxline *= 2;   /** Duplica el tamaño actual **/
            newl = (char *)realloc(line, maxline);
            news = (char *)realloc(sline, maxline);
            if(newl == NULL || news == NULL){
                reset();
                return NULL;   /** Memoria agotada **/
            }
            line = newl;
            sline = news;
        }
        line[i] = c;
    }
    line[i] = '\0';
    if(split() == NOMEM){
        reset();
        return NULL;   /** Memoria agotada **/
    }
    return (c == EOF && i == 0) ? NULL : line;
}
/** reset: establece las variables a sus valores de inicio **/
static void reset(void)
{
    free(line); /** Free(NULL) esta permitido por el ANSI C **/
    free(sline);
    free(field);
    line = NULL;
    sline = NULL;
    field = NULL;
    maxline = maxfield = nfield = 0;
}
/** endofline: detecta y consume '\r', '\n', '\r\n' o EOF **/
static int endofline(FILE *fin, int c)
{
    int eol;

    eol = (c=='\r' || c=='\n');
    if(c == '\r'){
        c = getc(fin);
        if(c != '\n' && c !=EOF)
            ungetc(c, fin); /** Se leyo demasiado; regresa c **/
    }
    return eol;
}
/** split: divide la línea en campos **/
static int split(void)
{
    char *p, **newf;
    char *sepp; /** apuntador a un caracter separador temporal **/
    int sepc; /** caracter separador temporal **/

    nfield = 0;
    if(line[0] == '\0')
        return 0;
    strcpy(sline, line);
    p = sline;

    do{
        if(nfield >= maxfield){
            maxfield *= 2;      /** duplica el tamaño actual **/
            newf = (char **)realloc(field, maxfield * sizeof(field[0]));
            if(newf == NULL)
                return NOMEM;
            field = newf;
        }
        if(*p == '"')
            sepp = advquoted(++p); /** Ignora la comilla inicial **/
        else
            sepp = p + strcspn(p, fieldsep);
        sepc = sepp[0];
        sepp[0] = '\0';  /** Termina el campo **/
        field[nfield++] = p;
        p = sepp + 1;
    } while(sepc == ',');

    return nfield;
}
/** advquoted: campo entrecomillas; devuelve un apuntador al siguiente separador **/
static char *advquoted(char *p)
{
    int i, j;
    for(i = j = 0; p[j] != '\0'; i++, j++){
        if(p[j] == '"' && p[++j] != '"'){
            /** copia hasta el siguiente separador '\0' **/
            int k = strcspn(p+j, fieldsep);

            memmove(p+i, p+j, k);
            i += k;
            j += k;
            break;
        }
        p[i] = p[j];
    }
    p[i] = '\0';
    return p + j;
}
/** csvfield: devuelve un apuntador al n-esimo campo **/
char *csvfield(int n)
{
    if(n < 0 || n >= nfield)
        return NULL;
    return field[n];
}
/** csvnfield: devuelve el numero de campos **/
int csvnfield(void)
{
    return nfield;
}

