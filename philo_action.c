/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:12:27 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/28 15:56:24 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->data->number_philo == 1)
		return ;
	print_situation(philo, philo->philo_number, EAT);
	pthread_mutex_lock(philo->m_philo);
	philo->last_eaten_meal = time_get() - philo->data->dinner_start;
	philo->meal_eaten++;
	philo->meal_should_eat--;
	if (philo->meal_should_eat == 0)
		philo->data->finish_eating_count++;
	pthread_mutex_unlock(philo->m_philo);
	ft_usleep(philo->data->time_eat);
	remove_fork(philo->left);
	remove_fork(philo->right);
}

void	sleep_philo(t_philo *philo)
{
	if (philo->data->number_philo == 1)
		return ;
	print_situation(philo, philo->philo_number, SLEEP);
	ft_usleep(philo->data->time_sleep);
}

void	think(t_philo *philo)
{
	print_situation(philo, philo->philo_number, THINK);
	ft_usleep(1);
	if (philo->philo_number % 2 == 0)
	{
		fork_use(philo, philo->left);
		fork_use(philo, philo->right);
	}
	else
	{
		if (philo->data->number_philo == 1)
		{
			print_situation(philo, philo->philo_number, FORK);
			ft_usleep(philo->data->time_die + 1);
			return ;
		}
		fork_use(philo, philo->right);
		fork_use(philo, philo->left);
	}
}

void	fork_use(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	print_situation(philo, philo->philo_number, FORK);
	fork->fork_used = true;
}

void	remove_fork(t_fork *fork)
{
	fork->fork_used = false;
	pthread_mutex_unlock(&fork->mutex);
}
