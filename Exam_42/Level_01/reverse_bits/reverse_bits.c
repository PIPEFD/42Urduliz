#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	bit = 0;

	while (i > 0)
	{
		bit = bit * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (bit);
}
int main(int argc, char **argv)
{
    if (argc == 2) {
        // int num = atoi(argv[1]);  // Convertir el argumento de entrada a un entero
        //     if (num < 0 || num > 255) 
        //     {
                
        //         printf("Error: Please enter a number between 0 and 255.\n");
        //         return 1;
        //     }
        unsigned char octet = (unsigned char)argv[1];  // Asegurarse de que el número esté en el rango de un unsigned char
        reverse_bits(octet);  // Llamar a la función para imprimir los bits
        write(1, "\n", 1);  // Añadir una nueva línea después de los bits para una mejor visualización
    }
    else
        write(1, "\n", 1);  // Añadir una nueva línea después de los bits para una mejor visualización
    return 0;
}