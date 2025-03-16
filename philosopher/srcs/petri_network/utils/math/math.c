/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:52:22 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 23:29:52 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../network/ptri_network.h"

void    *ft_clean_reachability_matrix(int ***memory, int idx)
{
    int i;
	int **M;
	
	if(memory == NULL)
		return(NULL);
	M = *memory;
    i = 0;
    while(i < idx)
    {
		if(M[i])
		{
			free(M[i]);
			M[i] = NULL;
		}
        i++;
    }
    free(*memory);
	*memory=NULL;
    return(NULL);
}

// return arr W_in - W_out
int **ft_get_reachability_matrix(t_petri_network *network)
{
    int **matrix;
    int i;
    int j;
    
    if(!ft_network_check(network, network->p))  
        return(NULL);
    matrix = malloc(sizeof(int *) * network->p);
    if(!matrix)
        return(NULL);
    i = 0;
    while (i < network->p)
    {
        j = 0;
        matrix[i] = malloc(sizeof(int) * network->t);
        if(!matrix)
            return(ft_clean_reachability_matrix(&matrix,i));
        while (j < network->t)
        {
            matrix[i][j] = network->M_in[i][j] - network->M_out[i][j];
            j++;
        }
        i++;
    }
    return(matrix);
}


