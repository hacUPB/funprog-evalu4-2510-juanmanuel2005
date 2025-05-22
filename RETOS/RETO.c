#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* leerArchivo(const char* nombreArchivo);  // Para el Caso 1
void calcularEstadisticas(const char* texto, int* chars, int* palabras, int* espacios, int* lineas);
void calcularVocales(const char* texto, int* a, int* e, int* i, int* o, int* u);
char* reemplazarPalabra(const char* texto, const char* buscar, const char* reemplazo);
void guardarResultados(const char* nombreArchivo, const char* texto);
void mostrarMenu(void);// Prototipo de la función del menú

int main() {
    int opcion;
    char* contenido = NULL;  // Puntero al texto cargado
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar();  
        
        switch(opcion) {
            case 1: { // Cargar archivo
                 char nombreArchivo[100];
                printf("Ingrese el nombre del archivo (.txt): ");
                fgets(nombreArchivo, sizeof(nombreArchivo), stdin);
                nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0';
                
                // Liberar memoria si ya había un archivo cargado
                if(contenido != NULL) {
                    free(contenido);
                }
                
                contenido = leerArchivo(nombreArchivo);
                if(contenido != NULL) {
                    printf("Archivo cargado exitosamente!\n");
                } else {
                    printf("Error al cargar el archivo.\n");
                }
                break;
            }
            
            case 2: { // Calcular estadísticas
                if(contenido == NULL) {
                    printf("Error: Primero cargue un archivo (Opción 1)\n");
                    break;
                }
                
                int chars, palabras, espacios, lineas;
                calcularEstadisticas(contenido, &chars, &palabras, &espacios, &lineas);
                
                printf("\n=== ESTADÍSTICAS ===\n");
                printf("Caracteres (sin \\n): %d\n", chars);
                printf("Palabras: %d\n", palabras);
                printf("Espacios: %d\n", espacios);
                printf("Líneas: %d\n", lineas);
                break;
            }
            
            case 3: { // Frecuencia de vocales
                if(contenido == NULL) {
                    printf("Error: Primero cargue un archivo (Opción 1)\n");
                    break;
                }
                
                int a = 0, e = 0, i = 0, o = 0, u = 0;
                calcularVocales(contenido, &a, &e, &i, &o, &u);
                
                printf("\n=== FRECUENCIA DE VOCALES ===\n");
                printf("A/a: %d\n", a);
                printf("E/e: %d\n", e);
                printf("I/i: %d\n", i);
                printf("O/o: %d\n", o);
                printf("U/u: %d\n", u);
                break;
            }
            
            case 4: { // Reemplazar palabra
                if(contenido == NULL) {
                    printf("Error: Primero cargue un archivo (Opción 1)\n");
                    break;
                }
                
                char buscar[50], reemplazo[50];
                printf("Palabra a buscar: ");
                fgets(buscar, sizeof(buscar), stdin);
                buscar[strcspn(buscar, "\n")] = '\0';
                
                printf("Palabra de reemplazo: ");
                fgets(reemplazo, sizeof(reemplazo), stdin);
                reemplazo[strcspn(reemplazo, "\n")] = '\0';
                
                char* nuevoTexto = reemplazarPalabra(contenido, buscar, reemplazo);
                if(nuevoTexto != NULL) {
                    free(contenido);
                    contenido = nuevoTexto;
                    printf("Reemplazo realizado con éxito!\n");
                } else {
                    printf("No se encontró la palabra '%s'\n", buscar);
                }
                break;
            }
            
            case 5: { // Guardar resultados
                if(contenido == NULL) {
                    printf("Error: Primero cargue un archivo (Opción 1)\n");
                    break;
                }
                
                char nombreSalida[100];
                printf("Nombre del archivo de salida (.txt): ");
                fgets(nombreSalida, sizeof(nombreSalida), stdin);
                nombreSalida[strcspn(nombreSalida, "\n")] = '\0';
                
                guardarResultados(nombreSalida, contenido);
                break;
            }
            
            case 6: { // Salir
                printf("Saliendo del programa...\n");
                break;
            }
            
            default: {
                printf("Opción no válida. Intente de nuevo.\n");
            }
        }
        
    } while(opcion != 6);
    
    if(contenido != NULL) {
        free(contenido); // Liberar memoria al finalizar
    }
    return 0;
}

