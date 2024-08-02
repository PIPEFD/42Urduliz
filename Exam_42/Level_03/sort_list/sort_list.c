#include <stdio.h>
#include <stdlib.h>
#include "sort_list.h"

// Función para crear un nuevo nodo
t_list *ft_create_elem(int data) {
    t_list *new = malloc(sizeof(t_list));
    if (!new) return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

// Función para añadir un elemento al final de la lista
void ft_list_push_back(t_list **begin_list, int data) {
    t_list *new = ft_create_elem(data);
    if (new) {
        if (*begin_list == NULL) {
            *begin_list = new;
        } else {
            t_list *tmp = *begin_list;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = new;
        }
    }
}

// Función de comparación para ordenar de menor a mayor
int ascending(int a, int b) {
    return a > b;  // Retorna 1 si a debe ir antes de b (a > b)
}

// Función de sort_list
t_list *sort_list(t_list* lst, int (*cmp)(int, int)) {
    int swap;
    t_list *start = lst;

    while (lst != NULL && lst->next != NULL) {
        if ((*cmp)(lst->data, lst->next->data)) {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = start;  // Reiniciar desde el principio después de un swap
        } else {
            lst = lst->next;
        }
    }
    return start;
}

// Función para imprimir la lista
void print_list(t_list *lst) {
    while (lst) {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int main() {
    t_list *mylist = NULL;

    // Añadir elementos a la lista
    ft_list_push_back(&mylist, 5);
    ft_list_push_back(&mylist, 3);
    ft_list_push_back(&mylist, 9);
    ft_list_push_back(&mylist, 1);

    // Imprimir la lista original
    printf("Original list:\n");
    print_list(mylist);

    // Ordenar la lista
    mylist = sort_list(mylist, ascending);

    // Imprimir la lista ordenada
    printf("Sorted list:\n");
    print_list(mylist);

    return 0;
}
