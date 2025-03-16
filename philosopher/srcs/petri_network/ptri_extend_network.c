/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_extend_network.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:56:42 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 01:13:30 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

int **ft_extend_network(t_petri_network *network, int n)
{
    int **new_matrice;

    new_matrice = ft_create_matrice(network->p, network->t, n);
    if(!new_matrice)
        return(NULL);
    return(new_matrice);
}