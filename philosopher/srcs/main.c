/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/04/20 09:11:16 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/global.h"

int	main(int argc, char **argv)
{
	
	int				*arr_args;
	t_network		*network;
	
	if (argc < 5 || argc > 6 || !argv || !*argv)
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
	run_simulation(&network);
	return(0);
}
