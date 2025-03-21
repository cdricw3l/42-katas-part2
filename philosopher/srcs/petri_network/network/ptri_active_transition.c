/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_active_transition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:25:51 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/21 10:17:35 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ptri_network.h"

int ft_is_activable_transition(t_petri_network *network, int t)
{
    int i;
    
    if(!ft_network_check(network, network->p))  
        return(-1);
    i = 0;
    while (i < network->p)
    {
        //bien faire attantion a optimiser ce genre de besoin et ne faire faire inutilisement une doucle boucles.
        if(network->M0[i] < network->M_out[i][t])
            return(0);
        i++;
    }
    printf( "\033[0;33m" "Transition: %d activable\n" "\x1b[0m",t);
    return(1);
}

int ft_active_transition(t_petri_network *network, int t)
{
    int **reachability;
    int i;
    
    if(!ft_network_check(network, network->p))
    {
        printf("\x1b[31m" "ERR: network\n" "\x1b[0m");
        return(-1);
    }
    reachability = ft_get_reachability_matrix(network);
    if(!reachability)
        return(0);
    if (ft_is_activable_transition(network, t))
    {
        i = 0;
        while (i < network->p)
        {
            network->M0[i] = network->M0[i] + reachability[i][t];
            i++;
        }
        printf( "\033[0;32m" "Transition: %d activé\n" "\x1b[0m",t);
    }
    else
    {
        printf("\x1b[31m" "Transition %d non activable\n" "\x1b[0m", t);
    }
    ft_clean_reachability_matrix(&reachability,network->p);
    return(1);
}
