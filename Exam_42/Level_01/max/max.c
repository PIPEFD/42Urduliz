#include <stdio.h>


int max(int *tab, unsigned int len)
{
    int result;
    unsigned int i = 0;

    if (len == 0)
        return(0);
    result = tab[i];
    while(i < len)
    {
        if (result < tab[i])
            result =  tab[i];
        i++;
    }
    return(result);
}

int main ()
{
    int  *nbr = {1,2,3,4,5};
    int  len = 5;

    printf("result-> %i\n",max(nbr, len));
    return(0);    
}