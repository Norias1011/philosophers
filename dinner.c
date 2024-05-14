/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/14 16:45:26 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*test_print(void *show_data)
{
	t_philo	*new;

	new = (t_philo *)show_data;
	printf("Philo number = %d\n", new->philo_number);
	printf("dinner start : %d\n", new->dinner_start);
	printf("id thread : %ld\n", new->id_thread);
	// printf("left fork number : %d\n", (int)new->left);
	// printf("right fork number : %d\n", (int)new->right);
	return (0);
}

int	dinner(t_philo *philo, t_init_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_create(&philo->id_thread, NULL, (void *)test_print,
				&philo[i]) != 0)
		{
			printf("Error with Pthread\n");
			return (0);
		}
		i++;
	}
	return (1);
}
