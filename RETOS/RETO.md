# RETO 
## Análisis del problema
Para este reto se desarrolló una aplicación de consola en lenguaje C llamada Analizador de Texto, la cual permite leer un archivo .txt, analizar su contenido, realizar modificaciones y guardar resultados. Este programa integra los conceptos de archivos de texto, cadenas de caracteres, memoria dinámica, bucles, condicionales y funciones.   
  
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
- Número de líneas.
     
El análisis se realiza recorriendo el arreglo de caracteres previamente cargado.      
     
### 3. Frecuencia de vocales   
Cuenta la cantidad de veces que aparece cada vocal (a, e, i, o, u), combinando mayúsculas y minúsculas.     
Este conteo se hace sin funciones externas, recorriendo cada carácter y evaluando con `tolower()`.     
         
### 4. Reemplazar palabra
Permite al usuario ingresar una palabra a buscar y otra para reemplazarla.   
El texto completo es recorrido y se crean dinámicamente nuevas cadenas con malloc para contener el resultado modificado.      
Si no se encuentra la palabra buscada, se informa al usuario. Si sí se encuentra, se reemplaza en todas sus apariciones.    

### 5. Guardar resultados
Permite guardar todos los resultados generados en un nuevo archivo `.txt`.     
El usuario elige el nombre del archivo de salida.     
Se guarda:     
- Estadísticas del texto.   
- Frecuencia de vocales.    
- Texto final (modificado o no).    
      
Todo se guarda usando fprintf() y se confirma al usuario que el archivo fue creado exitosamente.     
    
### 6. Salir del programa
Libera la memoria utilizada y termina la ejecución de forma segura.    

Codigo: [RETO.c](/RETOS/RETO.c)  