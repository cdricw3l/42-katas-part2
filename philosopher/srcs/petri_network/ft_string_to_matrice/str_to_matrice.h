/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrice.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:05 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 20:20:15 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRT_TO_MATRICE_H
#define SRT_TO_MATRICE_H

#include <unistd.h>
#include <limits.h>
#include "../../utils/ft_split/ft_split.h"
#include "../../utils/utils/utils.h"

int     **ft_str_to_matrice(char *str, int x, int y);
int    ft_clean_matrice_memory(int ***memory, int idx);

#endif