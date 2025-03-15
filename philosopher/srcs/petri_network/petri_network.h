/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:05 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 14:06:14 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETRI_NETWORK_H 
#define PETRI_NETWORK_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
 #include <stdio.h>
#include "../utils/ft_string_to_matrice/str_to_matrice.h"

typedef struct s_petri_network
{
    int     p;              //n place
    int     t;              //n transition
    int     *Mp;            //arr p
    int     *Mt;            //arr t
    int     *M0;            //initial state
    int     **M_in;         // output tocken
    int     **M_out;        // intput tocken

} t_petri_network;

t_petri_network     *ft_create_petri_net(int pt[2], char *m0, char *m_in, char *m_out);
void                *ft_clean_petri_network_mem(t_petri_network *network);
void                ft_join_matrice(int **old_m,int **new_m, int p, int t , int n);
int                 **ft_create_matrice(int p, int t, int n);
int                 **matrice_fusion(int **m, int p, int t, int n);
void	            *ft_memset(void *b, int c, size_t len);
void                ft_print_matrice_network(t_petri_network *network);
void	            ft_print_arr_int(int *arr, int len);
int                 *ft_create_state(int P, int *M_0);
void                ft_print_matrice(int **m, int p, int t);

#endif