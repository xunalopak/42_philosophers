/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:24:17 by rchampli          #+#    #+#             */
/*   Updated: 2022/05/06 17:56:45 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						m_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						stop;
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_f;
	pthread_mutex_t			l_f;
	t_arg					*pa;
	long int				ms_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

int				ft_strlen(char *s);
int				ft_atoi(const char *str);
int				check_death(t_philo *ph, int i);
int				check_death2(t_p *p);
long int		timing(void);
void			ft_usleep(long int time_in_ms);
int				start(t_p *p);
int				parse_args(int argc, char **argv, t_p *p);
int				thread(t_p *p);
int				ft_error(char *s, int error);
void			activity(t_philo *ph);
void			write_status(char *str, t_philo *ph, pthread_mutex_t *pha);
void			*is_dead(void *data);

#endif