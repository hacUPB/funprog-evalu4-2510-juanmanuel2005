# RETO 
## Análisis del problema
Para este reto se desarrolló un programa llamado Analizador de Texto, el cual permite leer un archivo .txt, analizar su contenido, realizar modificaciones y guardar resultados. Este programa integra los conceptos de archivos de texto, cadenas de caracteres, memoria dinámica, bucles, condicionales y funciones.   
  
El programa se organiza en un menú interactivo con las siguientes opciones:   

### 1. Cargar archivo de texto
Permite al usuario ingresar el nombre de un archivo `.txt`.    
El contenido del archivo se lee completamente en memoria utilizando `malloc` y se almacena en un arreglo dinámico de caracteres.     
Antes de cargar un nuevo archivo, se libera la memoria ocupada por el anterior con `free()`.           
     
### 2. Calcular estadísticas
Calcula y muestra por consola:         
- Número total de caracteres (excluyendo saltos de línea \n).
- Número de palabras (considerando separaciones por espacios).
- Número de espacios.
- Número de líneas (se cuentan con los saltos de linea \n).

     
El análisis se realiza recorriendo el arreglo de caracteres previamente cargado.      
     
### 3. Frecuencia de vocales   
Cuenta la cantidad de veces que aparece cada vocal (a, e, i, o, u), combinando mayúsculas y minúsculas.     
Este conteo se hace sin funciones externas, recorriendo cada carácter y evaluando con `tolower()`.     
         
### 4. Reemplazar palabra
Permite al usuario ingresar una palabra a buscar y otra para reemplazarla.   
El texto completo es recorrido y se crean dinámicamente nuevas cadenas con `malloc` para contener el resultado modificado.      
Si no se encuentra la palabra buscada, se informa al usuario. Si sí se encuentra, se reemplaza en todas sus apariciones.    

### 5. Guardar resultados
Permite guardar todos los resultados generados en un nuevo archivo `.txt`.     
El usuario elige el nombre del archivo de salida.     
Se guarda:     
- Estadísticas del texto.   
- Frecuencia de vocales.    
- Texto final (modificado o no).    
      
Todo se guarda usando `fprintf()` y se confirma al usuario que el archivo fue creado exitosamente.     
    
### 6. Salir del programa
Libera la memoria utilizada y termina la ejecución de forma segura.   

## Tabla de variables utilizadas

| Variable          | Tipo      | Entrada/Salida | Función/Sección          | Descripción |
|-------------------|-----------|----------------|--------------------------|-------------|
| `opcion`          | `int`     | Entrada        | `main()`                | Selección del menú |
| `contenido`       | `char*`   | Salida         | `main()`                | Texto cargado en memoria |
| `nombreArchivo`   | `char[100]` | Entrada      | Caso 1                  | Nombre del archivo a cargar |
| `chars`           | `int`      | Salida         | Caso 2                  | Total de caracteres |
| `palabras`        | `int`      | Salida         | Caso 2                  | Total de palabras |
| `espacios`        | `int`      | Salida         | Caso 2                  | Total de espacios |
| `lineas`          | `int`      | Salida         | Caso 2                  | Total de líneas |
| `a, e, i, o, u`   | `int`      | Salida         | Caso 3                  | Contadores de vocales |
| `buscar`          | `char[50]` | Entrada        | Caso 4                  | Palabra a buscar |
| `reemplazo`       | `char[50]` | Entrada        | Caso 4                  | Palabra de reemplazo |
| `nuevoTexto`      | `char*`    | Salida         | Caso 4                  | Texto modificado |
| `nombreSalida`    | `char[100]` | Entrada      | Caso 5                  | Nombre del archivo de salida |
| `archivo`         | `FILE*`    | Local          | `leerArchivo()`         | Puntero al archivo |
| `tamano`          | `long`     | Local          | `leerArchivo()`         | Tamaño del archivo |
| `bytesLeidos`     | `size_t`   | Local          | `leerArchivo()`         | Bytes leídos |
| `enPalabra`       | `int`      | Local          | `calcularEstadisticas()`| Flag para detectar palabras |
| `contador`        | `int`      | Local          | `reemplazarPalabra()`    | Ocurrencias encontradas |
| `longBuscar`      | `int`      | Local          | `reemplazarPalabra()`    | Longitud palabra a buscar |
| `longReemplazo`   | `int`      | Local          | `reemplazarPalabra()`    | Longitud palabra nueva |
| `longTexto`       | `int`      | Local          | `reemplazarPalabra()`    | Longitud texto original |
| `nuevoTamano`     | `int`      | Local          | `reemplazarPalabra()`    | Tamaño del nuevo texto |
| `ptr`, `inicio`, `pos` | `char*` | Local       | `reemplazarPalabra()`    | Punteros para manipulación |
| `c`               | `char`     | Local          | `calcularVocales()`      | Carácter actual en minúscula |
| `idx`             | `int`      | Local          | `calcularVocales()`      | Índice para recorrido |


