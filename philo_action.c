/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:12:27 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/16 14:58:17 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->mutex);
	print_situation(philo, philo->philo_number, FORK);
	philo->left->fork_used = true;
	pthread_mutex_lock(&philo->right->mutex);
	print_situation(philo, philo->philo_number, FORK);
	philo->right->fork_used = true;
	philo->last_eaten_meal = time_get();
	philo->meal_eaten++;
	philo->data->must_eat--;
	print_situation(philo, philo->philo_number, EAT);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->left->mutex);
	philo->left->fork_used = false;
	pthread_mutex_unlock(&philo->right->mutex);
	philo->right->fork_used = false;
}

void	sleep_philo(t_philo *philo)
{
	print_situation(philo, philo->philo_number, SLEEP);
	ft_usleep(philo->data->time_sleep);
}

void	think(t_philo *philo)
{
	print_situation(philo, philo->philo_number, THINK);
	ft_usleep(500);
}

/*void	fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	print_situation(philo, philo->philo_number, FORK);
	fork->fork_used = true;
}

void	remove_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_unlock(&fork->mutex);
	fork->fork_used = false;
}*/