/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:54:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/14 08:56:11 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_SPLIT.H
# define FT_SPLIT.H

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

void	*ft_clean_split(char **str, int idx);
char	**ft_split(char *str, char c);


# endif