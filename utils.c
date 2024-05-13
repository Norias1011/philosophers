/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:06:09 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/13 11:08:23 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	int	result;

	result = 0;
	if (c >= '0' && c <= '9')
	{
		result = 1;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	char	*c;
	int		i;
	int		number;
	int		parity;

	c = (char *)str;
	i = 0;
	number = 0;
	parity = 1;
	while ((c[i] >= 9 && c[i] <= 13) || c[i] == 32)
		i++;
	if (c[i] == '+' || c[i] == '-')
	{
		if (c[i] == '-')
			parity = -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		number = number * 10;
		number = number + c[i] - '0';
		i++;
	}
	return (number * parity);
}
int	check_av(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
size_t	time_get(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday error\n");
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	print_situation(t_philo *philo, int philo_number, char *message)
{
	pthread_mutex_lock(&(philo->print));
	if (!(philo->philo_dead))
	{
		printf("%d ", time_get() - philo->dinner_start);
		printf("%d ", philo_number + 1);
		printf("%s\n", message);
	}
	pthread_mutex_unlock(&(philo->print));
	return ;
}
