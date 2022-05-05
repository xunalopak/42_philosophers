/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:16:54 by rchampli          #+#    #+#             */
/*   Updated: 2022/05/05 20:57:22 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *s, int error)
{
	printf("Error: %s\nError code: %d\n", s, error);
	return (error);
}

int	check_death2(t_p *p)
{
	pthread_mutex_lock(&p->a.dead);
	if (p->a.stop)
	{
		pthread_mutex_unlock(&p->a.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->a.dead);
	return (0);
}

void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		ft_usleep(1);
	while (++i < p->a.total)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->a.write_mutex);
	i = -1;
	while (++i < p->a.total)
		pthread_mutex_destroy(&p->ph[i].l_f);
	if (p->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->a.m_eat);
	free(p->ph);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (!parse_args(ac, av, &p))
		return (ft_error("Please check the number", 3));
	p.ph = malloc(sizeof(t_philo) * p.a.total);
	if (!p.ph)
		return (ft_error("Malloc is NULL", 4));
	if (!start(&p) || !thread(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
}
