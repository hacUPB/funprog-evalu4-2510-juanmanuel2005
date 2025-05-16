#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* leerArchivo(const char* nombreArchivo);  // Para el Caso 1
void calcularEstadisticas(const char* texto, int* chars, int* palabras, int* espacios, int* lineas);
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
                break;
            }
            
            case 4: { // Reemplazar palabra
                break;
            }
            
            case 5: { // Guardar resultados
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