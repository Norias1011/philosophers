/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/02 14:45:19 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int		*number_philo;
	int		*time_die;
	int		*time_eat;
	int		*time_sleep;
	int		*must_eat;
}			t_init_data;

typedef struct s_philo
{
	struct	s_data;
}			t_philo;

/* data_init.c functions */

t_init_data	*start_data(int ac, char *av[]);
int			check_av(int ac, char *av[]);

/* utils.c functions */

int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif