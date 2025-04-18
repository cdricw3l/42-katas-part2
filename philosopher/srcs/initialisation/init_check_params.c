/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:10:47 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 20:11:52 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	// else if (i == 4 && value != CYCLE)
	// 	return(0);
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
		value = ft_atoi(argv[i]);
		if(!ft_check_argument(value, i))
		{
			
			printf("Error with arguments\n");
			free(arr);
			return(NULL);
		}
		arr[i] = (int)value;
		i++;
	}
	if(len == 4)
		arr[5] == -1;
	return (arr);
}
