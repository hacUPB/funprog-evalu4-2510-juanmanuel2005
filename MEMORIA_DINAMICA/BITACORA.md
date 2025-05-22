# MEMORIA DINAMICA
###  Se estudió: Diferencia entre datos estáticos y dinámicos      
       
Los datos estáticos se declaran con tamaño fijo en tiempo de compilación. Por ejemplo, un arreglo `int` a [10]; ya no puede cambiar su tamaño durante la ejecución. En cambio, los datos dinámicos permiten reservar memoria en tiempo de ejecución según sea necesario, evitando desperdicio o falta de memoria.
  
### Se estudió: La función `sizeof() `
        
Esta función permite conocer cuántos bytes ocupa un tipo de dato o variable en memoria. Es útil para calcular el tamaño a reservar con funciones dinámicas.   
     
**Prototipo:**    
```
 int sizeof (Variable o tipo de dato); 
int a=2 , v[2];
 printf("%d",sizeof(a)); //imprime 4
 printf("%d",sizeof(v[0])); //imprime 4
 printf("%d",sizeof(v)); //imprime 8
```
   
### Se estudió: La función `malloc()`   
       
`malloc()` permite reservar memoria en tiempo de ejecución. Retorna un puntero void * al inicio del bloque de memoria reservado. Es necesario convertir este puntero al tipo correcto.      
      
**Prototipo:**       
```
void *Puntero=(tipo_var*)malloc(int tamaño);
```
    
### Se estudió: La función `free()`  
    
Después de usar memoria dinámica, se debe liberar con `free()` para evitar fugas de memoria.     

**Prototipo:**
```
 free( puntero );
```
     
### Ejemplo:
```
 #include <stdio.h>
 int main(void)
 {
    int i;    
    int *puntero,tamano;
    printf("ingrese tamaño:");
    scanf("%d",&tamano);
    printf("\n");
    puntero = (int *) malloc(tamano*sizeof(int));

    for(i=0;i<tamano;i++){
       puntero[i]=i+1;
       printf("%d\n",puntero[i]);
   }
   free(puntero);   
   system("pause");
   return 0;
 }

```
       
### Se estudió: La función `calloc()`    
    
`calloc()` también reserva memoria dinámica, pero además inicializa todos los elementos a cero.    
    
**Funcion:**    
```
void * calloc (int nitems, int tamaño);
```

### Se estudió: La función realloc()
    
`realloc()` permite cambiar el tamaño de un bloque de memoria previamente reservado con `malloc` o `calloc`.      
     
**Funcion:**    
```
void * realloc (void * ptr, int tamaño)
```
    
### Ejemplo:
```
 #include <stdio.h>
 #include <stdlib.h>
 int main()
 {
    char *str;
    /* Initial memory allocation */
    str = (char *) malloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %u\n", str, str);

    /* Reallocating memory */
    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);

   return(0);
 }
```