// #include <stdio.h>
#include <stdlib.h>

// Función para generar un rango de enteros en orden inverso
// desde 'start' hasta 'end', ambos inclusive.
// Retorna un puntero a un arreglo dinámico que contiene los números.
// Si hay un error en la asignación de memoria, retorna NULL.
int *ft_rrange(int start, int end)
{
    int *res; // Puntero para almacenar los números del rango
    int len = (end >= start) ? end - start + 1 : start - end + 1; // Longitud del rango

    // Asignación de memoria para el arreglo dinámico
    if (!(res = (int *)malloc(sizeof(int) * len)))
        return (NULL);

    // Llenado del arreglo con los números del rango
    while (len--)
        res[len] = (end >= start) ? start++ : start--;

    return res; // Retorno del puntero al arreglo
}

int main(void)
{
    int i;
    int *ptr;

    i = 0;
    ptr = ft_rrange(1, 3); // Llamada a la función para obtener el rango
    while (i <= 2)
    {
        printf("%d ", ptr[i]); // Impresión de los números del rango
        i++;
    }
    printf("\n");
    free(ptr); // Liberación de la memoria asignada dinámicamente
    return 0;
}
