/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:31:03 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/10 13:06:05 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define FORK 'f'
# define EAT 'e'
# define SLEEP 's'
# define THINK 't'
# define DEAD 'd'

typedef struct s_sim
{
	int				count;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				must_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mut;
} 				t_sim;

typedef struct s_philo
{
	int				id;
	struct s_sim	*sim;
}				t_philo;

/*   INIT   */
int			ft_init(int ac, char **av, t_sim*sim);
int			ft_init_arg(int ac, char **av, t_sim*sim);
int			ft_init_forks(t_sim *sim);

/*   UTILS   */
void		ft_print_log(char state, t_philo *philo);

/*   ATOI   */
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

/*   EROOR   */
int			ft_ac_error(void);
int			ft_time_error(void);
int			ft_int_error(void);

/*   TIME   */
long long	ft_get_time(void);
void		ft_printf_time(long long time);

/*   LOG   */
void		ft_p_fork(long long time, int philo);
void		ft_p_eat(long long time, int philo);
void		ft_p_sleep(long long time, int philo);
void		ft_p_think(long long time, int philo);
void		ft_p_dead(long long time, int philo);

/*   MUTEX WRAP   */
void	ft_mut_del(pthread_mutex_t *mutex);
void	ft_mut_unlock(pthread_mutex_t *mutex);
void	ft_mut_lock(pthread_mutex_t *mutex);
void	ft_mut_init(pthread_mutex_t *mutex);
#endif
