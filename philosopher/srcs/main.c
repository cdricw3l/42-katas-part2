/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 19:49:23 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "petri_network/petri_network.h"
#include "utils/ft_split/ft_split.h"
#include "utils/ft_string_to_matrice/str_to_matrice.h"

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
		if(value == LONG_MIN)
		{
			free(arr);
			return(NULL);
		}
		arr[i] = (int)value;
		i++;
	}
	return (arr);
}

// int	main(int argc, char **argv)
// {
//     t_petri_network *network_1;
    
// 	int	*arr_args;
//     int pt[2] = {4,3};
//     char *m0 = "1 0 0 1";
//     char *m_out = "1 0 0 0 1 0 0 0 3 0 1 0";
//     char *m_int = "1 0 0 0 1 0 0 0 3 0 1 0";
	
// 	if (argc < 5 || argc > 6)
// 		return(1);
        
// 	arr_args = ft_init_arr_arg(&argv[1], argc - 1);
// 	if (!arr_args)
// 		return (1);
        
//     network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
//     if(!network_1)
//         return(1);
//     //ft_create_philosophe_network(network_1, arr_args);
//     printf("\n");

// 	free(arr_args);
// 	return(0);
// }
