/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:48:18 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/16 08:19:45 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_mut_init(pthread_mutex_t *mutex)
{
	pthread_mutex_init(mutex, NULL);
}

void	ft_mut_lock(pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
}

int	ft_mut_unlock(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	return (1);
}

void	ft_mut_del(pthread_mutex_t *mutex)
{
	pthread_mutex_destroy(mutex);
}
