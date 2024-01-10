/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:45:44 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 13:08:53 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_number(char *s, int ac)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0 * printf("Argument %d is not numeric\n", ac));
	}
	i = ft_atoi(s);
	if (ac != 1)
	{
		if (i < 60)
			return (0 * printf("Time must be greater than 60\n"));
	}
	else if (ac == 1)
	{
		if (i > 200)
			return (0 * printf("Can't simulate more than 200 philosophers\n"));
	}
	if (i < 0)
		return (0 * ft_int_error());
	return (1);
}

static int	ft_check_arg(char **av)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!ft_check_number(av[i], i))
			return (0);
		i++;
	}
	if (av[5])
	{
		i = -1;
		while (av[5][++i])
		{
			if (!ft_isdigit(av[5][i]))
				return (0 * printf("Argument %d is not numeric\n", 5));
		}
		i = ft_atoi(av[5]);
		if (i < 0)
			return (0 * ft_int_error());
	}
	return (1);
}

int	ft_init_arg(int ac, char **av, t_sim *sim)
{
	if (!ft_check_arg(av))
		return (0);
	sim->start_time = ft_get_time();
	if (sim->start_time == -1)
		return (ft_time_error());
	sim->count = ft_atoi(av[1]);
	sim->to_die = ft_atoi(av[2]);
	sim->to_eat = ft_atoi(av[3]);
	sim->to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		sim->must_eat = ft_atoi(av[5]);
	else
		sim->must_eat = -1;
	return (1);
}

int	ft_init_forks(t_sim *sim)
{
	int					i;
	pthread_mutex_t	*forks;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * sim->count);
	if (!forks)
		return (0 * printf("Malloc error\n"));
	while (++i < sim->count)
		ft_mut_init(&forks[i]);
	ft_mut_init(&(sim->print_mut));
	sim->forks = forks;
	return (1);
}