## Pseudocodigo
```
INICIO
    MOSTRAR menú con 6 opciones
    LEER opción del usuario
    
    SI opción es 1:
        PEDIR nombre de archivo
        LEER archivo a memoria
        GUARDAR en variable texto
    SI opción es 2:
        CONTAR caracteres, palabras, líneas
        MOSTRAR resultados
    SI opción es 3:
        CONTAR vocales a,e,i,o,u
        MOSTRAR conteo
    SI opción es 4:
        PEDIR palabra a cambiar
        PEDIR palabra nueva
        REEMPLAZAR en texto
    SI opción es 5:
        PEDIR nombre para guardar
        ESCRIBIR estadísticas + texto
    SI opción es 6:
        LIBERAR memoria
        SALIR
FIN

Caso 1: Cargar archivo
 PEDIR al usuario el nombre del archivo (.txt)
 ABRIR el archivo en modo lectura
   SI no se puede abrir:
      MOSTRAR error
   SINO:
      CALCULAR tamaño del archivo
      RESERVAR memoria suficiente
      LEER todo el contenido del archivo
      CERRAR archivo
      GUARDAR texto en variable 'contenido'
      MOSTRAR mensaje de éxito

Caso 2: Calcular estadisticas
 VERIFICAR que hay un archivo cargado
   SI no hay:
      MOSTRAR error
   SINO:
      INICIAR contadores (caracteres=0, palabras=0, espacios=0, líneas=0)
      RECORRER cada carácter del texto:
         SI es espacio:
            AUMENTAR contador espacios
            SI es salto de línea (\n):
               AUMENTAR contador líneas
            SI estaba en una palabra:
               AUMENTAR contador palabras
         SINO:
            AUMENTAR contador caracteres (si no es \n)
      MOSTRAR resultados

Caso 3: Frecuencia de vocales
VERIFICAR que hay un archivo cargado
   SI no hay:
      MOSTRAR error
   SINO:
      INICIAR contadores (a=0, e=0, i=0, o=0, u=0)
      RECORRER cada carácter del texto:
         CONVERTIR a minúscula
         SI es vocal:
            AUMENTAR su contador correspondiente
      MOSTRAR cantidad de cada vocal

Caso 4: Reemplazar una palabra 
VERIFICAR que hay un archivo cargado
   SI no hay:
      MOSTRAR error
   SINO:
      PEDIR palabra a buscar
      PEDIR palabra de reemplazo
      BUSCAR todas las ocurrencias de la palabra en el texto
      SI no se encuentra:
         MOSTRAR mensaje
      SINO:
         CREAR nuevo texto con los reemplazos
         LIBERAR memoria del texto antiguo
         GUARDAR nuevo texto en 'contenido'
         MOSTRAR mensaje de éxito

Caso 5: Guardar resultados
VERIFICAR que hay un archivo cargado
   SI no hay:
      MOSTRAR error
   SINO:
      PEDIR nombre para archivo de salida
      ABRIR archivo en modo escritura
      ESCRIBIR en el archivo:
         - Estadísticas (caracteres, palabras, etc.)
         - Conteo de vocales
         - Texto completo (con reemplazos si los hay)
      CERRAR archivo
      MOSTRAR mensaje de éxito

Caso 6: Salir
LIBERAR memoria usada por 'contenido' si existe
MOSTRAR mensaje de despedida
TERMINAR programa
```


Codigo: [RETO.c](/RETOS/RETO.c)  