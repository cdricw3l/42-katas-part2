// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   petri_network.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/07 15:43:15 by cbouhadr          #+#    #+#             */
// /*   Updated: 2025/03/14 21:45:40 by cw3l             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "ptri_network.h"
#include <assert.h>


static int  *ft_create_transitions(int t)
{
    int *transitions;
    int i;
    
    transitions = malloc(sizeof(int) * (t));
    if(!transitions)
        return(NULL);
    i = 0;
    while (i < t)
    {
        transitions[i] = 0;
        i++;
    }
    return(transitions);
}

static int  *ft_create_place(int p)
{
    int *place;
    int i;
    
    place = malloc(sizeof(int) * (p));
    if(!place)
        return(NULL);
    i = 0;
    while (i < p)
    {
        place[i] = 0;
        i++;
    }
    return(place);

}

int ft_network_check(t_petri_network *network, int p)
{
    int i;
    int count_p;

    i = 0;
    count_p = 0;
    if(!network || !network->M0 || !network->M_in || !network->M_out
        || !network->Mp || !network->Mt)
        return(0);
    while(i < p)
    {
        if(network->M_in[i] && network->M_out[i])
            count_p++;
        i++;
    }
    if(count_p != network->p)
        return(0);
    return(1);
}

t_petri_network *ft_create_petri_net(int pt[2], char *m0, char *m_in, char *m_out)
{
    t_petri_network *network;

    if(!m_in || !m_out)
        return(NULL);
    if(pt[0] < 1 && pt[1] < 1)
        return(NULL);
    network = malloc(sizeof(t_petri_network));
    if(!network)
        return(NULL);
    network->p = pt[0];
    network->t = pt[1];
    network->M0 =   *ft_str_to_matrice(m0, 1, network->p);
    network->Mp =   ft_create_place(network->p);
    network->Mt =   ft_create_transitions(network->t);
    network->M_in = ft_str_to_matrice(m_in,network->p,network->t);
    network->M_out = ft_str_to_matrice(m_out, network->p, network->t);
    assert(ft_network_check(network, pt[0]));
    if(!ft_network_check(network, pt[0]))
        return(ft_destroy_network(&network));
	DEBUGG;
    return(network);
}

// // int main(void)
// // {
// //     t_petri_network *network_1;
// //     int pt[2] = {4,3};
// //     char *m0 = "1 0 0 1";
// //     char *m_out = "1 0 0 0 1 0 0 0 3 0 1 0";
// //     char *m_int = "0 1 2 3 4 5 6 7 8 9 10 11";
    
// //     network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
// //     if(!network_1)
// //         return(1);
// //     printf("%d\n", network_1->p);
// //     ft_print_matrice(network_1->M_out, network_1->p,network_1->t, 1);
// //     printf("\n");
// //     matrice_fusion(network_1->M_in,network_1->p,network_1->t,4);
    
// //     return(0);
// // }
