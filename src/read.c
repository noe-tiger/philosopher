/*
** EPITECH PROJECT, 2018
** *
** File description:
** *
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

int	print_help(void)
{
	printf("%s\n", HELP);
	return (-1);
}

int	get_args(data_t *data, int ac, char **av)
{
	data->p = -1;
	data->e = -1;
	for (int i = 0; i < ac; i++)
	{
		if (!strcmp(av[i], "-h"))
			return (print_help());
		if (!strcmp(av[i], "-p") && i + 1 < ac)
			data->p = atoi(av[i+1]);
		if (!strcmp(av[i], "-e") && i + 1 < ac)
			data->e = atoi(av[i+1]);
	}
	if (data->p <= 1 || data->e < 0)
		return (84);
	return (0);
}
