/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/14 01:42:38 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

#define TT_DIE 1
#define TT_EAT 2
#define TT_SPLEEP 3

void ft_create_philosophe_network(t_petri_network *network, int *args)
{
    TEST_START;
    int n;

    n = args[0];
    ft_print_matrice_network(network);
    assert(network->p == 4 && network->t == 3);
    network->M_in = matrice_fusion(network->M_in,network->p,network->t, n);
    network->M_out =matrice_fusion(network->M_out,network->p,network->t, n);
    network->p *= n;
    network->t *= n;
    assert(network->p == 4 * n && network->t == 3 * n);
    ft_print_matrice_network(network);
    ft_print_arr_int(args, 4);
    
    TEST_SUCCES;
}