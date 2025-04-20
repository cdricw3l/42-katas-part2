/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/20 11:25:43 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include "../srcs/thread/thread.h"
#include "../srcs/initialisation/init_network.h"

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);
#define PSTR(msg) printf("\x1b[31m" "DEBBUG  str >>> " "%s\n", msg);
#define PPTR(msg) printf("\x1b[31m" "DEBBUG  de pointeur: >>> "  "%p\n" "\x1b[0m", msg);
#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("\033[0;33m" "\nInitiating function test: %s\n" "\x1b[0m", __func__);
#define TEST_SUCCES printf("\033[0;32m" "\nFunction: %s executed successfully.\n" "\x1b[0m", __func__);


int	*ft_init_and_check_argument(char **argv, int len);

#endif