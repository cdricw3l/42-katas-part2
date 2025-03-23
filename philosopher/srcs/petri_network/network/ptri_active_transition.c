/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_active_transition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:25:51 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 21:30:53 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ptri_network.h"

int ft_is_activable_transition(t_petri_network *network, int t, int id)
{
    int i;
    int acc_m_in;
    int acc_m_out;
    
    if(!ft_network_check(network, network->p))  
        return(-1);
    i = 0;
    acc_m_in = 0;
    acc_m_out = 0;
    while (i < network->p)
    {
        //bien faire attantion a optimiser ce genre de besoin et ne faire faire inutilisement une doucle boucles.
        if(network->M0[i] < network->M_out[i][t])
            return(0);
        acc_m_in += network->M_in[i][t];
        acc_m_out += network->M_out[i][t];
        i++;
    }
    if(acc_m_out < acc_m_in)
        return(0);
    printf( "\033[0;33m" "Transition: %d activable par le philosphe %d\n" "\x1b[0m",t, id);
    return(1);
}

int ft_active_transition(t_petri_network *network, int t, int id)
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
    if (ft_is_activable_transition(network, t, id))
    {
        i = 0;
        printf( "\033[0;32m" "Transition: %d activé par le philosphe %d\n" "\x1b[0m",t, id);
        while (i < network->p)
        {
            if(reachability[i][t] != 0)
            {
                network->M0[i] = network->M0[i] + reachability[i][t];
                //printf("modification de l'etat M0 a l'index %d par le philosophe %d\n", i, id);
            }
            i++;
        }
    }
    else
    {
        printf("\x1b[31m" "Transition %d non activable par le philosphe %d\n" "\x1b[0m", t, id);
        return(-1);
    }
    ft_clean_reachability_matrix(&reachability,network->p);
    return(1);
}
