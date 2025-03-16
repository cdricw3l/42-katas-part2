/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_destroy_network.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:42:01 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 03:06:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"
#include <assert.h>

static void *ft_destroy_M_in(t_petri_network **nets)
{
    int i;

    if((*nets)->M_in)
    {
        i = 0;
        while (i < (*nets)->p)
        {
            if((*nets)->M_in[i])
            {
                free((*nets)->M_in[i]);
                (*nets)->M_in[i] = NULL;
            }
            i++;
        }
        free((*nets)->M_in);
        (*nets)->M_in = NULL;
    }
    return(NULL);
}

static void *ft_destroy_M_out(t_petri_network **nets)
{
    int i;

    if((*nets)->M_out)
    {
        i = 0;
        while (i < (*nets)->p)
        {
            if((*nets)->M_out[i])
            {
                free((*nets)->M_out[i]);
                (*nets)->M_out[i] = NULL;
            }
            i++;
        }
        free((*nets)->M_out);
        (*nets)->M_out = NULL;
    }
    return (NULL);
}

void *ft_destroy_network(t_petri_network **network)
{
    
    if(*network)
    {
        ft_destroy_M_in(network);
        ft_destroy_M_out(network);
        free((*network)->Mp);
        free((*network)->Mt);
        free((*network)->M0);
        assert((*network)->M_in == NULL);
        assert((*network)->M_out == NULL);
        (*network)->Mp = NULL;
        (*network)->Mt = NULL;
        (*network)->M0 = NULL;
    }
    free(*network);
    *network = NULL;
    return(NULL);
}
