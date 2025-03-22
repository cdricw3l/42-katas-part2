/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/22 00:49:00 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

#define TT_DIE 1
#define TT_EAT 2
#define TT_SPLEEP 3


int ft_plug_philosophe_together(t_petri_network *network)
{
    int i;
    int j;
    
    //plug the first to th last on W-;
    network->M_out[network->p - 1][0] = 1;
    //plug the first to th last on W+;
    network->M_in[network->p - 1][network->t / N - 1] = 1;
    // --- > plug the other philosophe on W-
    i = P - 1;
    j = T;
    while (i < (N * P) - 1)            
    {
        network->M_out[i][j] = 1;
        i += P;
        j += T;
    }
    i = P - 1;
    j = T + 2;
    // --- > plug the other philosophe on W+
    while (i < (N * P) - 1)            
    {
        network->M_in[i][j] = 1;
        i += P;
        j += T;
    }
   /*  printf("matrice pre: \n\n");
    ft_print_petri_matrice(network->M_out,network->p,network->t,1); 
    printf("matrice post: \n\n");
    ft_print_petri_matrice(network->M_in,network->p,network->t,1);
    ft_print_petri_arr(network->M0,network->p, 0); */
    return(1);
}