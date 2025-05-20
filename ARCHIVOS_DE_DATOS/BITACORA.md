# ARCHIVOS DE DATOS 
## Funciones:
- `fopen()`: Abre un archivo.
- `fclose()`: Cierra un archivo.
- `fgets()`: Lee una cadena de un archivo.
- `fputs()`: Escribe una cadena de un archivo.
- `fseek()`: Busca un byte especifico de un archivo.
- `fprintf()`: Escribe una salida con formato en el archivo.
- `fscanf()`: Lee una entrada con formato desde el archivo.
- `feonf()`: Devuelve cierto si se llega al final del archivo.
- `ferror()`: Devuelve cierto si se produce un error.
- `rewind()`: Coloca el localizador en posición del archivo al principio del mismo.
- `remove()`: Borra un archivo.
- `fflush()`: Vacia un archivo.

## Ejercicio 1:
- Abrir y cerrar un archivo de texto.     
- Almacenar caracteres usando las instrucciones getc y fgetc para lectura de caracteres, así como putc y fputc para escritura de caracteres.     
**R//**    
```
#include <stdio.h>​

void main(void)​
{​
char p1;​
FILE *ar;​
ar = fopen(”arc.txt”, ”w”); if (ar != NULL) ​
   {​
   while ((p1=getchar()) != ‘\n’)​
   fputc(p1, ar); ​
   fclose(ar); /* Se cierra el archivo. */​
   }​
else​
   printf(”No se puede abrir el archivo”);​
}
```

## Ejecicio 2:
- Leer caracteres de un archivo​   
- Usar la instrucción feof() para verificar el fin del archivo     
**R//**    
```
#include <stdio.h>​
void main(void)​
{​
char p1;​
FILE *ar;​
if((ar = fopen(”arc.txt”, ”r”)) != NULL) ​
   {​
   while (!feof(ar)) ​
   {​
   p1 = fgetc(ar); /* Lee el caracter del archivo. */​
   putchar(p1); /* Despliega el caracter en la pantalla. */​
   }​
   fclose(ar);​
   }​
else​
    printf(”No se puede abrir el archivo”);​
}
```
     
## Ejercicio 3:
- Escribe un programa en C que, al recibir como datos la matrícula y cinco calificaciones de N alumnos de un curso universitario, almacene la información en el archivo tal como se presenta a continuación​:

Datos: N    
       MAT<sub>1</sub>, CAL<sub>1,1</sub>, CAL<sub>1.2</sub>, CAL<sub>1,3</sub>, CAL<sub>1,4</sub>, CAL<sub>1,5</sub>     
       MAT<sub>2</sub>, CAL<sub>2,1</sub>, CAL<sub>2.2</sub>, CAL<sub>2,3</sub>, CAL<sub>2,4</sub>, CAL<sub>2,5</sub>  
                         .   
                         .   
                         .   
       MAT<sub>N</sub>, CAL<sub>N,1</sub>, CAL<sub>N.2</sub>, CAL<sub>N,3</sub>, CAL<sub>N,4</sub>, CAL<sub>N,5</sub>      
     
- Dónde N es una variable de tipo entero que representa el número de alumnos,1 ≤ N ≤ 35​

- MATi es una variable de tipo entero que representa la matrícula del alumno i​

- CAL es una variable de tipo real que indica la calificación j del alumno i​
     
**R//**   
```
#include <stdio.h>​
void main(void)​
{​
int i, j, n, mat;​
float cal;​
FILE *ar;​
printf(”\nIngrese el número de alumnos: ”);​
scanf(”%d”, &n); /* el valor ingresado debe estar comprendido entre 1 y 35. */​
if ((ar = fopen(”arc8.txt”, ”w”)) != NULL)​
     {​
     fprintf(ar,”%d ”, n); /* Se escribe el número de alumnos en el archivo. */​
     for (i=0; i<n; i++)​
         {​
         printf(”\nIngrese la matrícula del alumno %d: ”, i+1);​
         scanf(”%d”, &mat);​
         fprintf(ar,”\n%d ”, mat); /* Se escribe la matrícula en el archivo. */​
         for (j=0; j<5; j++)​
             {​
             printf(”\nCalificación %d: ”, j+1);​
             scanf(”%f”, &cal);​
             fprintf(ar,”%.2f ”, cal); /* Se escriben las calificaciones en el archivo. */​
             }​
         }​
     fclose(ar);​
     }​
else​
     printf(”No se puede abrir el archivo”);​

}
```
     
