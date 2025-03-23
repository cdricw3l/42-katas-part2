/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_destroy_network.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:42:01 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/22 23:26:57 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

void *ft_destroy_matrice(int ***matrice, int p)
{
    int i;
    if(*matrice)
    {
        i = 0;
        while (i < p)
        {
            if((*matrice)[i])
            {
                free((*matrice)[i]);
                (*matrice)[i] = NULL;
            }
            i++;
        }
        free(*matrice);
        *matrice = NULL;
    }
    return(*matrice);
}

void *ft_destroy_network(t_petri_network **network)
{
    
    if(*network)
    {
        assert(*network);
        ft_destroy_matrice(&(*network)->M_in, (*network)->p);
        assert((*network)->M_in == NULL);
        ft_destroy_matrice(&(*network)->M_out, (*network)->p);
        assert((*network)->M_out == NULL);
        if((*network)->Mp)
            free((*network)->Mp);
        if((*network)->Mt)
            free((*network)->Mt);
        if((*network)->M0)
            free((*network)->M0);
        (*network)->Mp = NULL;
        (*network)->Mt = NULL;
        (*network)->M0 = NULL;
        assert((*network)->Mp == NULL);
        assert((*network)->Mt == NULL);
        assert((*network)->M0 == NULL);
    }
    free(*network);
   *network = NULL;
    return(NULL);
}

// void *ft_destroy_network(t_petri_network **network)
// {
//     if(*network)
//     {
//         ft_destroy_matrice(&(*network)->M_in, (*network)->p);
//         ft_destroy_matrice(&(*network)->M_out, (*network)->p);
//         if((*network)->Mp)
//         {
//             free((*network)->Mp);
//             (*network)->Mp = NULL;
//         }
//         if((*network)->Mt)
//         {
//             free((*network)->Mt);
//             (*network)->Mt = NULL;
//         }
//         if((*network)->M0)
//         {
//             free((*network)->M0);
//             (*network)->M0 = NULL;
//         }
//     }
//     free(*network);
//    *network = NULL;
//     return(NULL);
// }
