/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_unit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:23:04 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/21 10:22:23 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TST_UNIT_H
#define TST_UNIT_H

#include "../include/global.h"
#include "../srcs/initialisation/init_network.h"
#include "../srcs/thread/thread.h"

int tst_ft_init_arr_arg(void);
int tst_init_fork_and_pen(void);
int tst_init_philos(void);
int tst_init_network(void);
int tst_run_thread_monitor(void);
int tst_run_thread_philo(void);
int tst_run_thread_simulation(void);
int tst_tempo(void);
int tst_timestamp(void);

#endif