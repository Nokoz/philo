/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:20 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 12:49:33 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_log(char state, t_philo *philo)
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
