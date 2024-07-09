unsigned char	swap_bits(unsigned char c)
{
	return ((c >> 4) | (c << 4));
}




int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    unsigned char num = (unsigned char) ft_atoi(argv[1]);
    printf("Original byte: %u (binary: %02x)\n", num, num);
    unsigned char swapped = swap_bits(num);
    printf("Swapped byte: %u (binary: %02x)\n", swapped, swapped);

    return 0;
}

