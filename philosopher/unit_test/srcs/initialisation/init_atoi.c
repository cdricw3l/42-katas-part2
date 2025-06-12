/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:18:47 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/05/18 20:47:38 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static size_t	skip_space(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

size_t	process_atoi(char *str, long *result, size_t *i)
{
	while (ft_isdigit(str[(*i)]))
	{
		*result = (*result) * 10 + str[(*i)] - 48;
		if ((*result) > INT_MAX)
			return (-1);
		(*i)++;
	}
	return (*i);
}

int	init_atoi(const char *str)
{
	size_t	i;
	size_t	is_neg;
	long	result;

	is_neg = 0;
	result = 0;
	if (!str)
		return (-1);
	i = skip_space((char *)str);
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			is_neg = 1;
		i++;
	}
	process_atoi((char *)str, &result, &i);
	if (i == 0 || (!ft_isdigit(str[i]) && str[i] != '\0'))
		return (-1);
	if (is_neg)
		return (-result);
	return (result);
}
