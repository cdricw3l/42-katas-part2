/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:27:39 by ast               #+#    #+#             */
/*   Updated: 2025/04/30 12:59:00 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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


long long *get_time_board(int n)
{
    long long *time_board;
    int i;

    i = 0;
    time_board = malloc(sizeof(long long *) * n);
    if(!time_board)
        return(NULL);
    i = 0;
    while (i < n)
    {
        time_board[i] = 0;
        i++;
    }
    return(time_board);
}

long long **get_time_multi_board(int n, int len)
{
    long long **time_board;
    int i;

    if(n < 0)
        return(NULL);
    i = 0;
    time_board = malloc(sizeof(long long *) * n);
    if(!time_board)
        return (NULL);
    while (i < n)
    {
        time_board[i] = get_time_board(len);
        if(!time_board)
            return(ft_destroy_timeboard(&time_board, i));
        i++;
    }
    return(time_board);
}



