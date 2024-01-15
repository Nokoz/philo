/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:59:52 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/15 13:43:27 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_philo *philo)
{
	//check status
	if (ft_die_check(philo))
		return (ft_die(philo));
	philo->sim->must_eat--;
	ft_print_log(EAT, philo);
	philo->belly_full = ft_get_time();
	ft_action_time(philo, philo->sim->to_eat);
	ft_mut_unlock(&philo->sim->forks[philo->id - 1]);
	ft_mut_unlock(&philo->sim->forks[ft_left_fork(philo)]);
	ft_sleep(philo);
}

void	ft_sleep(t_philo *philo)
{
	//check status
	if (ft_die_check(philo))
		return (ft_die(philo));
	ft_print_log(SLEEP, philo);
	ft_action_time(philo, philo->sim->to_sleep);
	ft_think(philo);
}

void	ft_think(t_philo *philo)
{
	//check status
	if (ft_die_check(philo))
		return (ft_die(philo));
	ft_print_log(THINK, philo);
	ft_take_forks(philo);
	ft_eat(philo);
}

void	ft_take_forks(t_philo *philo)
{
	ft_mut_lock(&philo->sim->forks[philo->id - 1]);
	ft_print_log(FORK, philo);
	if (ft_die_check(philo))
		return (ft_die(philo));
	ft_mut_lock(&philo->sim->forks[ft_left_fork(philo)]);
	ft_print_log(FORK, philo);
	if (ft_die_check(philo))
		return (ft_die(philo));
}

int	ft_left_fork(t_philo *philo)
{
	if (philo->id > 1)
		return (philo->id - 1);
	else
		return (philo->sim->count - 1);
}
