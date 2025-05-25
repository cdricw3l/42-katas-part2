/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/05/25 13:05:35 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/initialisation/init_network.h"


int	main(int argc, char **argv)
{
	
	int				*arr_args;
	t_network		*network;

	
	if (argc < 5 || argc > 6 || !argv || !*argv)
	{
		write(STDERR_FILENO, "invalid params\n", ft_strlen("invalid params\n"));
		return(2);
	}
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
	printf("run simulation: N= %d, TDD = %d", arr_args[0], arr_args[1]);
	printf(" TTE= %d, TTS = %d, Cycle %d\n", arr_args[2], arr_args[3], arr_args[4]);
	run_simulation(&network);
	return(0);
}
