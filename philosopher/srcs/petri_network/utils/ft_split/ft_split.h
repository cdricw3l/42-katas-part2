/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:54:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 14:54:24 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_SPLIT_H
# define FT_SPLIT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../utils/utils.h"


char	**ft_split(char *str, char c);
int	    ft_get_split_len(char **split);
void	ft_split_print(char **split);
int	    ft_strlcpy(char *dst, char *src, int dstsize);
void	*ft_split_clean(char ***split);

# endif