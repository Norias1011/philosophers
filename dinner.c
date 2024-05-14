/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/14 16:19:21 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test_print(void *show_data)
{
	t_philo	*new;

	new = (t_philo *)show_data;
	printf("Dead = %d\n", new->dead);
	printf("dinner start : %d\n", new->dinner_start);
	printf("id thread : %d\n", new->id_thread);
	printf("left fork number : %d", new->left);
	printf("right fork number : %d\n", new->right);
}

int	dinner(t_philo *philo, t_fork *fork, t_init_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_create(&philo->id_thread, NULL, test_print, &philo[i]) != 0)
		{
			printf("Error with Pthread\n");
			return (0);
		}
		i++;
	}
	return (1);
}
