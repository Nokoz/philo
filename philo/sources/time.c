/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:35 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/15 08:48:32 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_time_error());
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

void	ft_printf_time(long long time)
{
	int	h;
	int	m;
	int	s;
	int	ms;

	h = time / 3600000;
	h %= 24;
	time %= 3600000;
	m = time / 60000;
	time %= 60000;
	s = time / 1000;
	ms = time % 1000;
	printf("[%dH %dM %dS %dmS]", h, m, s, ms);
}
