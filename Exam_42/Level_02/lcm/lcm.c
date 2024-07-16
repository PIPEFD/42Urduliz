unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

int main(int argc, char **argv)
{
    // 🧠 Verifica que se proporcionen exactamente 2 argumentos (los números)
    if (argc == 3)
        lcm(argv[1], argv[2]); // 🧠 Llama a la función pgcd con los dos números como argumentos
    printf("\n"); // 🖨️ Imprime un salto de línea al final
    return 0;
}