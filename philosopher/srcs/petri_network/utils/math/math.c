/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:52:22 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 22:14:37 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../network/ptri_network.h"

int ft_is_enabled_transition(t_petri_network *network, int t)
{
    int i;
    int j;
    
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
