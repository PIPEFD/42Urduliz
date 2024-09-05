#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void ft_put_str(char *str, int *size)
{
	if(!str)
		str = "(null)";
	while(*str)
		*size += write(1, str++, 1);
}

void ft_put_digit(long long int nbr, int base, int *size)
{
	if(nbr < 0)
	{
		nbr *= -1;
		*size += write(1, "-",1);
	}
	if(nbr >= base)
		ft_put_digit((nbr / base), base, size);
	*size += write(1, &("0123456789abcdef"[nbr % base]),1);
}

int ft_printf(const char *format, ... )
{
	int size = 0;

	va_list ptr;
	va_start(ptr, format);

	while (*format)
	{
		if((*format == '%') && \
		((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if(*format == 's')
				ft_put_str(va_arg(ptr, char *), &size);
			else if (*format == 'd')
				ft_put_digit((long long int)va_arg(ptr, int), 10, &size);
			else if (*format == 'x')
				ft_put_digit((long long int)va_arg(ptr, unsigned int), 16, &size);
		}
		else
			size +=  write(1, format, 1);
		format++;
	}
	return(va_end(ptr), size);
}

  int main (void)
{
	int len1;
	int len2;
	int len3;
	int len4;

	len1 = ft_printf("ft_printf este es un [%s] [42]\n", "number", 42);
	printf("size of ft_printf --> [%d]\n", len1);
    len2 = ft_printf("ft_printf este es un [%x] [42]\n", 42, 42);
	printf("size of ft_printf --> [%d]\n", len2);
    len3 = printf("printf orginal function este es un [%s] [%d]\n", "number", 42);
	printf("size of original function --> [%d]\n", len3);
    len4 = printf("printf orginal function este es un [%x] [%d]\n", 42, 42);
	printf("size of ft_printf --> [%d]\n", len4);

    return(0);
}
