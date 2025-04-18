/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/04/18 06:08:59 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../include/global.h"

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

	if(!argv)
		return(NULL);
	arr = malloc(sizeof(int) * len);
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
	return (arr);
}



int	main(int argc, char **argv)
{
	
	int *arr_args;
	t_network *network;
	
	if (argc < 5 || argc > 6)
		return(1);
	arr_args = ft_init_and_check_argument(&argv[1], argc - 1);
	if (!arr_args)
		return (1);
	network = create_network(arr_args);
	if(!network)
	{
		free(arr_args);
		arr_args = NULL;
		return(1);
	}

	return(0);
}


