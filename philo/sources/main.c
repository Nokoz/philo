/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:06:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 16:43:38 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_sim	*sim;
	t_philo	*philo;

	if (!ft_init(ac, av, &sim, &philo))
		return (1);

	ft_create_threads(sim, philo);
//	ft_print_log(THINK, philo);
	free(philo);
	free(sim->forks);
	free(sim);
	return (0);
}

void	ft_create_threads(t_sim *sim, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < sim->count)
		ft_th_create(&philo[i].th, ft_run_sim, &philo[i]);
	i = -1;
	while (++i < sim->count)
		ft_th_join(philo[i].th);
	i = -1;
	while (++i < sim->count)
		ft_th_detach(philo[i].th);

}

int	ft_init(int ac, char **av, t_sim **sim, t_philo **philo)
{
	if (ac < 5 || ac > 6)
		return (ft_ac_error());
	*sim = malloc(sizeof(t_sim));
	if (!*sim)
		return (0 * printf("Malloc error\n"));
	if (!ft_init_arg(ac, av, *sim))
		return (0);
	if (!ft_init_forks(*sim))
		return (0);
	*philo = ft_init_philos(*sim);
	if (!philo)
		return (0 * printf("Malloc error\n"));
	return (1);
}

void	*ft_run_sim(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
//	printf("Hello from thread %d\n", philo->id);
	ft_print_log(THINK, philo);
	return (NULL);
}
