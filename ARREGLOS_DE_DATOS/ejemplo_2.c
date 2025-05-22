#include <stdio.h>

int main(int argc, char const *argv[])
{
    int Datos[5] = {0};//se reserva el espacio para 5 datos.
    
   for (int cont = 0; cont < 15 ; cont++){// se crea un contador para realizar un incremento en cada dato 15 veces 
           Datos[0] ++;//primer dato se incrementa de 1 en 1
    Datos[1] += 2;// se incrementa de 2 en 2
    Datos[2] += 3;// se incrementa de 3 en 3
    Datos[3] += 4;// se incrementa de 4 en 4
    Datos[4] += 5;// se inclemnta de 5 en 5
    
   }
    
    for (int i = 0; i < 5; i++)
{

  printf("%d\n", Datos[i]);// se imprime el valor de cada dato que seria el valor final de cada dato al incrementarce 15 veces.
}
    return 0;
}

