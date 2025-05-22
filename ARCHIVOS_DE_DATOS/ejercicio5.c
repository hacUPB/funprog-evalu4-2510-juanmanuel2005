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
