/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_timestamp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:52:01 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 21:54:51 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "thread.h"

long long get_current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        write(2, "gettimeofday() error\n", 22);
    return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}