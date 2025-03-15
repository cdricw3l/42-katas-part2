/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 13:49:40 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_unit.h"

void test_atoi(void)
{
    int ld;

    TEST_START;
    ld = ft_atoi("   +10");
    assert(ld == 10);
    ld = ft_atoi("   +1563 2321dwqdq0");
    assert(ld == 1563);
    ld = ft_atoi("   -325223 2321dwqdq0");
    assert(ld == -325223);
    ld = ft_atoi("   ++10");
    assert(ld == -1);
    ld = ft_atoi("2147483647");
    assert(ld == INT_MAX);
    ld = ft_atoi("9223372036854775807");
    assert(ld == -1);
    ld = ft_atoi(NULL);
    assert(ld == -1);
    ld = ft_atoi("   -10");
    assert(ld == -10);
    ld = ft_atoi("-2147483648");
    assert(ld == INT_MIN);
    ld = ft_atoi("           -21474836444");
    assert(ld == -1);
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

void test_memcpy(void)
{
    TEST_START;
    
    char str[] = "hello";
    char *cpy;

    assert(ft_strlen(str) == 5);
    cpy= malloc(sizeof(char) * (ft_strlen(str) + 1));
    if(!cpy)
        return;
    ft_memcpy(cpy, str, ft_strlen(str));
    cpy[ft_strlen(str)] = '\0';
    cpy = NULL;
    assert( ft_memcpy(cpy, str, ft_strlen(str)) == 0);
   
    free(cpy);

    int arr_int[] = {1, 2, 3, 4, 5};
    int *cpy_arr;
    
    cpy_arr= malloc(sizeof(int *) * 5);
    if(!cpy_arr)
        return;
    ft_memcpy(cpy_arr, arr_int, sizeof(int) * 5);
    int i;

    i = 0;
    while (i < 5)
    {
        assert(cpy_arr[i] == arr_int[i]);
        i++;
    }
    free(cpy_arr);
    TEST_SUCCES;
}



int tst_utils(void)
{
    test_atoi();
    test_isdigit();
    test_memcpy();
    return(1);
}

