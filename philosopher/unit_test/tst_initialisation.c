/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:45 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 18:29:46 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_ft_init_arr_arg(void)
{
    TEST_START
    
    int  *arr_args;
    
    char *philosopher = strdup("+5");
    char *time_to_spleep = strdup("1000");
    char *time_to_eat = strdup("1000");
    char *time_to_die = strdup("1000");
    char *cycle = strdup("10");

    char **argv= malloc(sizeof(char *) * 5);
    assert(argv);
    
    argv[0] = philosopher;
    argv[1] = time_to_spleep;
    argv[2] = time_to_eat;
    argv[3] = time_to_die;
    argv[4] = cycle;
    
    arr_args = ft_init_and_check_argument(argv,5);
    assert(arr_args && arr_args[0] == 5 && arr_args[1] == 1000 &&
        arr_args[2] == 1000 && arr_args[3] == 1000 && arr_args[4] == 10);
    
    TEST_SUCCES
    return(1);
}