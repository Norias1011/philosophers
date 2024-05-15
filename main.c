/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/15 15:26:33 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_philo *philo, t_fork *fork, t_init_data *data)
{
	free(philo);
	free(fork);
	free(data);
	return (0);
}

void	ft_finish(t_philo *philo, t_fork *fork, t_init_data *data)
{
	pthread_mutex_destroy(&(philo)->print);
	pthread_mutex_destroy(&(philo)->dinner);
	pthread_mutex_destroy(&(philo)->dead);
	free_all(philo, fork, data);
}

int	main(int ac, char *av[])
{
	t_init_data	*data;
	t_fork		*fork;
	t_philo		*philos;

	data = start_data(ac, av);
	fork = init_fork(data);
	philos = init_philo(data, fork);
	if (data == 0 || fork == 0 || philos == 0)
	{
		ft_finish(philos, fork, data);
		return (printf(ERROR_MSG));
	}
	printf("all good before dining function\n");
	if (!(dinner(philos, data)))
	{
		ft_finish(philos, fork, data);
		return (printf("Someone died\n"));
	}
	ft_finish(philos, fork, data);
	return (0);
}
