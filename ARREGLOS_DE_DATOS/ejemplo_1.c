#include <stdio.h>

int main(int argc, char const *argv[])
{
    int Datos[5] = {45, 32, 89, 11, 9};// se reserva el espacio para 5 datos y se declaran los 5 datos.
    
    printf("%d\n", Datos[2]);// se imprime el dato en la posision 2 teniendo en cuenta que comienza en 0 siendo 45 el 0, 32 el 1 y asi sucesivamente.
    
    for (int i = 0; i < 5; i++)
{
    printf("%d\n - %p\n", Datos[i], &Datos[i]);// imprime los datos y su direccion de memoria.
}
    return 0;
}