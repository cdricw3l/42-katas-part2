/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_extend_network.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:56:42 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/22 23:54:48 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

/* int ft_add_arc(t_petri_network network, int t, int p)
{
    // add arc between from p to t W- matrice
    // add arc between from t to p W+ matrice

    
} */

void ft_join_matrice(int **old_m,int **new_m, int x, int y , int n)
{
    int i;
    int j;
    int off_set_col;
    int off_set_row;

    i = 0;
    j = 0;
    off_set_col = 0;
    off_set_row = 0;
    while (n > 0)
    {
        while(i < x)
        {
            j = 0;    
            while (j < y)
            {
                new_m[i + off_set_row][j + off_set_col] =  old_m[i][j];   //a decommenter ;
                j++;
            }
            i++;
        }
        i = 0;
        off_set_col += 3;
        off_set_row += 4;
        n--;
    }
}

int **ft_extend_matrice(int ***old_matrice,int x, int y, int n)
{
    int **new_matrice;
    int i;
    
    i = 0;
    new_matrice = malloc(sizeof(int *) * (x * n));
    if(!new_matrice)
        return(NULL);
    while (i <  (x * n))
    {
        new_matrice[i] = malloc(sizeof(int) * (y * n));
        if(!new_matrice[i])
        {
            ft_clean_matrice_memory(&new_matrice, i);
            return(NULL);
        }
        ft_memset(new_matrice[i],0,y * n * 4);
        i++;
    }
    ft_join_matrice(*old_matrice,new_matrice,x,y,n);
    free(*old_matrice);
    *old_matrice = NULL;
    return(new_matrice);
}

int *ft_extend_m0(int  **old, int y ,int n)
{
    int *new_arr;
    int i;
    int j;
    
    new_arr= malloc(sizeof(int) * (y * n));
    if(!new_arr)
        return(NULL);
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < y)
        {
            new_arr[j + (i * y)] = (*old)[j];
            j++;
        }
        i++;
    }
    free(*old);
    *old = NULL;
    return(new_arr);
}

t_petri_network *ft_extend_network(t_petri_network *network, int n)
{
    t_petri_network *new_network;

    new_network = malloc(sizeof(t_petri_network));
    if(!new_network || !ft_network_check(network, network->p))
		  return (NULL);
    new_network->M0 = ft_extend_m0(&network->M0 , network->p, n);
    assert(network->M0 == NULL);
    new_network->Mt = ft_extend_m0(&network->Mt,network->t ,n);
    new_network->Mp = ft_extend_m0(&network->Mp, network->p ,n);
    new_network->M_in = ft_extend_matrice(&network->M_in, network->p,network->t, n);
    new_network->M_out = ft_extend_matrice(&network->M_out, network->p,network->t, n);
    assert(network->M_out == NULL && network->M_in == NULL);
    new_network->p = network->p * n;
    new_network->t = network->t * n;
    new_network->n = n;
    ft_destroy_network(&network);
    return(new_network);
}


