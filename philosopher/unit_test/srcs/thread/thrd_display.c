/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:43:07 by ast               #+#    #+#             */
/*   Updated: 2025/05/18 20:25:34 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

#define MODE_INTERVAL   0
#define MODE_TIME_ST    1

char	*get_column_name(int i)
{
	if (i == TS_CYCLE)
		return ("Cycle:");
	if (i == TS_START)
		return ("Start:");
	if (i == TS_LAST_EAT)
		return ("Last eat");
	if (i == TS_END_THINK)
		return ("End Think:");
	if (i == TS_END_EAT)
		return ("End Eat:");
	if (i == TS_END_SPLEEP)
		return ("End sleep:");
	return ("");
}

void	display_all_philo_time_board(t_philo **philo, int mode)
{
	int	i;

	i = 0;
	if (!philo || mode < 0 || mode > 1)
		return ;
	while (i < philo[0]->pametres[P])
	{
		display_philo_time_board(philo[i], mode);
		i++;
	}
}

void	display_philo_time_board(t_philo *philo, int mode)
{
	int			i;
	long long	*time_board;

	i = 0;
	time_board = philo->time_data;
	if (!time_board)
		return ;
	printf("Philosopher %d\t", philo->pametres[ID]);
	while (i < TS_SIZE_ARR)
	{
		if (i == 0)
			printf("%s %lld ", get_column_name(i), time_board[i]);
		else
		{
			if (mode == MODE_INTERVAL)
				printf("%s %lld ", get_column_name(i),
					time_board[i] - time_board[TS_START]);
			else
				printf("%s %lld ", get_column_name(i),time_board[i]);
		}
		i++;
	}
	printf("\n");
}