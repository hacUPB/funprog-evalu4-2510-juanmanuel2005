#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototipo de la función del menú
void mostrarMenu(void);

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar();  
        
        switch(opcion) {
            case 1: { // Cargar archivo
                break;
            }
            
            case 2: { // Calcular estadísticas
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