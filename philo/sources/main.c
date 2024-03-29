/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:06:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/16 17:21:52 by gvardaki         ###   ########.fr       */
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
	free(philo);
	ft_destroy_mutexes(sim);
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
	{
		free(*sim);
		return (0);
	}
	*philo = ft_init_philos(*sim);
	if (!philo)
	{
		free(*sim);
		free((*sim)->forks);
		return (0 * printf("Malloc error\n"));
	}
	(*sim)->philos = *philo;
	return (1);
}

void	*ft_run_sim(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->sim->count == 1)
	{
		ft_mut_lock(&philo->sim->forks[0]);
		ft_print_log(FORK, philo);
		usleep(philo->sim->to_die * 1000);
		ft_die(philo);
		return (NULL);
	}
	ft_start_dinner(philo);
	return (NULL);
}

void	ft_start_dinner(t_philo *philo)
{
	if (philo->sim->count % 2 == 0)
	{
		if ((philo->id - 1) % 2 == 0)
			ft_sleep(philo);
		else if ((philo->id - 1) % 2 == 1)
		{
			ft_take_forks(philo);
			ft_eat(philo);
		}
	}
	else
	{
		if ((philo->id -1) % 3 == 0)
			ft_sleep(philo);
		else if ((philo->id - 1) % 3 == 1)
		{
			ft_take_forks(philo);
			ft_eat(philo);
		}
		else
			ft_think(philo);
	}
}
