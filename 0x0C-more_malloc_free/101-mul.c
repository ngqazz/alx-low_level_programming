char *final_prod, *next_prod;
    int size, index, digit, zeroes = 0;

    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }

    if (*(argv[1]) == '0')
        argv[1] = iterate_zeroes(argv[1]);
    if (*(argv[2]) == '0')
        argv[2] = iterate_zeroes(argv[2]);
    if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
    {
        printf("0\n");
        return (0);
    }

    size = find_len(argv[1]) + find_len(argv[2]);
    final_prod = create_xarray(size + 1);
    next_prod = create_xarray(size + 1);

    for (index = find_len(argv[2]) - 1; index >= 0; index--)
    {
        digit = get_digit(*(argv[2] + index));
        get_prod(next_prod, argv[1], digit, zeroes++);
        add_nums(final_prod, next_prod, size - 1);
    }
    for (index = 0; final_prod[index]; index++)
    {
        if (final_prod[index] != 'x')
            putchar(final_prod[index]);
    }
    putchar('\n');

    free(next_prod);
    free(final_prod);

    return (0);
}

