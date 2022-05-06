/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:50:47 by rchampli          #+#    #+#             */
/*   Updated: 2022/05/06 18:15:38 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *str, t_philo *ph, pthread_mutex_t *pha)
{
	long int		time;

	time = timing() - ph->pa->start_t;
	pthread_mutex_lock(pha);
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0))
		printf("%ld %d %s", time, ph->id, str);
	pthread_mutex_unlock(pha);
}

void	thinking(t_philo *ph)
{
	write_status("is sleeping\n", ph, &ph->pa->write_mutex);
	ft_usleep(ph->pa->sleep);
	write_status("is thinking\n", ph, &ph->pa->write_mutex);
}

void	activity(t_philo *ph)
{
	pthread_mutex_lock(&ph->l_f);
	write_status("has taken a fork\n", ph, &ph->pa->write_mutex);
	if (!ph->r_f)
	{
		ft_usleep(ph->pa->die * 2);
		return ;
	}
	pthread_mutex_lock(ph->r_f);
	write_status("has taken a fork\n", ph, &ph->pa->write_mutex);
	write_status("is eating\n", ph, &ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->ms_eat = timing();
	pthread_mutex_unlock(&ph->pa->time_eat);
	ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(&ph->l_f);
	thinking(ph);
}
