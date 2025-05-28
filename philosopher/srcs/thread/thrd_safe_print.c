/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_safe_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:07:45 by ast               #+#    #+#             */
/*   Updated: 2025/05/28 06:36:34 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

static char *get_action(int action)
{
    if(action == TAKEN_FORK)
        return("has taken fork");
    if(action == EATING)
        return("is eating");
    if(action == RELEASE_FORK)
        return("has release fork");
    if(action == SLEEPING)
        return("is spleeping");
    if(action == THINKING)
        return("is thinking");
    if(action == DEATH)
        return( "is OFF: end of cycle");
    if(action == DEATH_2)
        return( "is OFF: end of cycle");
    return(NULL);
}


int safe_print(long long timestamp,t_philo *philo, int action)
{
    if(pthread_mutex_lock(philo->print))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    if(action == DEATH)
        printf("\x1b[31m" "%lld %d %s  \n" "\x1b[0m",timestamp, philo->pametres[ID], get_action(action));
    else
        printf("%lld %d %s\n",timestamp, philo->pametres[ID], get_action(action));
    if(pthread_mutex_unlock(philo->print))
    {
        printf("Erreur mutex state lock\n");
        return(0);
    }
    return(1);
}