/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:06:24 by ast               #+#    #+#             */
/*   Updated: 2025/04/18 13:49:28 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef INIT_NETWORK_H
#define INIT_NETWORK_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "../thread/thread.h"

t_network   *create_network(int *params);
void        *destroy_network(t_network **network);

t_philo     **init_philos(int *params, mutex_t **forks, mutex_t **pens);
void        *ft_destroy_philos(t_philo ***philos, int len);

mutex_t     **init_mutex(int n);
void        *ft_destroy_mutexs(mutex_t ***mutexs, int len);

#endif