

#include <stdlib.h>
#include <stdio.h>


int ft_abs(int nbr)
{
    if(nbr < 0)
        return(nbr * -1);
    return(nbr);
}

int *ft_range(int start, int end) 
{
    int size = ft_abs(end - start) + 1;  // Calcula el tamaño del arreglo

    int *range = (int *)malloc(size * sizeof(int));  // Asignación de memoria
    if (!range) 
        return NULL;  // Verifica si la asignación falló

    int i = 0; // Índice para el bucle while
    // Llenado del arreglo
    if (start <= end) 
    {
        while (i < size) 
        {
            range[i] = start + i;
            i++;
        }
    } 
    else
    {
        while (i < size) 
        {
            range[i] = start - i;
            i++;
        }
    }

    return (range);  // Retorna el puntero al arreglo
}

int main(void)
{
    int i;
    int *ptr;

    i = 0;
    ptr = ft_range(-2147483648, 45453); // Llamada a la función para obtener el rango
    while (i <= 10000 )
    {
        printf("%d ", ptr[i]); // Impresión de los números del rango
        i++;
    }
    printf("\n");
    free(ptr); // Liberación de la memoria asignada dinámicam
    return 0;
}

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.