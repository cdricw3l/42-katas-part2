/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/23 21:53:40 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
#define GLOBAL_H

#include "../srcs/petri_network/network/ptri_network.h"
#include "../srcs/petri_network/utils/utils/utils.h"
#include "../srcs/thread_manager/thrd_manager.h"

#define PLACE 4
#define TRANSITION 3

#define MIN_P    1      /*minimum number of philosophe*/
#define MIN_TTD  60   /*minimum time to die*/
#define MIN_TTE  60   /*minimum time to eat*/
#define MIN_TTS  60   /*minimum time to spleep*/
#define CYCLE    100    /* number of cycle */

#define P   4
#define T   3
#define N   1

int	*ft_init_and_check_argument(char **argv, int len);

#endif