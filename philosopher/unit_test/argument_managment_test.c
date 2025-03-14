/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_managment_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:00:50 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/20 10:50:54 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_isdigit(char c)
{
	if(c < 48 || c > 57)
		return (0);
	return(1);
}

int	ft_atoi_long(char *argv)
{
	long result;
	int i;

	result = 0;
	i = 0;
	if(!argv)
		return(-1);
	if(!ft_isdigit(argv[i]))
		return (-1);
	while (argv[i])
	{
		result = ((result * 10) + (argv[i] - '0'));
		i++;
	}
	return(result);
}

int	*ft_init_arr_arg(char **argv, int len)
{
	int *arr;
	int i;

	arr = malloc(sizeof(int) * 6);
	if(!arr)
		return(NULL);
	i = 0;
	while (i < len)
    {
        arr[i] = ft_atoi_long(argv[i]);
		if(i < 5)
        	assert(arr[i] != -1);
        i++;
    }
	return (arr);
}