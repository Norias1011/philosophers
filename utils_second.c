/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:08:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/21 14:38:50 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long micro_sec)
{
	long	start_time;

	start_time = 0;
	start_time = time_get();
	while ((time_get() - start_time) < micro_sec)
		usleep(100);
}

int	philo_dead(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(philo->dead);
	flag = philo->data->philo_dead;
	pthread_mutex_unlock(philo->dead);
	return (flag);
}

int	must_eat_meal(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(philo->m_philo);
	flag = philo->meal_should_eat;
	pthread_mutex_unlock(philo->m_philo);
	return (flag);
}

void	print_situation_death(t_philo *philo, int philo_number, char *message)
{
	long	time;

	time = (time_get() - philo->data->dinner_start);
	printf("%ld %d %s\n", time, philo_number, message);
	pthread_mutex_unlock((philo->print));
}
