/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 08:11:07 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_isdigit(char c)
{
	if(c < 48 || c > 57)
		return (0);
	return(1);
}

long	ft_atoi_long(char *argv)
{
	long result;
	int i;
	int is_neg;

	result = 0;
	i = 0;
	if(!argv)
		return(-1);
	is_neg = 0;
	if(argv[0] == '-')
	{
		is_neg = 1;
		i++;
	}
	while (argv[i])
	{

		if(!ft_isdigit(argv[i]))
			return (-1);
		result = ((result * 10) + (argv[i] - '0'));
		i++;
	}
	if(is_neg)
		return(result * -1);
	return(result);
}


void	ft_print_arr_str(char **arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%s\n", arr[i++]);
	
}



int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

int ft_memcpy(void *src, void *dst, int size)
{
	int i;
	unsigned char *s;
	unsigned char *d;

	if(!src || !dst)
		return(0);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (i  < size)
	{
		d[i] = s[i];
		i++;
	}
	return(i);
	
}



