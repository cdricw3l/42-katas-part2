/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:10:47 by ast               #+#    #+#             */
/*   Updated: 2025/05/27 20:41:01 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_network.h"

static int	ft_check_argument(long value, int i)
{
	if (value == LONG_MIN)
		return (0);
	else if (i == 0 && (value < 0 || value > MAX_P))
		return (0);
	else if (i == 1 && value < 0)
		return (0);
	else if (i == 2 && value < 0)
		return (0);
	else if (i == 3 && value < 0)
		return (0);
	else
		return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*ft_init_and_check_argument(char **argv, int len)
{
	int		i;
	int		*arr;
	long	value;

	arr = malloc(sizeof(int) * 5);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		value = init_atoi(argv[i]);
		if (value < 0 || !ft_check_argument(value, i))
		{
			write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
			free(arr);
			return (NULL);
		}
		arr[i] = (int)value;
		i++;
	}
	if (len == 4)
		arr[4] = -1;
	return (arr);
}
