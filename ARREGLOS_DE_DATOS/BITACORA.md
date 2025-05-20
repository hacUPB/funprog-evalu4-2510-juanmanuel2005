# ARREGLOS DE DATOS
## Ejercicio 1
Declara un arreglo, y llénalo con datos. Puedes utilizar el ejemplo anterior. Luego imprime en pantalla las posiciones de memoria correspondientes a cada posición.     
```
#include <stdio.h>

int main() {
    int datos[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    printf("Contenido y direccion de memoria de cada elemento:\n");
    for (int i = 0; i < 10; i++) {
        printf("datos[%d] = %d \t direccion: %p\n", i, datos[i], (void*)&datos[i]);
    }

    return 0;
}
```
## Preguntas de control
1. ¿Qué valor contiene el siguiente dato: `dato[5]`, si el arreglo se inicializa de la siguiente manera: `int datos[6] = {5, 82, 41};`?     
**R//**  El valor de `dato[5]` será 0.     
     
2. ¿Cómo determinar el número de elementos en un arreglo cuando su tamaño no se especifica explícitamente?        
**R//** Contando manualmente la cantidad de valores con los que fue inicializado el arreglo.    

## Ejercicios prácticos  

### Ejercicio 1

- Crear un array de 10 números enteros.      
- Rellenarlo con números consecutivos desde el 11 hasta el 20.        
- Imprimirlos en pantalla en orden descendente.        
**R//**    
```
#include <stdio.h>

int main() {
    int numeros[10];
    
    // Rellenar el arreglo con números del 11 al 20
    for (int i = 0; i < 10; i++) {
        numeros[i] = 11 + i;
    }

    // Imprimir en orden descendente
    printf("Numeros en orden descendente:\n");
    for (int i = 9; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }

    return 0;
}
```

### Ejercicio 2

- Crear un array que contenga números pares desde el 2 hasta el 10.   
- Imprimir los valores en orden ascendente.     
**R//**    
```
#include <stdio.h>

int main() {
    int pares[5] = {2, 4, 6, 8, 10};

    printf("Numeros pares en orden ascendente:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", pares[i]);
    }

    return 0;
}
```

### Ejercicio 3

- Leer desde teclado 10 números.      
- Calcular y mostrar la suma, resta y multiplicación acumulada de esos números.      
**R//**    
```
#include <stdio.h>

int main() {
    int numeros[10];
    int suma = 0, resta = 0;
    int multiplicacion = 1;

    // Leer los 10 números
    for (int i = 0; i < 10; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Calcular operaciones
    for (int i = 0; i < 10; i++) {
        suma += numeros[i];

        if (i == 0) {
            resta = numeros[i];
        } else {
            resta -= numeros[i];
        }

        multiplicacion *= numeros[i];
    }

    // Mostrar resultados
    printf("Suma: %d\n", suma);
    printf("Resta: %d\n", resta);
    printf("Multiplicacion: %d\n", multiplicacion);

    return 0;
}
```

### Ejercicio 4

- Leer 10 números desde teclado, almacenando los primeros 5 en un array y los últimos 5 en otro.     
- Combinar ambos arrays en un tercer array e imprimir el contenido.      
**R//**     
```
#include <stdio.h>

int main() {
    int primeros[5], ultimos[5], combinados[10];

    // Leer los primeros 5 números
    printf("Ingrese los primeros 5 numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &primeros[i]);
    }

    // Leer los últimos 5 números
    printf("Ingrese los ultimos 5 numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 6);
        scanf("%d", &ultimos[i]);
    }

    // Combinar ambos arreglos
    for (int i = 0; i < 5; i++) {
        combinados[i] = primeros[i];
        combinados[i + 5] = ultimos[i];
    }

    // Imprimir arreglo combinado
    printf("Contenido del arreglo combinado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", combinados[i]);
    }

    return 0;
}
```
## Ejercicios Adicionales

### Ejercicio 5

- Crear un arreglo unidimensional para almacenar notas de 24 estudiantes.    
- Escribir una función para calcular:    
    - El promedio general del curso.     
    - La cantidad de estudiantes aprobados (nota ≥ 3).     
    - La cantidad de estudiantes reprobados (nota < 3).    
    - La cantidad de estudiantes con nota igual o superior a 4.    
