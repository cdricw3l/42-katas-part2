/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:34:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 16:39:47 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_to_matrice.h"

int    ft_clean_matrice_memory(int ***memory, int idx)
{
    int i;
	int **M;
	int count;
	
	if(memory == NULL)
		return(0);
	M = *memory;
    i = 0;
	count = 0;
    while(i < idx)
    {
		if(M[i])
		{
			free(M[i]);
			M[i] = NULL;
			count++;
		}
        i++;
    }

    free(*memory);
	*memory=NULL;
	count++;
    return(count);
}

static int	ft_is_valide_split(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != '-' && split[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_process_matrice(int **M, char **split, int x, int y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < x)
	{
		M[i] = malloc(sizeof(int) * y);
		if (!M[i])
			return (ft_clean_matrice_memory(&M, i));
		j = 0;
		while (j < y)
		{
			if (ft_atoi(split[k]) == LONG_MIN)
				return (ft_clean_matrice_memory(&M, i));
			M[i][j] = ft_atoi(split[k]);
			k++;
			j++;
		}
		i++;
	}
	M[i] = NULL;
	return (0);
}

int	**ft_str_to_matrice(char *str, int x, int y)
{
	char	**split;
	int		**m;
	
	if (!str || x <= 0 || y <= 0)
		return (NULL);
	split = ft_split(str, 32);
	if (!split || !ft_is_valide_split(split))
		return (NULL);
	if (ft_get_split_len(split) != (x * y))  //error matrice arg
	{
		ft_clean_split(&split, ft_get_split_len(split));
		return (NULL);
	}	
	m = malloc(sizeof(int *) * (x + 1));
	if (!m)
		return (NULL);
	if (ft_process_matrice(m, split, x, y))
		return (NULL);
	return (m);
}

