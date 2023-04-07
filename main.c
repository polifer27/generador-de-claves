#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

#define MAXLINE 300
#define NUM_CARACTERES 8
//void ver_clave(int argumento, char *cad);
//void agregar_clave(int argumento, char *cad);
void borrar_clave(void);
void salir(void);


int llena_arreglo(char *s, int lim);
//void agrega_terminador(char *s);
void app_usu_contra(void);
//char *generar_contraseña(void);
char *generate_key(int max);
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
    //char *ptr;


    do{
        printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf(" A- Agregar app, usuario, la contraseña es generada por el programa\n");
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
                app_usu_contra();
               // agrega_terminador(cad);

                //ptr = generate_key(8);
              //  ptr = ptr + 8;
               // ptr = '\0';
               // ptr = ptr - 8;
                //printf("%s\n", ptr);
                //for(int i = 0; i < 8; i++)
                //    printf("%c", ptr[i]);
                //printf("\n");
                //ptr -= 8;
                 agregar_datos(argc, argv[1]);

            break;

            case 'b':
            case 'B':
                ver_datos(argc, argv[1]);
            break;

            case 'c':
            case 'C':
                borrar_clave();
            break;

            case 'd':
            case 'D':
                exit(1);
            break;

            default: //Opción que no está disponible en el menú
                printf("Opcion no valida");
            break;
            }

        }while(opcion!='e' || opcion!='E');
	    //Hacer mientras el usuario no selecciona la opción de salir...

    return 0;
}
/** Agregar app usu y contra **/
void app_usu_contra(void)
{
    char *p;
    int i = 0;
    int j;
    printf("Ingrese la página o aplicacion:\n");
    llena_arreglo(cad, MAXLINE);

    printf("Ingrese el usuario:\n");
    // La variable i contiene la cantidad de caracteres en total ingresados hasta el momento
    // en cad contando la coma separadora y todo
    i = llena_arreglo(cad, MAXLINE);

    p = generate_key(NUM_CARACTERES);

    for(j = 0; j <= NUM_CARACTERES; j++){
        cad[i+j] = *p;
        p++;
    }
    j++;
    cad[i+j] = '\n';
    j++;
    cad[i+j] = '\0';

  // agrega_terminador(cad);

}
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
   // *s = '\0';
   // ++s;
   // *s = '\n';
    return i;  /** Retorna la cantidad de caracteres ingresados **/

/** Agrega_terminador **/
//void agrega_terminador(char *s)
//{
//    int i;
//    for(i = 0; *s != '\0'; ++i, ++s)
//        ;

//    s--; /** Se va un lugar para atras y se agrega el terminador nulo en
//         lugar de la ultima coma **/
//    *s = '\0';
//}

/** generar_contraseña **/
//char *generar_contraseña(void)
//{
//    char *p;
///    p = generate_key(NUM_CARACTERES);
    //cad++;

    //llena_arreglo(p, MAXLINE);
//}
char *generate_key(int max){
    // diccionario de caracteres
    char diccionario[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', ' ',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'Ñ', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z',
        '!', '?', '¿','#', '@', '%', '&', '*', '-', '{', '}', '[', ']',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    srand(getpid()); // genero una semilla para poder tener un numero random
    char *key = malloc(sizeof(char)+max); // le doy la cantidad de memoria a la variable que guardara la clave
    int len = (int)strlen(diccionario); // obtengo la longitud de caracteres del diccionario

    for(int i = max; i >= 0; i--){
        key[i] = diccionario[rand() % len]; // se genera la clave aleatoria
    }

    return key;
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
/** ver datos permite ver por pantalla **/
void ver_datos(int argumento, char *arch)
{
    int i;
    int j = 0;
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
        if(j == 0){
          printf("          ");

          for(i = 0; *line != '\0'; line++){
              if(*line == ',')
                  printf("               ");
              else{

                  printf("%c", *line);
              }
          }
         }
        else {
           printf("%d- '%s'\n",j ,line);
           }
        j++;
        //for(i = 0; i < csvnfield(); i++){
          //  printf("campo[%d] = '%s'\n", i, csvfield(i));
            //if(i >= 0 && i <=1)
            //    ;
            //else
              // printf(" %s ", csvfield(i));
        //}
        printf("\n");

    }
}
void borrar_clave(void)
{

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

