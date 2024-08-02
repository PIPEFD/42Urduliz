#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list_remove_if.h"

// Función para comparar strings almacenados en la lista
int cmp(void *data1, void *data2)
{
    return strcmp((char *)data1, (char *)data2);
}

// Función para crear un nuevo nodo
t_list *ft_create_elem(void *data)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new) return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

// Función para añadir un elemento al inicio de la lista
void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new = ft_create_elem(data);
    if (new)
    {
        new->next = *begin_list;
        *begin_list = new;
    }
}

// Función para liberar la lista completa
void ft_list_clear(t_list **begin_list)
{
    t_list *tmp;
    while (*begin_list)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }
}

// Función para imprimir la lista
void ft_print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return;

    t_list *cur = *begin_list;

    if (cmp(cur->data, data_ref) == 0)
    {
        *begin_list = cur->next;
        free(cur);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        cur = *begin_list;
        ft_list_remove_if(&cur->next, data_ref, cmp);
    }
}

int	ft_list_size(t_list *begin_list)
{
    int count = 0;

    while (begin_list)
    {
        begin_list = begin_list->next;
        count++;
    }
    return(count);
}

int main()
{
    t_list *list = NULL;

    // Añadir elementos a la lista
    ft_list_push_front(&list, "apple");
    ft_list_push_front(&list, "banana");
    ft_list_push_front(&list, "cherry");
    ft_list_push_front(&list, "banana");
    ft_list_push_front(&list, "date");
    ft_list_push_front(&list, "naraja");


    printf("result-> %d \n",ft_list_size (list));
    printf("Original list:\n");
    ft_print_list(list);
    ft_list_remove_if(&list, "banana", cmp);
    // Remover todos los "banana" de la lista
    printf("result-> %d \n",ft_list_size (list));

    printf("List after removing 'banana':\n");
    ft_print_list(list);

    // Limpiar la lista al final
    ft_list_clear(&list);

    return 0;
}
