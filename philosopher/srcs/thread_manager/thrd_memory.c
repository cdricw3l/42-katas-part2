/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:29:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 20:30:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

static void ft_destroy_state(t_philosophe ***philosophes)
{
    if(*philosophes)
    {
        if((*philosophes)[0]->state)
        {
            free((*philosophes)[0]->state);
            (*philosophes)[0]->state = NULL;
        }
    }
}

void *ft_kill_philosophes_and_network(t_philosophe ***philosophes, t_petri_network **network, pthread_mutex_t ***forks ,int idx)
{
    int i;
    TEST_START;
    ft_destroy_mutext(forks, (*network)->n);
    ft_destroy_network(network);
    ft_destroy_state(philosophes);
    if(*philosophes)
    {
        i = 0;
        while (i < idx)
        {
            (*philosophes)[i]->network = NULL;
            free((*philosophes)[i]);
            (*philosophes)[i] = NULL;
            i++;
        }
        free(*philosophes);
        *philosophes = NULL;
    }
    TEST_SUCCES;
    return(NULL);
}
