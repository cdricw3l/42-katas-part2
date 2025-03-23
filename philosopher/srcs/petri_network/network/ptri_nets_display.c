/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_nets_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:28:15 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 19:32:39 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

void	ft_print_petri_arr(int *arr, int len, int mode)
{
	int i;
	int mod;

	i = 0;
	mod = 0;
	while(i < len)
	{
		if(arr[i] == 0)
			printf("%d ", arr[i]);
		else
			printf("\x1B[32m" "%d " "\x1B[0m", arr[i]);
		if(mod == 2 && len > 2 && i > 0 && mode == 1)
		{
			printf(" ");
			mod = -1;
		}
		mod++;
		i++;
	}
	printf("\n");
	
}

void ft_print_petri_matrice(int **m, int p, int t, int mode)
{
	int i;
	int mod;

	i = 0;
	mod = 0;
	while (i < p)
	{
		if(m[i])
		{
			ft_print_petri_arr(m[i], t, mode);
			if(mod == 3 && p > 3 && mode == 1)
			{
				printf("\n");
				mod = -1;
			}
			mod++;
		}
		i++;
	}	
}
void ft_print_network(t_petri_network *network)
{
	if(!network || !ft_network_check(network, network->p))
		return ;
	
    printf("\n[ Network size: %d ]\n\n", network->n);
    printf("\n[ P: %d ]\n\n", network->p);
    ft_print_petri_arr(network->M0, network->p,0);
    printf("\n[ T: %d ]\n\n", network->t);
    ft_print_petri_arr(network->Mt, network->t,0);
    printf("\n[ matrice M 0 ]\n\n");
    ft_print_petri_arr(network->M0, network->p,0);
    printf("\n[ matrice M_out ]\n\n");
    ft_print_petri_matrice(network->M_out, network->p,network->t,1);
    printf("\n[ matrice M_in ]\n\n");
    ft_print_petri_matrice(network->M_in, network->p, network->t,1);
    printf("\n");
}
