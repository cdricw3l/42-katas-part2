/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:45:09 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/22 11:01:44 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

int ft_timer(int ms)
{
    struct timeval tv;
    struct timezone tz;
    (void)ms;
    printf("Seconds since 1/1/1970: %lu\n",tv.tv_sec);
    printf("Microseconds: %d\n",tv.tv_usec);
    printf("Minutes west of Greenwich: %d\n",tz.tz_minuteswest/ 60);
    printf("Daylight Saving Time adjustment: %d\n",tz.tz_dsttime);

    return(1);
}