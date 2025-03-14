/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/08 08:54:49 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print_arr_int(int *arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%d ", arr[i++]);
	printf("\n");
	
}
void	ft_print_arr_str(char **arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%s ", arr[i++]);
	printf("\n");
	
}

void	ft_printm(int **arr, int row, int col)
{
	int i;
	int j;

	i = 0;
	if(!arr)
	{
		perror("Arg NULL");
		return ;
	}
	while(i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%d ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

