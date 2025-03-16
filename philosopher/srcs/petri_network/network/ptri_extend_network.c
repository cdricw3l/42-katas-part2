/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_extend_network.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:56:42 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 08:59:17 by cw3l             ###   ########.fr       */
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