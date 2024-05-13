/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/13 14:34:03 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define FORK "has taken the fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
# define ERROR_MSG "Wrong argument : ./philo (number_philo) (time_die) (time_eat) (time_sleep) (number_meal)"

/*   All the structures  */

typedef struct s_data
{
	long			number_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			must_eat;
	pthread_t		syncronizor;
}					t_init_data;

typedef struct s_philo
{
	t_init_data		*data;
	int				philo_number;
	int				meal_eaten;
	int				philo_dead;
	int				last_eaten_meal;
	int				dinner_start;
	bool			end_dinner;
	t_fork			*left;
	t_fork			*right;
	pthread_t		id_thread;
	pthread_mutex_t	print;
	pthread_mutex_t	dinner;
	pthread_mutex_t	dead;
}					t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				fork_used;
}					t_fork;

/* data_init.c functions */

t_init_data			*start_data(int ac, char *av[]);
t_fork				*init_fork(t_init_data *data);
t_philo				*init_philo(t_init_data *data, t_fork *fork);
int					data_philo(t_philo *philo, t_init_data *data, t_fork *fork,
						int i);

/* utils.c functions */

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					check_av(int ac, char *av[]);
size_t				time_get(void);
void				print_situation(t_philo *philo, int philo_number,
						char *message);

/* utils_second.c functions */

void				ft_usleep(long int micro_sec);

/* main.c functions */

int					free_all(t_philo *philo, t_fork *fork, t_init_data *data);

/* dinner.c functions */

int					dinner(t_philo *philo, t_fork *fork, t_init_data *data);

#endif