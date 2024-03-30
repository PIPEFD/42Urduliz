
#include <stdlib.h>
// #include <stdio.h>

// Función para generar un rango de enteros desde 'start' hasta 'end' (excluyendo 'end').
// Retorna un puntero a un arreglo dinámico que contiene los números del rango.
// Si hay un error en la asignación de memoria, retorna NULL.
int *ft_range(int start, int end)
{
    int *res; // Puntero para almacenar los números del rango
    int len = (end >= start) ? end - start : start - end; // Longitud del rango

    // Asignación de memoria para el arreglo dinámico
    if (!(res = (int *)malloc(sizeof(int) * len)))
        return (NULL);

    // Llenado del arreglo con los números del rango
    while (start != end)
        *res++ = end > start ? start++ : end--;

    *res = end; // Último número del rango
    return (res - len); // Retorno del puntero al arreglo
}

int main(void)
{
    int i;
    int *ptr;

    i = 0;
    ptr = ft_range(1, 3); // Llamada a la función para obtener el rango
    while (i <= 2)
    {
        printf("%d ", ptr[i]); // Impresión de los números del rango
        i++;
    }
    printf("\n");
    free(ptr); // Liberación de la memoria asignada dinámicamente
    return 0;
}