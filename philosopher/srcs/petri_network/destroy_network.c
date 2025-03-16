/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_network.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:42:01 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 02:20:11 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");

static void *ft_destroy_M_in(int **M_in, int p)
{
    int i;

    if(M_in)
    {
        i = 0;
        while (i < p)
        {
            if(M_in[i])
            {
                PPTR(M_in[i]);
                free(M_in[i]);
                M_in[i] = NULL;
            }
            i++;
        }
        free(M_in);
        M_in = NULL;
    }
    return(NULL);
}

static void *ft_destroy_M_out(int **M_out, int p)
{
    int i;

    if(M_out)
    {
        i = 0;
        while (i < p)
        {
            if(M_out[i])
            {
                free(M_out[i]);
                M_out[i] = NULL;
            }
            i++;
        }
        free(M_out);
        M_out = NULL;
    }
    return (NULL);
}

void *ft_destroy_network(t_petri_network **nets)
{
    int p;
    t_petri_network *network;
    
    network = *nets;
    if(network)
    {
        
        p = network->p;
        ft_destroy_M_in(network->M_in, p);
        ft_destroy_M_out(network->M_out, p);
        free(network->Mp);
        free(network->Mt);
        free(network->M0);
        network->Mp = NULL;
        network->Mt = NULL;
        network->M0 = NULL;
    }
    free(*nets);
    *nets = NULL;
    return(NULL);
}
