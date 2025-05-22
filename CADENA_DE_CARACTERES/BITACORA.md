# CADENAS DE CARACTERES 
     
## Actividad 1: Invesstigación práctica 
### Librería `<string.h>`
1. `strlen`   
¿Para qué sirve?    
Calcula la longitud de una cadena (sin contar el '\0').    
   
Prototipo:   
`size_t strlen(const char *str);`     
    
Parámetros:     

`str`: puntero a la cadena.    
     
Ejemplo:     
```
#include <stdio.h>
#include <string.h>

int main() {
    char palabra[] = "Hola";
    printf("Longitud: %lu\n", strlen(palabra));
    return 0;
}
```    
2. `strcpy`    
¿Para qué sirve?   
Copia una cadena a otra.   
    
Prototipo:   
`char *strcpy(char *dest, const char *src);`   
    
Parámetros:   
   
`dest`: destino.    
    
`src`: origen.    
    
Ejemplo:     
```   
#include <stdio.h>
#include <string.h>

int main() {
    char destino[20];
    strcpy(destino, "Copia exitosa");
    printf("%s\n", destino);
    return 0;
}
```    
3. `strncpy`     
¿Para qué sirve?    
Copia los primeros n caracteres de una cadena.    
     
Prototipo:    
`char *strncpy(char *dest, const char *src, size_t n);`    
    
Ejemplo:
```
#include <stdio.h>
#include <string.h>

int main() {
    char destino[10];
    strncpy(destino, "Ejemplo", 5);
    destino[5] = '\0'; // Agregar nulo manual
    printf("%s\n", destino);
    return 0;
}
```
4. `strcat`     
¿Para qué sirve?    
Concatena cadenas.    
     
Prototipo:    
`char *strcat(char *dest, const char *src);`     
    
Ejemplo:     
```
#include <stdio.h>
#include <string.h>

int main() {
    char mensaje[20] = "Hola ";
    strcat(mensaje, "mundo");
    printf("%s\n", mensaje);
    return 0;
}
```
5. `strncat`     
¿Para qué sirve?     
Concatena hasta n caracteres.     
     
Prototipo:    
`char *strncat(char *dest, const char *src, size_t n);`     
     
Ejemplo:    
```
#include <stdio.h>
#include <string.h>

int main() {
    char mensaje[20] = "Hola ";
    strncat(mensaje, "mundo cruel", 5);
    printf("%s\n", mensaje);  // "Hola mundo"
    return 0;
}
```
6. `strcmp`    
¿Para qué sirve?    
Compara dos cadenas (sensitivo a mayúsculas).    
      
Prototipo:    
`int strcmp(const char *s1, const char *s2);`    
     
Ejemplo:    
```
#include <stdio.h>
#include <string.h>

int main() {
    printf("%d\n", strcmp("hola", "hola"));   // 0
    printf("%d\n", strcmp("hola", "mundo"));  // < 0
    return 0;
}
```
7. `strncmp`    
¿Para qué sirve?    
Compara hasta n caracteres.    
    
Prototipo:    
`int strncmp(const char *s1, const char *s2, size_t n);`   
    
Ejemplo:   
```
#include <stdio.h>
#include <string.h>

int main() {
    printf("%d\n", strncmp("hola", "holanda", 3)); // 0
    return 0;
}
```
8. `strchr`     
¿Para qué sirve?     
Busca un carácter en una cadena.    
    
Prototipo:    
`char *strchr(const char *str, int c);`    
    
Ejemplo:     
```
#include <stdio.h>
#include <string.h>

int main() {
    char *ptr = strchr("banana", 'n');
    printf("Primera 'n': %s\n", ptr);
    return 0;
}
```
9. `strstr`    
¿Para qué sirve?    
Busca una subcadena dentro de otra.    
     
Prototipo:    
`char *strstr(const char *haystack, const char *needle);`      
     
Ejemplo:     
```
#include <stdio.h>
#include <string.h>

int main() {
    char *ptr = strstr("programacion en C", "en");
    printf("Subcadena encontrada: %s\n", ptr);
    return 0;
}
```
10. `strtok`    
¿Para qué sirve?    
Divide una cadena en tokens.    
     
