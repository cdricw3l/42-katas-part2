/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_tempo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:12:06 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/23 02:02:48 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"


float time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-5 * (end->tv_usec - start->tv_usec);
}

int ft_temporisation(int ms)
{
    struct timeval start;
    struct timeval end;

    
    struct timeval tv_start;
    struct timeval tv_end;
    gettimeofday(&start, NULL);
    gettimeofday(&tv_start,NULL);
    gettimeofday(&tv_end,NULL);
    while (tv_end.tv_usec < tv_start.tv_usec + ms)
    {
        gettimeofday(&tv_end,NULL);
    }
    gettimeofday(&end, NULL);
    printf("Test fonction temporisation : %0.8f sec\n", time_diff(&start, &end));
    (void)ms;
    return(0);
}