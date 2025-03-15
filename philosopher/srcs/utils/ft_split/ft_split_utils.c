/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:05:27 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 14:36:28 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	ft_get_split_len(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (-1);
	while (split[i])
		i++;
	return (i);
}

void ft_print_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		printf("%s\n", arr[i++]);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (!dstsize && src)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}