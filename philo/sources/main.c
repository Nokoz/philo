/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:06:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/09 16:35:42 by gvardaki         ###   ########.fr       */
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
	if (ft_init_struct(av, philo) != 0)
		return (ft_struct_error());
	return (0);
}
int	ft_init_struct(char **av, t_philo *philo)
{
	(void)av;
	if (ft_get_time(philo) != 0)
		return (1);
	return (0);
}
