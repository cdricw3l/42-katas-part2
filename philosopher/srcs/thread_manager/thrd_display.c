/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:43:12 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 20:22:54 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thrd_manager.h"

void    ft_print_transitions_set(t_philosophe *philosophe)
{
    int j;
    
    j = 0;
    while (j < philosophe->network->t /  philosophe->network->n)
    {
        printf("%d ", philosophe->transitions_set[j]);
        j++;
    }
    printf("\t");
}
void    ft_print_places_set(t_philosophe *philosophe)
{
    int j;
    
    j = 0;
    while (j < philosophe->network->p /  philosophe->network->n)
    {
        printf("%d ", philosophe->places_set[j]);
        j++;
    }
    printf("\n");
}

void ft_print_philosophe_state(t_philosophe *philosophe)
{
    int j;
    
    j = 0;
    while (j < philosophe->network->p /  philosophe->network->n)
    {
        
        printf("%d ", philosophe->network->M0[philosophe->places_set[j]]);
        j++;
    }
    printf("\n");
}

void ft_display_philophes(t_philosophe **philosophes)
{
    int i;

    i = 0;

    while (i < philosophes[0]->network->n)
    {
        printf("\n[Philosophe id]: %d\n", philosophes[i]->id);
        if(philosophes[i]->state == ALIVE)
            printf("[ State ]: Vivant\n");
        else if(philosophes[i]->state == DEAD)
            printf("[ State ]: Mort\n");
        printf("[Transitions set] : ");
        ft_print_transitions_set(philosophes[i]);
        printf("\n[ M0 ]: ");
        ft_print_philosophe_state(philosophes[i]);
        printf("[Tempo] : ttd %d, tte %d, tts %d\n", philosophes[i]->tempo.ttd,
            philosophes[i]->tempo.tte, philosophes[i]->tempo.tts);
        i++;
    }
    printf("\n");
}
