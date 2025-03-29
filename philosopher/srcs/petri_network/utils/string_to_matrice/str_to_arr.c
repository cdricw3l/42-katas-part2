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

int *ft_str_to_arr_int(char *str)
{
    char **split;
    int *arr_int;
    int i;

    if(!str)
        return(NULL);
    split = ft_split(str, 32);
    if(split)
    {
        i = 0;
        arr_int = malloc(sizeof(int) * ft_get_split_len(split));
        if(!arr_int)
            return(NULL);
        while (split[i])
        {
            arr_int[i] = ft_atoi(split[i]);
            i++;
        }
    }
    ft_split_clean(&split);
    return(arr_int);
}