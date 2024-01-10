/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:43:06 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 16:33:14 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_th_create(pthread_t *th, void *(*function)(void *), void *arg)
{
	return (pthread_create(th, NULL, function, arg));
}

int	ft_th_join(pthread_t th)
{
	return (pthread_join(th, NULL));
}

int	ft_th_detach(pthread_t th)
{
	return (pthread_detach(th));
}
