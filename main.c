/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:57:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/21 15:12:39 by akinzeli         ###   ########.fr       */
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
	ft_usleep(data->time_eat + data->time_sleep + 20000);
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
	if (!(dinner(philos, data)))
		code = EXIT_FAILURE;
	while (check_death_full(philos) != 1 && check_death(philos) == NULL)
		ft_usleep(1);
	if (!(join_thread(philos, data)))
	{
		code = EXIT_FAILURE;
		return (ft_finish(philos, fork, data, code));
	}
	return (ft_finish(philos, fork, data, code));
}

int	check_death_full(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock((philo->dead));
	pthread_mutex_lock((philo->m_philo));
	if (philo->data->philo_dead == 1)
		flag = 1;
	else if (philo->data->finish_eating_count == philo->data->number_philo)
		flag = 1;
	pthread_mutex_unlock((philo->dead));
	pthread_mutex_unlock((philo->m_philo));
	return (flag);
}
