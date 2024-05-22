/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/22 12:07:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner(t_philo *philo, t_init_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_create(&((philo + i)->id_thread), NULL, routine, philo + i))
			return (0);
		i++;
	}
	return (1);
}

void	*check_death(void *philo)
{
	t_philo	*philo_pointer;
	int		i;
	long	time;

	philo_pointer = (t_philo *)philo;
	i = 0;
	time = time_get() - philo_pointer->data->dinner_start;
	while (i < philo_pointer->data->number_philo)
	{
		if (death_checker(&philo_pointer[i], time))
			return (NULL);
		i++;
	}
	return (NULL);
}

int	death_checker(t_philo *philo, size_t time)
{
	long	last_real_meal;
	int		flag;

	flag = 0;
	pthread_mutex_lock((philo->m_philo));
	last_real_meal = time - philo->last_eaten_meal;
	pthread_mutex_unlock((philo->m_philo));
	if (last_real_meal > philo->data->time_die
		&& philo->data->finish_eating_count < philo->data->number_philo)
	{
		pthread_mutex_lock((philo->print));
		pthread_mutex_lock((philo->dead));
		philo->data->philo_dead = 1;
		philo->data->end_dinner = true;
		pthread_mutex_unlock((philo->dead));
		print_situation_death(philo, philo->philo_number, DIE);
		flag = 1;
	}
	return (flag);
}

void	*routine(void *philo)
{
	t_philo	*philo_pointer;

	philo_pointer = (t_philo *)philo;
	if (philo_pointer->philo_number % 2 == 0)
		ft_usleep(philo_pointer->data->time_eat);
	while (philo_dead(philo_pointer) != 1 || must_eat_meal(philo_pointer) != 0)
	{
		think(philo_pointer);
		eat(philo_pointer);
		if (must_eat_meal(philo_pointer) == 0 || philo_dead(philo_pointer) == 1)
			break ;
		sleep_philo(philo_pointer);
	}
	return (NULL);
}

int	join_thread(t_philo *philo, t_init_data *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < data->number_philo)
	{
		if (pthread_detach(philo[i].id_thread))
			flag = 0;
		i++;
	}
	pthread_detach(philo->id_thread);
	return (flag);
}
