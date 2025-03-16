/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_extend_network.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:56:42 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 21:07:42 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

t_petri_network *ft_extend_network(t_petri_network *network, t_extend_data ext_data)
{
    t_petri_network *new_matrice;
    (void) ext_data;

    new_matrice = NULL;
    if(!network || !ft_network_check(network, network->p))
		  return (NULL);
    return(new_matrice);
}


int ft_add_add(t_petri_network *network, t_arc arc)
{

    // est ce un ajout ou un retrai: est ce t ---> p or p ---> t.?
    // Si t ---> p, action sur W+ arc.direction == 0
    // Si p ---> t, action sur w-

    if(!network && !ft_network_check(network, network->p))
        return(0);
    if(arc.direction == t_to_p)
    {
        //verification de la matrice.
        if(!network->M_in || !network->M_in[arc.p])
            return(0);
        network->M_in[arc.p][arc.t] = arc.weight;
    }
    if(arc.direction == p_to_t)
    {
        //verification de la matrice.
        if(!network->M_out || !network->M_in[arc.p])
            return(0);
        network->M_out[arc.p][arc.t] = arc.weight;
    }
    return(1);
}