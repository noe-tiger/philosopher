/*
** EPITECH PROJECT, 2018
** *
** File description:
** *
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define HELP	"USAGE\n\t./philo -p nbr_p -e nbr_e\n\n\
DESCRIPTION\n\t-p nbr_p\tnumber of philosophers\n\t-e nbr_e\
\tmaximum number times a philosopher eats before exiting the\
program"

typedef struct	data_s
{
	int	p;
	int	e;
}		data_t;

typedef struct	philo_s
{
	pthread_t       thread;
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
}		philo_t;

typedef	struct	var_s
{
	int	tmp;
	int	left;
	int	right;
	int	lock;
	int	llock;
	int	rlock;
	int	step;
}		var_t;

int		get_args(data_t *, int, char **);
void		try_lock(var_t *var, pthread_mutex_t *mutex, int i);
int		eat(var_t *var, int i);
void		end_loop(var_t *var);
void		think_or_not(var_t *var);
void		think_incrementation(var_t *var);
void		left_or_right_unlock(pthread_mutex_t *mutex);
philo_t         *philo;

#endif /* STRUCT_H_ */
