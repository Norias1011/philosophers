/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:17:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/13 15:32:17 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner(t_philo *philo, t_fork *fork, t_init_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		(philo + i)->data = data;
		if (pthread_create(&philo->id_thread, NULL, /*function name */,
				&philo[i]) != 0)
		{
			printf("Error with Pthread\n");
			return (0);
		}
		i++;
	}
	return (1);
}
