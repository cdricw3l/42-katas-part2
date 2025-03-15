/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:23:04 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 11:57:12 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UNIT_H
#define TEST_UNIT_H

#include "../srcs/petri_network/petri_network.h"
#include "../srcs/utils/utils/utils.h"
#include "../include/global.h"

#include <assert.h>

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);


int test_unit_ft_create_petri_net(void);
int tst_ft_init_arr_arg(void);
int tst_utils(void);

#endif