/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/19 17:43:51 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner(t_philo *philo, t_init_data *data)
{
	int	i;

	philo->dinner_start = time_get();
	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_create(&((philo + i)->id_thread), NULL, routine, philo + i))
			return (0);
		i++;
	}
	if (pthread_create(&(data->death_checker), NULL, check_death, philo))
		return (0);
	return (1);
}

void	*check_death(void *philo)
{
	t_philo	*philo_pointer;
	int		i;
	size_t	time;

	philo_pointer = (t_philo *)philo;
	while (1)
	{
		i = 0;
		time = time_get();
		while (i < philo_pointer->data->number_philo)
		{
			if (death_checker(&philo_pointer[i], time))
				return (NULL);
			i++;
		}
		ft_usleep(1);
	}
	return (NULL);
}

int	death_checker(t_philo *philo, size_t time)
{
	int	last_real_meal;
	int	flag;

	flag = 0;
	pthread_mutex_lock(&(philo->m_philo));
	last_real_meal = time - philo->last_eaten_meal;
	pthread_mutex_unlock(&(philo->m_philo));
	if (last_real_meal > philo->data->time_die)
	{
		pthread_mutex_lock(&(philo->print));
		pthread_mutex_lock(&(philo->dead));
		philo->data->philo_dead = 1;
		philo->data->end_dinner = true;
		pthread_mutex_unlock(&(philo->dead));
		print_situation_death(philo, philo->philo_number, DIE);
		flag = 1;
	}
	return (flag);
}

void	*routine(void *philo)
{
	t_philo	*philo_pointer;

	philo_pointer = (t_philo *)philo;
	if (philo_pointer->philo_number % 2 != 0)
		ft_usleep(philo_pointer->data->time_eat);
	while (philo_dead(philo_pointer) != 1
		&& philo_pointer->data->end_dinner == false)
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
		if (pthread_join(philo[i].id_thread, NULL))
			flag = 0;
		i++;
	}
	if (pthread_join(data->death_checker, NULL))
		flag = 0;
	return (flag);
}

/*int	*test_print(void *show_data)
{
	t_philo	*new;
	int		i;

	new = (t_philo *)show_data;
	printf("Philo number = %d\n", new->philo_number);
	printf("dinner start : %d\n", new->dinner_start);
	printf("id thread : %ld\n", new->id_thread);
	// printf("left fork number : %d\n", (int)new->left);
	// printf("right fork number : %d\n", (int)new->right);
	return (0);
}*/

/* philo_pointer->data->must_eat > 0
			&& philo_pointer->meal_eaten <= philo_pointer->data->must_eat)
		|| philo_pointer->philo_dead == 0
			|| philo_pointer->end_dinner == false*/