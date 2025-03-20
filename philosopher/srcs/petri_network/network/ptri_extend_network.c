/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_extend_network.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:56:42 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/20 23:17:11 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

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

int **ft_extend_matrice(int **old_matrice,int x, int y, int n)
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
    ft_join_matrice(old_matrice,new_matrice,x,y,n);
    return(new_matrice);
}

int *ft_extend_m0(int  *old, int y ,int n)
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
            new_arr[j + (i * y)] = old[j];
            j++;
        }
        i++;
    }
    return(new_arr);
}

t_petri_network *ft_extend_network(t_petri_network *network, int n)
{
    t_petri_network *new_matrice;

    new_matrice = NULL;
    if(!network || !ft_network_check(network, network->p))
		  return (NULL);
    network->M0 = ft_extend_m0(network->M0 , network->p,n);
    network->Mt = ft_extend_m0(network->Mp,network->t ,n);
    network->Mp = ft_extend_m0(network->Mt, network->p ,n);
    network->M_in = ft_extend_matrice(network->M_in, network->p,network->t, n);
    network->M_out = ft_extend_matrice(network->M_out, network->p,network->t, n);
    network->p = network->p * n;
    network->t = network->t * n;
    ft_print_network(network);
    return(new_matrice);
}


