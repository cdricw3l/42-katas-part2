/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:31:13 by ast               #+#    #+#             */
/*   Updated: 2025/05/18 18:06:25 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_network.h"

void	*destroy_network(t_network **network)
{
	int	p;

	p = (*network)->pametres[P];
	ft_destroy_mutex_struct(&(*network)->mutex_data, p);
	ft_destroy_philos(&(*network)->philos, (*network)->pametres[P]);
	ft_destroy_timeboard(&((*network)->time_board), TS_SIZE_ARR);
	free(*network);
	*network = NULL;
	return (NULL);
}

void	*ft_destroy_philos(t_philo ***philos, int len)
{
	int		i;
	t_philo	**p;

	i = 0;
	p = *philos;
	while (i < len)
	{
		free(p[i]);
		p[i] = NULL;
		i++;
	}
	free(*philos);
	return (NULL);
}

void	*ft_destroy_mutexs(t_mutex ***mutexs, int len)
{
	int		i;
	t_mutex	**f;

	i = 0;
	f = *mutexs;
	while (i < len)
	{
		if (f[i])
		{
			if (pthread_mutex_destroy(f[i]) != 0)
				printf("Mutex destroy err");
			free(f[i]);
			f[i] = NULL;
		}
		i++;
	}
	free(*mutexs);
	*mutexs = NULL;
	return (NULL);
}

void	*ft_destroy_mutex_struct(t_mutex_data **mutex_data, int len)
{
	ft_destroy_mutexs(&(*mutex_data)->forks, len);
	ft_destroy_mutexs(&(*mutex_data)->pens, len);
	ft_destroy_mutexs(&(*mutex_data)->m_states, len);
	free(*mutex_data);
	return (NULL);
}
