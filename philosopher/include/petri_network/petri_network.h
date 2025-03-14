/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:05 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/14 09:08:08 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETRI_NETWORK_H
#define PETRI_NETWORK_H

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include "philosophers.h"
#include "str_to_matrice.h"

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);


typedef struct s_petri_network
{
    int     p;  //n place
    int     t;  //n transition
    int     *T; //arr t
    //int     *P; arr p a implementer;
    int     *M0;
    int     **M_in;        
    int     **M_out;

} t_petri_network;

int                 **ft_copy_matrice(int **M_in, int P, int T);
void                *ft_clean_matrice_mem(int **M, int idx);
t_petri_network     *ft_init_network(int pt[2], char *m0);
void                ft_print_matrice_network(t_petri_network *network);
int                 **matrice_fusion(int **m, int p, int t, int n);
void                ft_create_philosophe_network(t_petri_network *network, int *args);




t_petri_network     *ft_create_petri_net(int pt[2], char *m0, char *m_in, char *m_out);
void                *ft_clean_petri_network_mem(t_petri_network *network);
void                ft_join_matrice(int **old_m,int **new_m, int p, int t , int n);
int                 **ft_create_matrice(int p, int t, int n);
int                 **matrice_fusion(int **m, int p, int t, int n);
void	            *ft_memset(void *b, int c, size_t len);
void                ft_print_matrice_network(t_petri_network *network);
void	            ft_print_arr_int(int *arr, int len);

#endif