/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:55:46 by ast               #+#    #+#             */
/*   Updated: 2025/05/18 20:57:57 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	get_fork_number(t_philo *philo, int fork_number)
{
	int	id;
	int	n_philo;

	id = philo->pametres[ID];
	n_philo = philo->pametres[P];
	if (id == 0)
	{
		if (fork_number == 1)
			return (id);
		if (fork_number == 2)
			return (n_philo - 1);
	}
	else if (id > 0)
	{
		if (fork_number == 1)
			return (id - 1);
		if (fork_number == 2)
			return (id);
	}
	return (-1);
}

int	release_forks(t_philo *philo, long long timestamps)
{
	int	err;
	(void)timestamps;
	err = 0;
	if (pthread_mutex_unlock(philo->fork_1))
		err += 1;
	if (pthread_mutex_unlock(philo->fork_2))
		err += 1;
	if (err)
		return (0);
	return (1);
}

int	get_forks(t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork_1))
		return (0);
	if (pthread_mutex_lock(philo->fork_2))
		return (0);
	return (1);
}
