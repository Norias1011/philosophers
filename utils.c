/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:06:09 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/02 14:45:18 by akinzeli         ###   ########.fr       */
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
