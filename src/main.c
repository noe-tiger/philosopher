/*
** EPITECH PROJECT, 2018
** *
** File description:
** *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"
#include "struct.h"

pthread_mutex_t temp = PTHREAD_MUTEX_INITIALIZER;
data_t		*args;

char wait = 0;
char start = 0;

void	left_or_right_unlock(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	lphilo_release_chopstick(mutex);
}

void	init(var_t *var, void *arg)
{
	var->tmp = *((int *)arg);
	var->left = var->tmp;
	var->right = ((var->tmp + 1 < args->p) ? var->left + 1 : 0);
	var->lock = 0;
	var->llock = 0;
	var->rlock = 0;
	var->step = 0;
	start = 1;
}

void	*pot(void *arg)
{
	var_t	*var = malloc(sizeof(var_t));

	init(var, arg);
	while (wait == 0);
	for (int i = 0; i < args->e; i = i)
	{
		if (pthread_mutex_trylock(&philo[var->left].mutex) == 0)
			try_lock(var, &philo[var->left].mutex, 0);
		if (pthread_mutex_trylock(&philo[var->right].mutex) == 0)
			try_lock(var, &philo[var->right].mutex, 1);
		if (var->lock == 2 && var->step != 2)
			i = eat(var, i);
		else if (var->lock == 1 && var->step == 0)
			think_incrementation(var);
		else if (var->step == 2 || var->step == 0)
			think_or_not(var);
		end_loop(var);
	}
	return (NULL);
}

void	manage_thread(data_t *data)
{
	philo_t		philo_struct[data->p];

	philo = philo_struct;
	args = data;
	for (int i = 0; i < data->p; i++)
		philo[i].mutex = temp;
	for (int i = 0; i < data->p; i++)
	{
		int	j = i;
		start = 0;
		pthread_create(&philo[i].thread, NULL, pot, &j);
		while (start == 0);
	}
	wait = 1;
	for (int i = 0; i < data->p; i++)
		pthread_join(philo[i].thread, NULL);
}

int	main(int ac, char **av)
{
	data_t	data;
	int	ret;

	ret = get_args(&data, ac, av);
	if (ret == 84)
		return (84);
	if (ret == -1)
		return (0);
	RCFStartup(ac, av);
	manage_thread(&data);
	RCFCleanup();
	return (0);
}
