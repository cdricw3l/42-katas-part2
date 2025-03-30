/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_init_philosophes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:30:55 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 07:58:11 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

void ft_plug_philosophe_together(t_petri_network *network)
{
    int i;
    int j;
    
    if(!network || network->n == 1)
    {
        printf("return\n");
        return ;
    }
    //plug the first to th last on W-;
    network->M_out[network->p - 1][1] = 1;
    //plug the first to th last on W+;
    network->M_in[network->p - 1][network->t / network->n - 1] = 1;
    // --- > plug the other philosophe on W-
    i = network->p / network->n - 1;
    j = network->t / network->n + 1;
    while (i < (network->n * (network->p / network->n)) - 1)            
    {
        network->M_out[i][j] = 1;
        i += network->p / network->n;
        j += network->t / network->n;
    }
    i = network->p / network->n - 1;
    j = network->t / network->n + 2;
    // --- > plug the other philosophe on W+
    while (i < (network->n * (network->p / network->n)) - 1)            
    {
        network->M_in[i][j] = 1;
        i += network->p / network->n;
        j += network->t / network->n;
    }
    DEBUGG;
    printf("matrice pre: \n\n");
    ft_print_petri_matrice(network->M_out,network->p,network->t,1); 
    printf("matrice post: \n\n");
    ft_print_petri_matrice(network->M_in,network->p,network->t,1);
    ft_print_petri_arr(network->M0,network->p, 0);

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
void    ft_get_place_set(int id, int place[4])
{
    int i;
    /* 
        p 0 = 0 1 2 3
        p 1 = 4 5 6 7
        p 2 = 8 9 10 11
    */
    i = id * P;
    place[0] = i;
    place[1] = i + 1;
    place[2] = i + 2;
    place[3] = i + 3;
}

int *ft_get_state_arr(int n)
{
    int i;
    int *arr;

    arr = malloc(sizeof(int) * n);
    if(!arr)
        return(NULL);
    i = 0;
    while (i < n)
    {
        arr[i] = ALIVE;
        i++;
    }
    return(arr);
}

t_philosophe **ft_create_philosophe(int n, pthread_mutex_t **fork, t_petri_network *network, t_tempo_data tempo)
{
    t_philosophe **philosophes;
    int *state;
    int i;

    philosophes = malloc(sizeof(t_philosophe *) * n);
    if(!philosophes)
        return(NULL);
    state =  ft_get_state_arr(n);
    i = 0;
    while (i < network->n)
    {
        philosophes[i] = malloc(sizeof(t_philosophe));
        if(!philosophes[i])
            return(ft_kill_philosophes_and_network(&philosophes, &network, &fork,i));
        philosophes[i]->id = i;
        philosophes[i]->fork = fork;
        philosophes[i]->network = network;
        philosophes[i]->tempo = tempo;
        philosophes[i]->state = state;
        ft_get_transition_set(i, philosophes[i]->transitions_set);
        ft_get_place_set(i ,philosophes[i]->places_set);
        i++;
    }
    return(philosophes);
}
