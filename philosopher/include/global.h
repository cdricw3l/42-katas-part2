/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/18 20:11:34 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "../srcs/thread/thread.h"
#include "../srcs/initialisation/init_network.h"



int	*ft_init_and_check_argument(char **argv, int len);

#endif