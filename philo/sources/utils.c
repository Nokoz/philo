/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/15 12:30:59 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_log(int state, t_philo *philo)
{
	ft_mut_lock(&(philo->sim->print_mut));
	if (state == DEAD)
		ft_p_dead(ft_get_time(), philo->id);
	if (1) //check status
	{
		if (state == FORK)
			ft_p_fork(ft_get_time(), philo->id);
		else if (state == EAT)
			ft_p_eat(ft_get_time(), philo->id);
		else if (state == SLEEP)
			ft_p_sleep(ft_get_time(), philo->id);
		else if (state == THINK)
			ft_p_think(ft_get_time(), philo->id);
	}
	ft_mut_unlock(&(philo->sim->print_mut));
}

void	ft_die(t_philo *philo)
{
	int	i;

	i = 0;
	philo->state = DEAD;
	ft_print_log(DEAD, philo);
	while (i < philo->sim->count)
	{
		ft_mut_unlock(&philo->sim->forks[i]);
		i++;
	}
}

int	ft_die_check(t_philo *philo)
{
	if (ft_get_time() - philo->belly_full > philo->sim->to_die)
		return (1);
	else
		return (0);
}

void	ft_action_time(t_philo *philo, int time)
{
	long long	end;

	end = ft_get_time() + time;
	while (end >= ft_get_time())
	{
		usleep(1000);
		if (ft_die_check(philo))
			return (ft_die(philo));
	}
}