## Ejercicio 4:
- Escribe un programa en C que lea de un archivo el número de alumnos (N), el número de la matrícula y las cinco calificaciones de cada uno de ellos, y que imprima en pantalla la matrícula y el promedio de cada alumno.     
**R//**    
```
#include <stdio.h>​
void main(void)​
{​
int i, j, n, mat;​
float cal, pro;​
FILE *ar;​
if ((ar = fopen(”arc9.txt”, ”r”)) != NULL)​
     {​
     fscanf(ar, ”%d”, &n); /* Se lee el valor de n. */​
     for (i = 0; i < n; i++)​
         {
         fscanf(ar, ”%d”, &mat); /* Se lee la matrícula de cada alumno. */​
         printf(”%d\t”, mat);​
         pro = 0;​
         for (j=0; j<5; j++) {​
             fscanf(ar, ”%f”, &cal); pro += cal;​
             }​
         printf(”\t %.2f ”, pro / 5); /* Se escribe el promedio de cada alumno. */​
         printf(”\n”);​
         }​
         fclose(ar);​
     }​
else​
     printf(”No se puede abrir el archivo”);​
}
```
    
## Ejercicio 5:
- Se tiene un archivo de texto con el código de ciertos empleados en tres ciudades diferentes. Se desea realizar el incremento a dichos empleados, de acuerdo a la ciudad en la que se encuentran. ​
- Los códigos de las ciudades son:​
  - Buenos Aires: 284​
  - Lima: 395​
  - Quito: 774​
- El código de los empleados consta de 5 dígitos. Los primeros tres XXX corresponden al código de la ciudad y los dos siguientes a un consecutivo. ​
- Podrían existir los siguientes códigos de empleados:​
   - 39503: corresponde al empleado 03 de la ciudad de Lima​
- En el archivo, frente a cada empleado, separado por un espacio en blanco está su salario en dólares (número real)

**¿Qué hay que hacer con el archivo?​**   
    
- Se debe crear un programa que permita leer dicho archivo y realizar los siguiente cambios:​
- A los empleados se les realizará un aumento de sueldo según la ciudad donde residen, así:​
   - Buenos Aires: incremento del 15%​
   - Lima: incremento del 17%​
   - Quito: incremento del 20%​
- El nuevo valor debe quedar registrado en el mismo archivo

### Solucion:
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *temporal;
    int codigo;
    float salario, nuevoSalario;

    entrada = fopen("empleados.txt", "r");
    temporal = fopen("temporal.txt", "w");

    if (entrada == NULL || temporal == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fscanf(entrada, "%d %f", &codigo, &salario) == 2) {
        int ciudad = codigo / 100;  // Extrae los 3 primeros dígitos

        if (ciudad == 284) {
            nuevoSalario = salario * 1.15;
        } else if (ciudad == 395) {
            nuevoSalario = salario * 1.17;
        } else if (ciudad == 774) {
            nuevoSalario = salario * 1.20;
        } else {
            nuevoSalario = salario; // Ciudad desconocida
        }

        fprintf(temporal, "%d %.2f\n", codigo, nuevoSalario);
    }

    fclose(entrada);
    fclose(temporal);

    // Reemplazar archivo original
    remove("empleados.txt");
    rename("temporal.txt", "empleados.txt");

    printf("Archivo actualizado con nuevos salarios.\n");

    return 0;
}
```
