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

void *ft_kill_philosophes_and_network(t_philosophe ***philosophes, t_petri_network **network, pthread_mutex_t **forks ,int idx)
{
    int i;

    ft_destroy_mutext(&forks, N);
    assert(forks == NULL);
    ft_destroy_network(network);
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
    return(NULL);
}