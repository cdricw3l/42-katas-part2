/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:27:39 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 21:59:56 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "init_network.h"

long long *get_meal_board(int n)
{
    long long *meal_board;
    int i;

    if(n < 0)
        return(NULL);
    i = 0;
    meal_board = malloc(sizeof(long long) * n);
    if(!meal_board)
        return (NULL);
    while (i < n)
    {
        meal_board[i] = 1;
        i++;
    }
    return(meal_board);
}