// Definición de la función del menú
void mostrarMenu(void) {
    printf("\n=== ANALIZADOR DE TEXTO ===");
    printf("\n1. Cargar archivo de texto");
    printf("\n2. Calcular estadísticas");
    printf("\n3. Frecuencia de vocales");
    printf("\n4. Reemplazar palabra");
    printf("\n5. Guardar resultados");
    printf("\n6. Salir");
    printf("\nSeleccione una opción: ");
}

// Función para leer archivo (Caso 1)
char* leerArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }
    
    // Obtener tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);
    
    // Reservar memoria
    char* contenido = (char*)malloc(tamano + 1);
    if(contenido == NULL) {
        fclose(archivo);
        perror("Error al reservar memoria");
        return NULL;
    }
    
    // Leer contenido
    size_t bytesLeidos = fread(contenido, 1, tamano, archivo);
    contenido[bytesLeidos] = '\0';  // Terminar cadena
    
    fclose(archivo);
    return contenido;
}


void calcularEstadisticas(const char* texto, int* chars, int* palabras, int* espacios, int* lineas) {
    *chars = 0;
    *palabras = 0;
    *espacios = 0;
    *lineas = 0;
    int enPalabra = 0;
    
    for(int i = 0; texto[i] != '\0'; i++) {
        if(texto[i] != '\n') {
            (*chars)++;
        }
        
        if(isspace(texto[i])) {
            (*espacios)++;
            if(texto[i] == '\n') {
                (*lineas)++;
            }
            if(enPalabra) {
                (*palabras)++;
                enPalabra = 0;
            }
        } else {
            enPalabra = 1;
        }
    }
    
    // Ajustes finales
    if(enPalabra) (*palabras)++;
    if(texto[strlen(texto)-1] != '\n') (*lineas)++;
}

void calcularVocales(const char* texto, int* a, int* e, int* i, int* o, int* u) {
    *a = *e = *i = *o = *u = 0;
    
    for(int idx = 0; texto[idx] != '\0'; idx++) {
        char c = tolower(texto[idx]);
        switch(c) {
            case 'a': (*a)++; break;
            case 'e': (*e)++; break;
            case 'i': (*i)++; break;
            case 'o': (*o)++; break;
            case 'u': (*u)++; break;
        }
    }
}

char* reemplazarPalabra(const char* texto, const char* buscar, const char* reemplazo) {
    int contador = 0;
    int longBuscar = strlen(buscar);
    int longReemplazo = strlen(reemplazo);
    const char* temp = texto;
    
    // Contar ocurrencias
    while((temp = strstr(temp, buscar)) != NULL) {
        contador++;
        temp += longBuscar;
    }
    
    if(contador == 0) return NULL;
    
    // Calcular nuevo tamaño
    int longTexto = strlen(texto);
    int nuevoTamano = longTexto + contador * (longReemplazo - longBuscar);
    char* resultado = (char*)malloc(nuevoTamano + 1);
    
    // Realizar reemplazos
    char* ptr = resultado;
    const char* inicio = texto;
    const char* pos;
    
    while((pos = strstr(inicio, buscar)) != NULL) {
        int copiarHasta = pos - inicio;
        strncpy(ptr, inicio, copiarHasta);
        ptr += copiarHasta;
        
        strcpy(ptr, reemplazo);
        ptr += longReemplazo;
        
        inicio = pos + longBuscar;
    }
    
    strcpy(ptr, inicio);
    return resultado;
}

void guardarResultados(const char* nombreArchivo, const char* texto) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if(archivo == NULL) {
        perror("Error al crear archivo");
        return;
    }
    
    // Estadísticas
    int chars, palabras, espacios, lineas;
    calcularEstadisticas(texto, &chars, &palabras, &espacios, &lineas);
    fprintf(archivo, "=== ESTADÍSTICAS ===\n");
    fprintf(archivo, "Caracteres: %d\nPalabras: %d\nEspacios: %d\nLíneas: %d\n\n", 
            chars, palabras, espacios, lineas);
    
    // Vocales
    int a, e, i, o, u;
    calcularVocales(texto, &a, &e, &i, &o, &u);
    fprintf(archivo, "=== FRECUENCIA DE VOCALES ===\n");
    fprintf(archivo, "A: %d\nE: %d\nI: %d\nO: %d\nU: %d\n\n", a, e, i, o, u);
    
    // Texto completo
    fprintf(archivo, "=== TEXTO ===\n%s", texto);
    fclose(archivo);
    
    printf("Resultados guardados en '%s'\n", nombreArchivo);
}