#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ver_clave(int argumento, char *cad);
void agregar_clave(int argumento, char *cad);
void borrar_clave(void);
void salir(void);

FILE *fp;

int main(int argc, char *argv[])
{
    char opcion;
    int c;

    do{
        printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf(" A- Ver claves\n");
        printf(" B- Agregar clave\n");
        printf(" C- Borrar clave\n");
        printf(" D- Salir del programa\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++\n");

        scanf("%c", &opcion);
        while(getchar() != '\n'); //Limpia el buffer de entrada de stdin

        printf("opcion = %c \n", opcion);
        switch(opcion){
			case 'A':
			case 'a':
                ver_clave(argc, argv[1]);
                printf("Estamos en la rama usando-csv");
            break;

            case 'b':
            case 'B':
                agregar_clave(argc, argv[1]);
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
void ver_clave(int argumento, char *cad)
{
    char car;
    if(argumento != 2){
                    printf("Has olvidade introducir el nombre del archivo.\n");
                    exit(1);
                }
                if((fp = fopen(cad, "r")) == NULL){
                    printf("No se puede abrir el archivo.\n");
                    exit(1);
                }

	car = getc(fp);  /** Leer un caracter **/
    while(car != EOF){
        putchar(car); /** Lo muestra en la pantalla **/
        car = getc(fp);
    }
    fclose(fp);
}
/*********************************************************/
void agregar_clave(int argumento, char *cad)
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
        gets(cadena);
        strcat(cadena, "\n");  /** añade un salto de línea **/
        fputs(cadena, fp);
    }while(*cadena != '\n');
    fclose(fp);
}
/*********************************************************/
void borrar_clave(void)
{

}
/*********************************************************/
void salir(void)
{

}
