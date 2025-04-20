/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:27:39 by ast               #+#    #+#             */
/*   Updated: 2025/04/20 09:05:17 by ast              ###   ########.fr       */
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



int get_fork_number(t_philo *philo, int fork_number)
{
    int id;
    int n_philo;

    id = philo->pametres[ID];
    n_philo = philo->pametres[P];
    if(id == 0)
    {
        if(fork_number == 1)
            return(id);
        if(fork_number == 2)
            return(n_philo - 1);
        
    }
    else if(id > 0)
    {
        if(fork_number == 1)
            return(id - 1); 
        if(fork_number == 2)
            return(id);  
    }
    else
        return(-1);
}
