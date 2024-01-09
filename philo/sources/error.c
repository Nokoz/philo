/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:13:38 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/09 13:26:31 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_ac_error(void)
{
	printf("Arguments can only be 4 or 5 numeric values\n");
	return (1);
}
int	ft_time_error(void)
{
	printf("Error retrieving time\n");
	return (1);
}
int	ft_struct_error(void)
{
	printf("Error in stuct\n");
//free;
	return (1);
}