Prototipo:   
`char *strtok(char *str, const char *delim);`    
      
Ejemplo:      
```
#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "uno,dos,tres";
    char *token = strtok(cadena, ",");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}   
```
### Librería `<ctype.h>`   
1. `isalpha`    
¿Para qué sirve?     
Verifica si es letra (A-Z o a-z).    
     
Prototipo:      
`int isalpha(int c);`     
     
Ejemplo:       
```
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("%d\n", isalpha('A')); // 1
    printf("%d\n", isalpha('3')); // 0
    return 0;
}
```
2. `isdigit`    
¿Para qué sirve?    
Verifica si es un dígito (0-9).     
     
Prototipo:    
`int isdigit(int c);`    
     
Ejemplo:            
```
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("%d\n", isdigit('9')); // 1
    printf("%d\n", isdigit('a')); // 0
    return 0;
}
```
3. `isalnum`    
¿Para qué sirve?     
Verifica si es alfanumérico (letra o número).     
      
Prototipo:      
`int isalnum(int c);`   

4. `islower / isupper`      
¿Para qué sirven?     
Verifican si el carácter es minúscula o mayúscula.     

Prototipos:    
`int islower(int c);`        
`int isupper(int c);`     
      
5. `tolower / toupper`      
¿Para qué sirven?      
Convierte una letra mayúscula a minúscula o viceversa.      
     
Prototipos:     
`int tolower(int c);`       
`int toupper(int c);`      
       
Ejemplo:              
```
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'M';
    printf("Minúscula: %c\n", tolower(c)); // m
    printf("Mayúscula: %c\n", toupper('n')); // N
    return 0;
} 
```
## Ejemplo guiado: Saludo personalizado   
Vamos a realizar un programa que pida tu nombre y luego te salude.      
Primero, declara un arreglo de caracteres para almacenar tu nombre:     
      
```
char nombre[20]; 
```
Luego, pide al usuario que ingrese su nombre:   
```
printf("Ingresa tu nombre: ");
fgets(nombre, sizeof(nombre), stdin);
```
​   
Usamos `fgets()` porque es seguro y limita la cantidad de caracteres que podemos leer.    
A continuación, elimina el salto de línea (`'\n'`)   que introduce `fgets()`:   
```
nombre[strlen(nombre)-1] = '\0';
//nombre[strcspn(nombre, "\n")] = '\0';
```
​   
Ahora, prepara un saludo personalizado:      
```
char mensaje[30] = "Hola, ";
strncat(mensaje, nombre, sizeof(mensaje) - strlen(mensaje) - 1);
```
​   
Finalmente, imprime el saludo y la longitud del nombre:     
```
printf("%s\n", mensaje);
printf("Tu nombre tiene %d letras.\n", strlen(nombre));
```
## Preguntas de control

Responde estas preguntas para asegurarte de que has comprendido bien el tema:   

1. ¿Por qué `sizeof("Hola")` devuelve 5, pero `strlen("Hola")` devuelve 4?     
**R//** `sizeof("Hola")` incluye todos los caracteres más el carácter nulo `'\0'`, que marca el final de la cadena. Por eso devuelve 5.    
        
2. ¿Cuál es la diferencia práctica entre declarar una cadena como arreglo (`char saludo[]`) y como puntero (`char *saludo`)?       
**R//** El arreglo crea una copia editable; el puntero apunta a una cadena constante que puede no ser modificable.    
     
3. ¿Cómo evitas un "buffer overflow" al copiar o concatenar cadenas?     
**R//** 
- Usando funciones seguras con límite de caracteres, como:     
  - `strncpy()` en lugar de `strcpy()`   
  - `strncat()` en lugar de `strcat()`      
              
- Asegurándote de que el buffer destino tenga suficiente espacio (incluyendo el carácter nulo `'\0'`).    
       
- Si reservas memoria dinámicamente, calcula con cuidado el tamaño necesario.      
         
4. ¿Qué hace exactamente la función `strcspn()` y por qué es útil usarla junto con `fgets()`?       
**R//** La función `strcspn()` busca la primera aparición de cualquier carácter de un conjunto en una cadena y devuelve su posición. Es útil con `fgets()` porque permite localizar el salto de línea \n que fgets suele almacenar, para luego reemplazarlo por `'\0'` y así limpiar correctamente la entrada del usuario.       
    
