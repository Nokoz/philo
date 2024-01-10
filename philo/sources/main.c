/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:06:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 13:08:54 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_sim	sim;
	t_philo	*philo;

	if (!ft_init(ac, av, &sim))
		return (1);

	philo = malloc(sizeof(t_philo));
	philo->id = 4;
	philo->sim = &sim;
	ft_print_log(THINK, philo);
	free(philo);
	return (0);
}

int	ft_init(int ac, char **av, t_sim *sim)
{
	if (ac < 5 || ac > 6)
		return (ft_ac_error());
	if (!ft_init_arg(ac, av, sim))
		return (0);
	if (!ft_init_forks(sim))
		return (0);
	return (1);
}
