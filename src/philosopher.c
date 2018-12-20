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

void	try_lock(var_t *var, pthread_mutex_t *mutex, int i)
{
	lphilo_take_chopstick(mutex);
	var->lock += 1;
	if (i == 1)
		var->rlock = 1;
	else
		var->llock = 1;
}

int	eat(var_t *var, int i)
{
	lphilo_eat();
	if (var->step == 1)
		var->step += 1;
	i += 1;
	return (i);
}

void	end_loop(var_t *var)
{
	if (var->rlock)
		left_or_right_unlock(&philo[var->right].mutex);
	if (var->llock)
		left_or_right_unlock(&philo[var->left].mutex);
	var->rlock = 0;
	var->llock = 0;
	var->lock = 0;
}

void	think_or_not(var_t *var)
{
	if (var->rlock)
		left_or_right_unlock(&philo[var->right].mutex);
	var->rlock = 0;
	if (var->llock)
		left_or_right_unlock(&philo[var->left].mutex);
	var->llock = 0;
	lphilo_sleep();
	var->step = 0;
}

void	think_incrementation(var_t *var)
{
	lphilo_think();
	var->step += 1;
}
