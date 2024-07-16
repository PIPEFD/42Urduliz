#include <stdlib.h>
#include <stdio.h>



int ft_abs(int n)
{
    if (n < 0)
        return(n * -1);
    return (n);
}

int *ft_rrange(int start, int end) {
    int size = abs(end - start) + 1;

    int *range = (int *)malloc(size * sizeof(int));

    if (!range) 
        return NULL;

    int i = 0;
    if (start <= end)
    {
        while (i < size) 
        {
            range[i] = end - i;
            i++;
        }
    } 
    else {
        while (i < size) {
            range[i] = end + i;
            i++;
        }
    }
    
    return range;
}



int main(void)
{
    int i;
    int *ptr;

    i = 0;
    ptr = ft_rrange(-2147483648, 45453); // Llamada a la función para obtener el rango
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

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.