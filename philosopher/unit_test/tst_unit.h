/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_unit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:23:04 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/19 10:05:04 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TST_UNIT_H
#define TST_UNIT_H

#include "../include/global.h"

#include <assert.h>
 #include <string.h>


int tst_ft_init_arr_arg(void);
int tst_init_fork_and_pen(void);
int tst_init_philos(void);
int tst_init_network(void);
int tst_run_thread_monitor(void);
int tst_run_thread_philo(void);
int tst_run_thread_simulation(void);

#endif