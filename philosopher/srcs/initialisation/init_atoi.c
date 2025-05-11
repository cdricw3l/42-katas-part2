/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:18:47 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/05/11 07:05:56 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	init_atoi(const char *str)
{
	size_t	i;
	size_t	is_neg;
	long	result;

	i = 0;
	is_neg = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			is_neg = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		if(result > INT_MAX)
			return(-1);
		i++;
	}
	if(i == 0 || (!ft_isdigit(str[i]) && str[i] != '\0'))
		return(-1);
	if (is_neg)
		return (-result);
	return (result);
}
