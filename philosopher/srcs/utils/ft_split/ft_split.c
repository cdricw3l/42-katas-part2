/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:51:55 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 16:13:28 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	ft_clean_split(char ***split, int idx)
{
	int	i;
	int count;
	char **str;

	i = 0;
	count = 0;
	if (!split)
		return (count);
	str = *split;
	while (i < idx)
	{
		if (str && str[i])
		{
			free(str[i]);
			str[i] = NULL;
			count++;
		}
		i++;
	}
	free(*split);
	*split = NULL;
	return (count);
}

static int	count_word(char *str, char c)
{
	int	i;
	int	word_count;
	int	is_word;

	i = 0;
	word_count = 0;
	is_word = 0;
	while (str[i] && i < ft_strlen(str) - 1)
	{
		if(str[i] == c)
		{
			is_word = 0;
			i++;

		}
		if (str[i] != c)
		{
			if (is_word == 0)
				word_count++;
			is_word = 1;
			i++;
		}
	}
	return (word_count);
}

static int	ft_get_word_size(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_process_split(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	word_size;

	i = 0;
	j = 0;
	while (str[i])
	{
		if(str[i] == c)
			i++;
		else
		{
			word_size = ft_get_word_size(&str[i], c);
			split[j] = malloc(sizeof(char) * (word_size + 1));
			/* if(j == 3)
			{
				free(split[j]);			error simulation for memory check.
				split[j] = NULL;
			} */
			if (!split[j] || word_size == -1)
			{
				ft_clean_split(&split, j);
				return (NULL);
			}
			ft_strlcpy(split[j], &str[i], word_size + 1);
			i += word_size;
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char *str, char c)
{
	int		word_count;
	char	**split;

	if(!str)
		return(NULL);
	word_count = count_word(str, c);
	if (word_count == 0)
		return (NULL);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	if (!ft_process_split(split, str, c))
		return (NULL);
	return (split);
}
