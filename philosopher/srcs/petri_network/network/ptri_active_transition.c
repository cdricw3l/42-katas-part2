/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_active_transition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:25:51 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/20 23:40:12 by cw3l             ###   ########.fr       */
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
    return(1);
}

int ft_active_transition(t_petri_network *network, int t)
{
    int **reachability;
    int i;
    
    if(!ft_network_check(network, network->p))
    {
        printf("ERR: network\n");
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
        printf("Transition: %d activé\n",t);
    }
    else
    {
        printf("Transiont non activable\n");
    }
    ft_clean_reachability_matrix(&reachability,network->p);
    return(1);
}
