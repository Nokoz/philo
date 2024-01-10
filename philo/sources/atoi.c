/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:36:40 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 11:34:22 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (!c)
		return (0);
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static const char	*skip_zero(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (str + i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	str = skip_zero(str + i);
	i = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	if (i <= 19)
		return (res * sign);
	else
		return (-1);
}
