/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:06:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/09 17:01:24 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ft_init(ac, av, &philo) != 0)
		return (1);

	ft_p_eat(philo.time, 3);
	return (0);
}
int	ft_init(int ac, char **av, t_philo *philo)
{
	if (ac < 5 || ac > 6)
		return (ft_ac_error());
	if (ft_init_struct(ac, av, philo) != 0)
		return (1);
	return (0);
}
int	ft_init_struct(int ac, char **av, t_philo *philo)
{
	(void)av;
	if (ft_get_time(philo) != 0)
		return (ft_time_error());
	philo->count = ft_atoi(av[1]);
	if (philo->count < 0)
		return (ft_int_error());
	philo->to_die = ft_atoi(av[2]);
	if (philo->to_die < 0)
		return (ft_int_error());
	philo->to_eat = ft_atoi(av[3]);
	if (philo->to_eat < 0)
		return (ft_int_error());
	philo->to_sleep = ft_atoi(av[4]);
	if (philo->to_sleep < 0)
		return (ft_int_error());
	if (ac == 6)
	{
		philo->must_eat = ft_atoi(av[5]);
		if (philo->must_eat < 0)
			return (ft_int_error());
	}
	return (0);
}
