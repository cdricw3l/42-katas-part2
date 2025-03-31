/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/25 07:25:26 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

t_tempo_data ft_get_tempo_data(int **args, int argc)
{
	t_tempo_data tempo;
	tempo.ttd = (*args)[1];
	tempo.tte = (*args)[2];
	tempo.tts = (*args)[3];
	if(argc == 5)
		tempo.cycle = (*args)[4];
	free(*args);
	*args = NULL;
	return(tempo);
}

t_philosophe **ft_create_network(int **args, int argc)
{
	int	ptn[3];
	t_petri_network *network;
	t_philosophe **philosophes;
	pthread_mutex_t **fork;
	t_tempo_data tempo;
	
	ptn[0] = 4;
	ptn[1] = 3;
	ptn[2] = (*args)[0];
	network = ft_extend_network(ft_create_petri_net(ptn,
		"1 0 0 1", "0 0 1 1 0 0 0 3 0 0 0 1",
		"1 0 0 0 1 0 0 0 3 0 1 0"), ptn[2]);
	ft_plug_philosophe_together(network);
	fork = ft_create_arr_mutext(network->n + 1);
	tempo = ft_get_tempo_data(args, argc);
	//assert(*args == NULL &&tempo.ttd == 800 && tempo.tte == 200 && tempo.tts == 200);	
	philosophes = ft_create_philosophe(network->n,fork, network, tempo);
	//ft_display_philophes(philosophes);
	return(philosophes);
}

int	main(int argc, char **argv)
{
	
	int				*arr_args;
	t_philosophe	**philosophes;
	
	if (argc < 5 || argc > 6)
		return(1);
	arr_args = ft_init_and_check_argument(&argv[1], argc - 1);
	if (!arr_args)
		return (1);
	philosophes = ft_create_network(&arr_args, argc - 1);
	if(!philosophes)
		printf("Erreur creation des philosophes");
	if(arr_args)
		free(arr_args);
	else
	{
		if(!run_simulation(philosophes, philosophes[0]->network->n))
		{
			ft_kill_philosophes_and_network(&philosophes,&philosophes[0]->network,&philosophes[0]->fork, philosophes[0]->network->n);
			return(0);
		}
		ft_kill_philosophes_and_network(&philosophes,&philosophes[0]->network,&philosophes[0]->fork, philosophes[0]->network->n);
	}
	return(0);
}


