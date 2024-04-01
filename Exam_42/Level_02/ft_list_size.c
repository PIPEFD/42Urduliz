typedef struct    s_list
{
    struct s_list *next; // 🔗 Puntero al siguiente nodo de la lista
    void          *data; // 📦 Puntero a los datos almacenados en el nodo
}                 t_list; // 📋 Definición de la estructura de la lista

// 🔢 Función para obtener el tamaño de una lista enlazada
int ft_list_size(t_list *begin_list)
{
    int i = 0; // Inicializa un contador

    // 🔁 Recorre la lista mientras haya elementos
    while (begin_list)
    {
        begin_list = begin_list->next; // 🚶 Avanza al siguiente nodo de la lista
        i++; // Incrementa el contador
    }
    return(i); // 📏 Retorna el tamaño de la lista
}
