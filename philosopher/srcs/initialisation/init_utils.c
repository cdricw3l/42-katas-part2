/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:27:39 by ast               #+#    #+#             */
/*   Updated: 2025/04/22 23:22:29 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_network.h"

void *ft_destroy_timeboard(long long ***time_board, int len)
{
    int i;
    long long **time_b;
    
    i = 0;
    time_b = *time_board;
    while (i < len)
    {
        free(time_b[i]);
        time_b[i] = NULL;
        i++;
    }   
    free(*time_board);
    *time_board = NULL;
    return (NULL);
}

long long **get_time_board(int n)
{
    long long **time_board;
    int i;
    int j;

    if(n < 0)
        return(NULL);
    i = 0;
    time_board = malloc(sizeof(long long *) * n);
    if(!time_board)
        return (NULL);
    while (i < n)
    {
        time_board[i] = malloc(sizeof(long long) * n);
        if(!time_board)
            return(ft_destroy_timeboard(&time_board, i));
        j = 0;
        while (j < n)
        {
            time_board[i][j] = 0;
            j++;
        }
        i++;
    }
    return(time_board);
}