5. ¿Qué pasos debes seguir para manejar correctamente una cadena reservada dinámicamente con `malloc()`?      
**R//** Para manejar cadenas reservadas con `malloc()`, primero se debe calcular el tamaño necesario y usar `malloc` para reservar memoria. Luego, se debe verificar que el puntero no sea `NULL`. Una vez utilizada la cadena, se debe liberar con `free()` y opcionalmente poner el puntero en `NULL` para evitar errores posteriores o fugas de memoria.    
    
## Ejercicios prácticos

Realiza los siguientes ejercicios para reforzar tus conocimientos:     
     
1. **Contar vocales**: Escribe un programa que cuente el número de vocales en una cadena.    
**R//**     
```
#include <stdio.h>
#include <ctype.h>

int contarVocales(const char *cadena) {
    int contador = 0;
    while (*cadena) {
        char c = tolower(*cadena);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

int main() {
    char texto[100];
    printf("Ingresa una cadena: ");
    fgets(texto, sizeof(texto), stdin);

    printf("Cantidad de vocales: %d\n", contarVocales(texto));
    return 0;
}

```   
     
2. **Invertir cadena**: Implementa una función segura que invierta una cadena en otro arreglo.     
**R//**     
```
#include <stdio.h>
#include <string.h>

void invertirCadena(const char *original, char *invertida) {
    int len = strlen(original);
    for (int i = 0; i < len; i++) {
        invertida[i] = original[len - 1 - i];
    }
    invertida[len] = '\0'; // terminador nulo
}

int main() {
    char texto[100], invertida[100];
    printf("Ingresa una cadena: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    invertirCadena(texto, invertida);
    printf("Cadena invertida: %s\n", invertida);
    return 0;
}

```   
     
3. **Palíndromo**: Detecta si una frase es un palíndromo (sin considerar espacios y puntuación).     
**R//**     
```
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int esPalindromo(const char *cadena) {
    char limpio[100], inverso[100];
    int j = 0;
    for (int i = 0; cadena[i]; i++) {
        if (isalnum(cadena[i])) {
            limpio[j++] = tolower(cadena[i]);
        }
    }
    limpio[j] = '\0';

    // Invertir
    for (int i = 0; i < j; i++) {
        inverso[i] = limpio[j - 1 - i];
    }
    inverso[j] = '\0';

    return strcmp(limpio, inverso) == 0;
}

int main() {
    char frase[100];
    printf("Ingresa una frase: ");
    fgets(frase, sizeof(frase), stdin);

    if (esPalindromo(frase)) {
        printf("Es un palíndromo.\n");
    } else {
        printf("No es un palíndromo.\n");
    }
    return 0;
}

```   
     
4. **Conversión ASCII**: Convierte todas las letras minúsculas de una cadena a mayúsculas sin usar funciones de biblioteca.      
**R//**     
```
#include <stdio.h>

void convertirMayusculas(char *cadena) {
    while (*cadena) {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - 32;
        }
        cadena++;
    }
}

int main() {
    char texto[100];
    printf("Ingresa una cadena: ");
    fgets(texto, sizeof(texto), stdin);

    convertirMayusculas(texto);
    printf("En mayúsculas: %s", texto);
    return 0;
}

```   
     
5. **Tokenizador**: Implementa una versión simplificada de `strtok()` que separe una cadena por coma, punto y coma o espacios.     
**R//**     
```
#include <stdio.h>

void tokenizar(char *cadena) {
    char *ptr = cadena;
    while (*ptr) {
        // Separadores: espacio, coma, punto y coma
        if (*ptr == ' ' || *ptr == ',' || *ptr == ';') {
            *ptr = '\0';
        }
        ptr++;
    }

    ptr = cadena;
    while (*ptr) {
        printf("Token: %s\n", ptr);
        ptr += strlen(ptr) + 1; // avanzar al siguiente token
    }
}

int main() {
    char texto[100];
    printf("Ingresa una frase con separadores (, ; espacio): ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    tokenizar(texto);
    return 0;
}

```   
     