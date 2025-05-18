/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_philo_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:15:58 by ast               #+#    #+#             */
/*   Updated: 2025/05/18 22:58:00 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	*thread_philo_cycle(void *p)
{
	int			i;
	t_philo		*philo;
	
	long long	last_eat;
	
	philo = (t_philo *)p;
	i = 0;
	while (get_state(philo, 0) == OFF)
	{
		usleep(500);
	}

	while (get_state(philo, 0) == ON && philo->pametres[CYCLE] > i)
	{
		
		put_timestamp(philo, TS_CYCLE, philo->start);
		put_timestamp(philo, TS_START, philo->start);
		//printf("ici %lld\n", philo->time_data[TS_START]);
		philo->time_data[TS_LAST_EAT] = last_eat;

		while (!get_forks(philo))
		{
			safe_print(get_current_time() - philo->start, philo, THINKING);
		}
		safe_print(get_current_time() - philo->start, philo, TAKEN_FORK);
		safe_print(get_current_time() - philo->start, philo, EATING);
		put_timestamp(philo, TS_END_THINK, philo->start);
		
		if(philo->time_data[TS_END_THINK] - philo->time_data[TS_LAST_EAT] > philo->pametres[TTD])
		{
			change_state(philo, 0, OFF);
			return (NULL);
		}
			
		ft_temporisation(philo->pametres[TTE]);
		put_timestamp(philo, TS_END_EAT, philo->start);
		last_eat = philo->time_data[TS_END_EAT];
		release_forks(philo, get_current_time() - philo->start);
		//safe_print(get_current_time() - start, philo, RELEASE_FORK);
		safe_print(get_current_time() - philo->start, philo, SLEEPING);
		ft_temporisation(philo->pametres[TTS]);
		put_timestamp(philo, TS_END_SPLEEP, philo->start);
		i++;
	}
	display_philo_time_board(philo,1);

	change_state(philo, philo->pametres[STATE_1], OFF);
	//printf("\x1b[31m" "PHILO %d WAS KILLED\n" "\x1b[0m", philo->pametres[ID]);
	return(p);
}
