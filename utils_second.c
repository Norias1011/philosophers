/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:08:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/15 11:18:26 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t micro_sec)
{
	size_t start_time;

	start_time = 0;
	start_time = time_get();
	while ((time_get() - start_time) < micro_sec)
		usleep(micro_sec / 10);
	return (0);
}