/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/23 19:40:55 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/global.h"

static int	ft_check_argument(long value, int i)
{
	if(value == LONG_MIN)
		return(0);
	else if (i == 0 && value < MIN_P)
		return(0);
	else if (i == 1 && value < MIN_TTD)
		return(0);
	else if (i == 2 && value < MIN_TTE)
		return(0);
	else if (i == 3 && value < MIN_TTS)
		return(0);
	else if (i == 4 && value != CYCLE)
		return(0);
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
			
			printf("Errror\n");
			free(arr);
			return(NULL);
		}
		arr[i] = (int)value;
		i++;
	}
	return (arr);
}

int ft_run_network(int *args)
{
	int	ptn[3];
	t_petri_network *network;
	t_philosophe **philosophes;
	pthread_mutex_t **fork;
	
	ptn[0] = 4;
	ptn[1] = 3;
	ptn[2] = args[0];
	network = ft_extend_network(ft_create_petri_net(ptn,
		"1 0 0 1", "1 0 0 0 1 0 0 0 3 0 1 0",
		"0 0 1 1 0 0 0 3 0 0 0 1"), ptn[2]);
	ft_plug_philosophe_together(network);
	fork = ft_create_arr_mutext(network->n);
	philosophes = ft_create_philosophe(network->n,fork, network);
	ft_display_philophes(philosophes);
	return(1);
}

int	main(int argc, char **argv)
{
	
	int	*arr_args;
	
	if (argc < 5 || argc > 6)
		return(1);
	arr_args = ft_init_and_check_argument(&argv[1], argc - 1);
	if (!arr_args)
		return (1);
	ft_run_network(arr_args);
	free(arr_args);
	return(0);
}
