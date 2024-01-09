/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:31:03 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/09 16:31:52 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{
	int				count;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				must_eat;
	long long		time;
} 				t_philo;

/*   UTILS   */
int	ft_init(int ac, char **av, t_philo *philo);
int	ft_init_struct(char **av, t_philo *philo);

/*   EROOR   */
int	ft_ac_error(void);
int	ft_time_error(void);
int	ft_struct_error(void);

/*   TIME   */
int	ft_get_time(t_philo *philo);
void	ft_printf_time(long long time);

/*   LOG   */
void	ft_p_fork(long long time, int philo);
void	ft_p_eat(long long time, int philo);
void	ft_p_sleep(long long time, int philo);
void	ft_p_think(long long time, int philo);
void	ft_p_dead(long long time, int philo);
#endif
