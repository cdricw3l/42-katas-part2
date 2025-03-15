/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 19:40:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <limits.h>

int ft_isdigit(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

long ft_atoi(char *argv)
{
	int i;
	long result;
	int is_neg;

	result = LONG_MIN;
	i = 0;
	if (!argv)
		return (LONG_MIN);
	is_neg = 0;
	while (argv[i])
	{
		while (argv[i] == 32)
			i++;
		if (argv[i] == '-' || argv[i] == '+')
		{
			if (argv[i] == '-')
				is_neg = 1;
			i++;
		}
		while(ft_isdigit(argv[i]))
		{
			result = ((result * 10) + (argv[i] - '0'));
			if ((result > INT_MAX && !is_neg) || (is_neg && result * -1 < INT_MIN))
				return (LONG_MIN);
			i++;
		}
		while (argv[i])
		{
			if(!ft_isdigit(argv[i]) && argv[i] != '\0' && argv[i] != 32)
				return(LONG_MIN);
			i++;
		}
	}
	if(is_neg)
		return (result * -1);
	return (result);
}



int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_memcpy(void *dst, void *src, int size)
{
	int i;
	unsigned char *s;
	unsigned char *d;

	if (!src || !dst)
		return (0);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (i);
}
