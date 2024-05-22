/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/22 14:51:35 by akinzeli         ###   ########.fr       */
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
# define ERROR_MSG "Arguments:./philo(n_philo)(t_die)(t_eat)(t_sleep)(n_meal)\n"

/*   All the structures  */

typedef struct s_data
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	bool			end_dinner;
	int				philo_dead;
	long			dinner_start;
	int				finish_eating_count;
	pthread_t		death_checker;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	m_philo;
}					t_init_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				fork_used;
}					t_fork;

typedef struct s_philo
{
	t_init_data		*data;
	int				philo_number;
	int				philo_size;
	int				meal_eaten;
	int				meal_should_eat;
	long			last_eaten_meal;
	long			start_time;
	t_fork			*left;
	t_fork			*right;
	pthread_t		id_thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*m_philo;
}					t_philo;

/* data_init.c functions */

t_init_data			*start_data(int ac, char *av[]);
t_fork				*init_fork(t_init_data *data);
t_philo				*init_philo(t_init_data *data, t_fork *fork);
void				data_philo(t_philo *philo, t_init_data *data, t_fork *fork,
						int i);

/* utils.c functions */

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					check_av(int ac, char *av[]);
long				time_get(void);
void				print_situation(t_philo *philo, int philo_number,
						char *message);

/* utils_second.c functions */

void				ft_usleep(long micro_sec);
int					philo_dead(t_philo *philo);
int					must_eat_meal(t_philo *philo);
void				print_situation_death(t_philo *philo, int philo_number,
						char *message);

/* main.c functions */

void				free_all(t_philo *philo, t_fork *fork, t_init_data *data);
int					ft_finish(t_philo *philo, t_fork *fork, t_init_data *data,
						int code);
int					check_death_full(t_philo *philo);

/* dinner.c functions */

int					dinner(t_philo *philo, t_init_data *data);
void				*check_death(void *philo);
int					death_checker(t_philo *philo, size_t time);
void				*routine(void *philo);
int					join_thread(t_philo *philo, t_init_data *data);

/* philo_action.c functions */

void				eat(t_philo *philo);
void				sleep_philo(t_philo *philo);
void				think(t_philo *philo);
void				fork_use(t_philo *philo, t_fork *fork);
void				remove_fork(t_fork *fork);

#endif