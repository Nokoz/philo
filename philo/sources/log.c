/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:22:59 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/09 16:32:48 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_p_fork(long long time, int philo)
{
	ft_printf_time(time);
	printf(" %d has taken a fork\n", philo);
}

void	ft_p_eat(long long time, int philo)
{
	ft_printf_time(time);
	printf(" %d is eating\n", philo);
}

void	ft_p_sleep(long long time, int philo)
{
	ft_printf_time(time);
	printf(" %d is sleeping\n", philo);
}

void	ft_p_think(long long time, int philo)
{
	ft_printf_time(time);
	printf(" %d is thinking\n", philo);
}

void	ft_p_dead(long long time, int philo)
{
	ft_printf_time(time);
	printf(" %d died\n", philo);
}
