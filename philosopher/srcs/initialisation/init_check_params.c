/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:10:47 by ast               #+#    #+#             */
/*   Updated: 2025/05/09 14:03:55 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_network.h"

static int	ft_check_argument(long value, int i)
{
	if(value == LONG_MIN)
		return(0);
	else if (i == 0 && (value < MIN_P || value > MAX_P))
		return(0);
	else if (i == 1 && value < MIN_TTD)
		return(0);
	else if (i == 2 && value < MIN_TTE)
		return(0);
	else if (i == 3 && value < MIN_TTS)
		return(0);
	else
		return(1);
}

int	*ft_init_and_check_argument(char **argv, int len)
{
	long value;
	int *arr;
	int i;

	arr = malloc(sizeof(int) * 5);
	if(!arr)
		return(NULL);
	i = 0;
	while (i < len)
	{
		value = init_atoi(argv[i]);
		if(!ft_check_argument(value, i))
		{
			
			printf("\x1b[31m" "Error with params\n" "\x1b[0m");
			free(arr);
			return(NULL);
		}
		arr[i] = (int)value;
		i++;
	}
	if(len == 4)
		arr[4] = -1;
	return (arr);
}
