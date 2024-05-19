/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:05:53 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/19 17:31:47 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_init_data	*start_data(int ac, char *av[])
{
	t_init_data	*new;

	new = malloc(sizeof(t_init_data));
	if (new == NULL)
		return (NULL);
	if ((ac > 4 && ac <= 6) && check_av(ac, av))
	{
		new->number_philo = ft_atoi(av[1]);
		new->time_die = ft_atoi(av[2]);
		new->time_eat = ft_atoi(av[3]);
		new->time_sleep = ft_atoi(av[4]);
		if (ac == 6)
			new->must_eat = ft_atoi(av[5]);
		else
			new->must_eat = INT_MAX;
	}
	else
		free(new);
	if (new->number_philo <= 0 || new->time_die <= 0 || new->time_eat <= 0
		|| new->time_sleep <= 0 || new->must_eat <= 0)
		return (NULL);
	new->philo_dead = 0;
	new->end_dinner = false;
	return (new);
}

t_fork	*init_fork(t_init_data *data)
{
	t_fork	*fork;
	int		i;

	if (data == NULL)
		return (NULL);
	fork = malloc(sizeof(t_fork) * data->number_philo);
	if (fork == NULL)
		return (NULL);
	i = 0;
	while (i < data->number_philo)
	{
		(fork + i)->fork_used = false;
		pthread_mutex_init(&(fork + i)->mutex, NULL);
		i++;
	}
	return (fork);
}

t_philo	*init_philo(t_init_data *data, t_fork *fork)
{
	t_philo	*philo;
	int		i;

	if (data == NULL || fork == NULL)
		return (NULL);
	philo = malloc(sizeof(t_philo) * data->number_philo);
	if (philo == NULL)
		return (NULL);
	pthread_mutex_init(&(philo)->print, NULL);
	pthread_mutex_init(&(philo)->dead, NULL);
	i = 0;
	while (i < data->number_philo)
	{
		data_philo(&philo[i], data, fork, i);
		i++;
	}
	return (philo);
}

void	data_philo(t_philo *philo, t_init_data *data, t_fork *fork, int i)
{
	t_fork	*left;
	t_fork	*right;

	left = (fork + i);
	right = (fork + ((i + 1) % data->number_philo));
	philo->left = left;
	philo->right = right;
	philo->meal_eaten = 0;
	philo->meal_should_eat = data->must_eat;
	philo->philo_number = i + 1;
	philo->philo_size = i;
	philo->data = data;
	pthread_mutex_init(&(philo)->m_philo, NULL);
}
