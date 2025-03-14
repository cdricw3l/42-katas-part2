/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:43:15 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/14 21:45:40 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "petri_network.h"

void *ft_clean_petri_network_mem(t_petri_network *network)
{
    int i;
    
    if(network->M_in)
    {
        i = 0;
        while (i < network->p)
        {
            if(network->M_in[i])
                free(network->M_in[i]);
            i++;
        }
    }
    if(network->M_out)
    {
        i = 0;
        while (i < network->p)
        {
            if(network->M_out[i])
                free(network->M_out[i]);
            i++;
        }
    }
    free(network->M0);
    free(network->T);
    free(network);
    return(NULL);
}



static int  *ft_create_transitions(int T)
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


static t_petri_network *ft_init_state_network(int pt[2], char *m0)
{
    t_petri_network *network;
    
    if(pt[0] < 1 && pt[1] < 1)
        return(NULL);
    network = malloc(sizeof(t_petri_network));
    if(!network)
        return(NULL);
    network->M0 = *ft_str_to_matrice(m0, 1, pt[0]);
    if(!network->M0)
    {
        free(network);
        return(NULL);
    }
    network->p = pt[0];
    network->t = pt[1];
    network->T =  ft_create_transitions(network->t);
    if(!network->T)
    {
        free(network->M0);
        free(network);
        return(0);
    }
    return(network);    
}


t_petri_network *ft_create_petri_net(int pt[2], char *m0, char *m_in, char *m_out)
{
    t_petri_network *network;

    network = ft_init_state_network(pt, m0);
    if(!network)
        return(NULL);
    if(!m_in || !m_out)
        return(NULL);
    network->M_out = ft_str_to_matrice(m_out, pt[0], pt[1]);
    if(!network->M_out)
    {
        free(network->M0);
        free(network->T);
        free(network);
        return(NULL);
    }
    network->M_in = ft_str_to_matrice(m_in, pt[0], pt[1]);
    if(!network->M_in)
    {
        free(network->M0);
        free(network->T);
        ft_clean_matrice_mem(network->M_out, network->p);
        free(network);
        return(NULL);
    }
    return(network);
}

// int main(void)
// {
//     t_petri_network *network_1;
//     int pt[2] = {4,3};
//     char *m0 = "1 0 0 1";
//     char *m_out = "1 0 0 0 1 0 0 0 3 0 1 0";
//     char *m_int = "0 1 2 3 4 5 6 7 8 9 10 11";
    
//     network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
//     if(!network_1)
//         return(1);
//     printf("%d\n", network_1->p);
//     ft_print_matrice(network_1->M_out, network_1->p,network_1->t, 1);
//     printf("\n");
//     matrice_fusion(network_1->M_in,network_1->p,network_1->t,4);
    
//     return(0);
// }
