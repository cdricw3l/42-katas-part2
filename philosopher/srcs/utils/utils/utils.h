/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:56:23 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 16:32:17 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


long	ft_atoi(char *argv);
void	ft_print_arr_str(char **arr, int len);
int     ft_strlen(char *str);
int     ft_isdigit(char c);
int     ft_strlcpy(char *dst, char *src, int dstsize);
int     ft_memcpy(void *src, void *dst, int size);

#endif