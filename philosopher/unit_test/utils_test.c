/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 12:32:32 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_unit.h"

void test_atoi_long(void)
{
    int ld;

    TEST_START;
    ld = ft_atoi_long("10");
    assert(ld == 10);
    ld = ft_atoi_long("2147483647");
    assert(ld == INT_MAX);
    ld = ft_atoi_long("9223372036854775807");
    assert(ld == -1);
    ld = ft_atoi_long(NULL);
    assert(ld == -1);
    ld = ft_atoi_long("-10");
    assert(ld == -10);
    ld = ft_atoi_long("-2147483648");
    printf("%d\n", ld);
    assert(ld == INT_MIN);
    TEST_SUCCES;
}

void test_isdigit(void)
{
    char c;

    TEST_START;
    c = '0';
    assert(ft_isdigit(c) == 1);
    c = '5';
    assert(ft_isdigit(c) == 1);
    c = '9';
    assert(ft_isdigit(c) == 1);
    c = 'a';
    assert(ft_isdigit(c) == 0);
    c = 'w';
    assert(ft_isdigit(c) == 0);
    c = '-';
    assert(ft_isdigit(c) == 0);
    TEST_SUCCES;
}



int tst_utils(void)
{
    test_atoi_long();
    test_isdigit();
    return(1);
}

