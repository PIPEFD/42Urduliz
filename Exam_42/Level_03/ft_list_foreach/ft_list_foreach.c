#include <stdio.h>
#include <stdlib.h>
#include "ft_list_foreach.h"

void print_int(void *data) {
    printf("%d\n", *(int *)data);
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *)) 
{
    while (begin_list) 
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}

void ft_list_push_front(t_list **begin_list, void *data) 
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) 
        return (NULL);
    new_node->data = data;
    new_node->next = *begin_list;
    *begin_list = new_node;
}

int main() {

    t_list *my_list = NULL;
    int arr[] = {10, 20, 30, 40, 50}; 


    for (int i = 0; i < 5; i++) 
    {
        ft_list_push_front(&my_list, &arr[i]);
    }


    ft_list_foreach(my_list, print_int);


    t_list *tmp;
    while (my_list != NULL) {
        tmp = my_list;
        my_list = my_list->next;
        free(tmp);
    }

    return 0;
}