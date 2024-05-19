/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:08:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/19 04:24:48 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t micro_sec)
{
	size_t	start_time;

	start_time = 0;
	start_time = time_get();
	while ((time_get() - start_time) < micro_sec)
		usleep(micro_sec / 10);
	return (0);
}

int	philo_dead(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&philo->dead);
	flag = philo->philo_dead;
	pthread_mutex_unlock(&philo->dead);
	return (flag);
}

int	must_eat_meal(t_philo *philo)
{
	int flag;

	pthread_mutex_lock(&philo->m_philo);
	flag = philo->data->must_eat;
	pthread_mutex_unlock(&philo->m_philo);
	return (flag);
}