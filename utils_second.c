/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:08:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/05/13 11:14:52 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int micro_sec)
{
	long int start_time;

	start_time = 0;
	start_time = time_get();
	while ((time_get() - start_time) < micro_sec)
		usleep(100);
}