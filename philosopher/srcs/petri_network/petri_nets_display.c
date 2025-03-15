/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_nets_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:28:15 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 15:34:14 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "petri_network.h"

void	ft_print_petri_arr(int *arr, int len)
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
		if(mod == 2 && len > 2 && i > 0)
		{
			printf(" ");
			mod = -1;
		}
		mod++;
		i++;
	}
	printf("\n");
	
}

void ft_print_petri_matrice(int **m, int p, int t)
{
	int i;
	int mod;

	i = 0;
	mod = 0;
	while (i < p)
	{
		ft_print_petri_arr(m[i], t);
		if(mod == 3 && p > 3)
		{
			printf("\n");
			mod = -1;
		}
		mod++;
		i++;
	}	
}