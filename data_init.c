/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:05:53 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/02 14:48:32 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_av(int ac, char *av[])
{
	int	i;
	int	j;
	int	result_av;

	i = 1;
	result_av = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				result_av = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	if (result_av == 1)
		return (1);
	else
		return (0);
}

t_init_data	*start_data(int ac, char *av[])
{
	t_init_data	*philo_info;
	int			check;

	check = check_av(ac, av);
	if (ac > 5 && check == 1)
	{
		philo_info->number_philo = ft_atoi(av[1]);
		philo_info->time_die = ft_atoi(av[2]) * 1000;
		philo_info->time_eat = ft_atoi(av[3]) * 1000;
		philo_info->time_sleep = ft_atoi(av[4]) * 1000;
		if (ac == 6)
		{
			philo_info->must_eat = ft_atoi(av[5]);
		}
		else
			philo_info->must_eat = 0;
	}
	else
		exit(EXIT_FAILURE);
	return (philo_info);
}
