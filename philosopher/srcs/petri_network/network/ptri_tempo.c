/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_tempo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:12:06 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/24 10:02:07 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"


float time_diff(struct timeval *start, struct timeval *end) 
{
    return (end->tv_sec - start->tv_sec) + 1e-5 * (end->tv_usec - start->tv_usec);
}

int get_current_time(void)
{
    struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int ft_temporisation(int ms, int id, int mode)
{
    
	int	start;
    struct timeval	s;
    struct timeval	end;

    gettimeofday(&s, NULL);
	start = get_current_time();
    printf("start %d\n",start);
    
	while ((get_current_time() - start) < ms)
        usleep(500);
    
    gettimeofday(&end, NULL);
    
    if(mode == 0)
    {
        printf("elapsed time a dormir par le philosophe : %d :  %f\n", id,time_diff(&s, &end));

    } 
    else if(mode == 1)
    {

        printf("elapsed time a manger pour le philosophe : %d :  %f\n", id,time_diff(&s, &end));
    }
        
	return (0);

}


