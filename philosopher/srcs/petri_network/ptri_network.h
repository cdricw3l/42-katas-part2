/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:05 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/16 03:40:58 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETRI_NETWORK_H 
#define PETRI_NETWORK_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
 #include <stdio.h>
#include "ft_string_to_matrice/str_to_matrice.h"


#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");

typedef struct s_petri_network
{
    int     p;              //n place
    int     t;              //n transition
    int     *Mp;            //arr p or actual state
    int     *Mt;            //arr t
    int     *M0;            //initial state
    int     **M_in;         // output tocken
    int     **M_out;        // intput tocken

} t_petri_network;

typedef struct s_extend_data
{
    int Np;             // number of place extension;
    int Nt;             // size of transition extension
    int Pi;             // Place index in matrice
    int Ti;             // Transition index in matrice
    
} t_extend_data;


int                 **ft_create_matrice(int p, int t, int n);
void	            *ft_memset(void *b, int c, size_t len);
void	            ft_print_arr_int(int *arr, int len);
int                 *ft_create_state(int P, int *M_0);

t_petri_network     *ft_create_petri_net(int pt[2], char *m0, char *m_in, char *m_out);
void                ft_print_petri_matrice(int **m, int p, int t, int mode);
void                ft_print_petri_arr(int *arr, int len, int mode);
void                ft_print_network(t_petri_network *network);
int                 ft_network_check(t_petri_network *network, int p);
void                ft_join_matrice(int **old_m,int **new_m, int p, int t , int n);
int                 *ft_create_arr_int(int n);
void                *ft_destroy_network(t_petri_network **network);

#endif