/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/06 16:02:30 by akinzeli         ###   ########.fr       */
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
# include <unistd.h>

/*   All the structures  */

typedef struct s_data
{
	long			number_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			must_eat;
}					t_init_data;

typedef struct s_philo
{
	t_init_data		*data;
	int				meal_eaten;
	t_fork			*left;
	t_fork			*right;
	pthread_t		id_thread;
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

#endif