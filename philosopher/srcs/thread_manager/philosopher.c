/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:23:43 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/22 12:10:28 by cw3l             ###   ########.fr       */
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
    network->M_out[network->p - 1][1] = 1;
    //plug the first to th last on W+;
    network->M_in[network->p - 1][network->t / N - 1] = 1;
    // --- > plug the other philosophe on W-
    i = P - 1;
    j = T + 1;
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

void    ft_get_transition_set(int id, int trs[3])
{
    int i;
    /* 
        p 0 = 0 1 2
        p 1 = 3 4 5
        p 2 = 6 7 8
    */
    i = id * T;
    trs[0] = i;
    trs[1] = i + 1;
    trs[2] = i + 2;
}

void *ft_clean_philosophe(t_philosophe **philosophes, int idx)
{
    int i;

    i = 0;
    while (i < idx)
    {
        free(philosophes[i]);
        philosophes[i] = NULL;
        i++;
    }
    free(philosophes);
    return(NULL);
}

t_philosophe **ft_create_philosophe(int n, pthread_mutex_t *fork, t_petri_network *network)
{
    t_philosophe **philosophes;
    int i;

    philosophes = malloc(sizeof(t_philosophe *) * n);
    if(!philosophes)
        return(NULL);
    i = 0;
    while (i < N)
    {
        philosophes[i] = malloc(sizeof(t_philosophe));
        if(!philosophes[i])
            return(ft_clean_philosophe(philosophes, i));
        philosophes[i]->id = i;
        philosophes[i]->fork = fork;
        philosophes[i]->network = network;
        philosophes[i]->transitions_set[0] = 1;
        ft_get_transition_set(i, philosophes[i]->transitions_set);
        i++;
    }
    return(philosophes);
}