**R//**  
```
#include <stdio.h>

#define N 24

// Función para calcular estadísticas
void analizarNotas(float notas[], int n) {
    float suma = 0;
    int aprobados = 0, reprobados = 0, sobresalientes = 0;

    for (int i = 0; i < n; i++) {
        suma += notas[i];
        if (notas[i] >= 3.0)
            aprobados++;
        else
            reprobados++;

        if (notas[i] >= 4.0)
            sobresalientes++;
    }

    float promedio = suma / n;

    printf("Promedio general: %.2f\n", promedio);
    printf("Estudiantes aprobados: %d\n", aprobados);
    printf("Estudiantes reprobados: %d\n", reprobados);
    printf("Estudiantes con nota >= 4.0: %d\n", sobresalientes);
}

int main() {
    float notas[N];

    printf("Ingrese las notas de los %d estudiantes:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Nota del estudiante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    analizarNotas(notas, N);

    return 0;
}
```
### Ejercicio 6

- Utilizar un arreglo bidimensional para calcular la nota definitiva de estudiantes, dados los porcentajes en la primera fila y las notas en filas sucesivas.     
- Mostrar la nota definitiva en la última columna.     
**R//**    
```
#include <stdio.h>

#define ESTUDIANTES 3
#define EVALUACIONES 7

int main() {
    // Porcentajes
    float porcentajes[EVALUACIONES] = {16, 16, 16, 10, 10, 16, 16};

    // Notas de estudiantes [fila][columna]
    float notas[ESTUDIANTES][EVALUACIONES] = {
        {3.20, 2.50, 4.50, 4.00, 2.60, 3.80, 2.00},
        {4.50, 4.20, 4.60, 5.00, 5.00, 4.30, 3.80},
        {2.50, 3.00, 3.40, 2.00, 1.80, 2.00, 1.60}
    };

    // Calcular nota definitiva
    for (int i = 0; i < ESTUDIANTES; i++) {
        float definitiva = 0;
        for (int j = 0; j < EVALUACIONES; j++) {
            definitiva += notas[i][j] * (porcentajes[j] / 100);
        }
        printf("Nota definitiva del estudiante %d: %.2f\n", i + 1, definitiva);
    }

    return 0;
}
```
### Preguntas de comprensión

1. ¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro?    
**R//** Se pasa la dirección del primer elemento del arreglo.     
     
2. ¿Qué diferencia hay entre declarar el parámetro como `int arr[]` y `int *arr`?    
**R//** Ninguna diferencia real en el contexto de una función. Ambas formas indican que se está recibiendo un puntero al primer elemento del arreglo.    
    
3. ¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?     
**R//** Como se pasa la dirección, cualquier modificación al arreglo dentro de la función afecta al arreglo original.    
    
### Ejercicios propuestos

1. Crear una función que reciba un arreglo de enteros y su tamaño, y calcule el promedio de sus valores.      
**R//**     
```
float calcularPromedio(int arr[], int tamaño) {
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += arr[i];
    }
    return (float)suma / tamaño;
}

```
2. Escribir una función que reciba un arreglo y lo ordene en orden ascendente usando el método burbuja.    
**R//**     
```
void ordenarBurbuja(int arr[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

```
3. Crear una función que reciba un arreglo y devuelva el valor máximo contenido en él.     
**R//**     
```
int encontrarMaximo(int arr[], int tamaño) {
    int max = arr[0];
    for (int i = 1; i < tamaño; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

```

---

## Preguntas finales para reforzar el aprendizaje

1. ¿Cuál es exactamente la diferencia entre un arreglo y un puntero?     
**R//**       
| Arreglo                          | Puntero                             |
| -------------------------------- | ----------------------------------- |
| Tiene un tamaño fijo             | Puede apuntar a cualquier dirección |
| Se reserva espacio al declararlo | Puede cambiar de dirección          |
| No se puede reasignar            | Se puede modificar                  |    
     
2. ¿Cómo están almacenados en la memoria los elementos de una matriz?    
**R//** Están almacenados en forma lineal y continua en memoria.    
      
3. ¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?    
**R//** 
- No acceder fuera del rango válido del arreglo.   
- Asegurarse de que el puntero esté inicializado.   
- Evitar modificar el puntero si se va a usar más adelante.   
- Usar correctamente el tamaño del arreglo al recorrerlo.   