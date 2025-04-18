/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:45 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/18 13:01:04 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int tst_ft_init_arr_arg(void)
{
    
    int  *arr_args;
    
    char *philosopher = strdup("+3");
    char *time_to_spleep = strdup("1000");
    char *time_to_eat = strdup("1000");
    char *time_to_die = strdup("1000");
    char *cycle = strdup("100");

    char **argv= malloc(sizeof(char *) * 5);
    assert(argv);
    
    argv[0] = philosopher;
    argv[1] = time_to_spleep;
    argv[2] = time_to_eat;
    argv[3] = time_to_die;
    argv[4] = cycle;
    
    arr_args = ft_init_and_check_argument(argv,5);
    assert(arr_args);
    assert(arr_args[0] == 3 && arr_args[1] == 1000 &&
        arr_args[2] == 1000 && arr_args[3] == 1000 && arr_args[4] == 100);
    
    free(arr_args);
    free(time_to_spleep);
    
    time_to_spleep = strdup("-1000");
    argv[1] = time_to_spleep;
    arr_args = ft_init_and_check_argument(argv,5);
    assert(!arr_args);
    
    free(arr_args);
    free(time_to_spleep);
    
    time_to_spleep = strdup("");
    argv[1] = time_to_spleep;
    arr_args = ft_init_and_check_argument(argv,5);
    assert(!arr_args);
    
    free(arr_args);
    free(time_to_die);
    free(time_to_eat);
    free(cycle);
    free(time_to_spleep);
    
    free(argv[0]);
    free(argv);
    return(1);
}