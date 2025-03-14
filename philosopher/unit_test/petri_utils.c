/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:43:15 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/14 00:48:30 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

void *ft_clean_petri_network_mem(t_petri_network *network)
{
    int i;
    
    if(network->M_in)
    {
        i = 0;
        while (i < PETRI_P)
        {
            if(network->M_in[i])
                free(network->M_in[i]);
            i++;
        }
    }
    if(network->M_out)
    {
        i = 0;
        while (i < PETRI_P)
        {
            if(network->M_out[i])
                free(network->M_out[i]);
            i++;
        }
    }
    free(network->P);
    free(network->T);
    free(network);
    return(NULL);
}

void    *ft_clean_matrice_mem(int **M, int idx)
{
    int i;

    i = 0;
    while(i < idx)
    {
        free(M[i]);
        i++;
    }
    free(M);
    return(NULL);
}

int *ft_create_place(int P, int *M_0)
{
    int *places;
    int i;

    places = malloc(sizeof(int) * P);
    if(!places)
        return(NULL);
    i = 0;
    while (i < P)
    {
        places[i] = M_0[i];
        i++;
    }
    return(places);
}

int  *ft_create_transitions(int T)
{
    int *transitions;
    int i;
    
    transitions = malloc(sizeof(int) * (T));
    if(!transitions)
        return(NULL);
    i = 0;
    while (i < T)
    {
        transitions[i] = 0;
        i++;
    }
    return(transitions);

}

int **ft_copy_matrice(int **M_in, int P, int T)
{
    int i;
    int r;
    int **M;

    if(!M_in)
        return(NULL);
    M = malloc(sizeof(int *) * P);
    if(!M)
        return(NULL);
    i = 0;
    while (i < P)
    {
        M[i] = malloc(sizeof(int) * T);
        if(!M[i])
            return(ft_clean_matrice_mem(M, i));
        r = ft_memcpy(M_in[i], M[i], sizeof(int) * T);
        if(r / sizeof(r) != T)
        {
            perror("Err ft_copy_matrice");
            return(ft_clean_matrice_mem(M, i));
        }
        i++;
    }
    return(M);
}

t_petri_network *ft_create_network(int *PT, int *M_0, int **M_in, int **M_out)
{
    t_petri_network *network;
    
    if(PT[0] < 1)
        return(NULL);
    network = malloc(sizeof(t_petri_network));
    if(!network)
        return(NULL);
    network->p = ft_create_place(PT[0], M_0);
    if(!network->P)
    {
        free(network);
        return(NULL);
    }
    network->T =  ft_create_transitions(PT[1]);
    if(!network->T)
    {
        free(network->P);
        free(network);
        return(NULL);
    }
    network->M_in = ft_copy_matrice(M_in, PT[0], PT[1]);
    network->M_out = ft_copy_matrice(M_out, PT[0], PT[1]);
    if(!network->M_in || !network->M_out)
        return(ft_clean_petri_network_mem(network));
    return(network);    
}

