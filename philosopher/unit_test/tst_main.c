/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:22:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/05/17 18:49:13 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int	main(void)
{   
    //assert(tst_ft_init_arr_arg() == 1);
    //assert(tst_init_fork_and_pen() == 1);
    // assert(tst_init_network() == 1);
    //assert(tst_timestamp() == 1);
    //assert(tst_init_philos() == 1);
    //assert(tst_init_network() == 1);
    
    // assert(tst_run_thread_monitor() == 1);
    //assert(tst_run_thread_philo() == 1);
    //assert(tst_run_thread_simulation() == 1);
    assert(tst_utils());
    //assert(tst_tempo() == 1);
    TEST_SUCCES;
	return(0);
}