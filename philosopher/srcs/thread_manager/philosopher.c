/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/21 19:49:51 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

#define TT_DIE 1
#define TT_EAT 2
#define TT_SPLEEP 3


int ft_plug_philosophe_together(t_petri_network *network)
{
    assert(network->p == 12);
    assert(network->t == 9);

    ft_print_petri_matrice(network->M_out,network->p,network->t,1);
    ft_print_petri_matrice(network->M_in,network->p,network->t,1);
    printf("voici le int %d\n", network->M_out[network->p - 1][0]);
    //plug the first to th last on W-;
    network->M_out[network->p - 1][0]= 1;
    //plug the first to th last on W+;
    network->M_in[network->p - 1][network->t / N - 1]= 1;
    ft_print_petri_matrice(network->M_out,network->p,network->t,1);
    ft_print_petri_matrice(network->M_in,network->p,network->t,1);
    
    return(1);
}



// void ft_create_philosophe_network(t_petri_network *network, int *args)
// {
//     TEST_START;
//     int n;

//     n = args[0];
//     ft_print_matrice_network(network);
//     assert(network->p == 4 && network->t == 3);
//     network->M_in = matrice_fusion(network->M_in,network->p,network->t, n);
//     network->M_out =matrice_fusion(network->M_out,network->p,network->t, n);
//     network->p *= n;
//     network->t *= n;
//     assert(network->p == 4 * n && network->t == 3 * n);
//     ft_print_matrice_network(network);
//     ft_print_arr_int(args, 4);
    
//     TEST_SUCCES;
// }