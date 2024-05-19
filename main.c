/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/19 17:03:27 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo, t_fork *fork, t_init_data *data)
{
	free(philo);
	free(fork);
	free(data);
}

int	ft_finish(t_philo *philo, t_fork *fork, t_init_data *data, int code)
{
	pthread_mutex_destroy(&(philo)->print);
	// pthread_mutex_destroy(&(philo)->dinner);
	pthread_mutex_destroy(&(philo)->dead);
	free_all(philo, fork, data);
	return (code);
}

int	main(int ac, char *av[])
{
	t_init_data	*data;
	t_fork		*fork;
	t_philo		*philos;
	int			code;

	code = EXIT_SUCCESS;
	data = start_data(ac, av);
	fork = init_fork(data);
	philos = init_philo(data, fork);
	if (data == 0 || fork == 0 || philos == 0)
	{
		code = EXIT_FAILURE;
		printf(ERROR_MSG);
		return (ft_finish(philos, fork, data, code));
	}
	printf("all good before dining function\n");
	if (!(dinner(philos, data)))
		code = EXIT_FAILURE;
	if (!(join_thread(philos, data)))
	{
		code = EXIT_FAILURE;
		return (ft_finish(philos, fork, data, code));
	}
	return (ft_finish(philos, fork, data, code));
}
