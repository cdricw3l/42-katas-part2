/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 23:07:58 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

void test_atoi(void)
{
    long ld;

    TEST_START;

    // good value
    ld = ft_atoi("+10");
    assert(ld == 10);
    ld = ft_atoi("10");
    assert(ld == 10);
    ld = ft_atoi("        +10  ");
    assert(ld == 10);
    ld = ft_atoi("        -10  ");
    assert(ld == -10);
    ld = ft_atoi("10  ");
    assert(ld == 10);
    ld = ft_atoi("2147483647");
    assert(ld == INT_MAX);
    ld = ft_atoi("+2147483647");
    assert(ld == INT_MAX);
    ld = ft_atoi("-2147483648");
    assert(ld == INT_MIN);
    ld = ft_atoi("1");
    assert(ld == 1);
    ld = ft_atoi("0");
    assert(ld == 0);
    ld = ft_atoi("01");
    assert(ld == 1);ld = ft_atoi("-325223");
    assert(ld == -325223);


    //bad value
    
    ld = ft_atoi("2147483649");
    assert(ld == LONG_MIN);
    ld = ft_atoi("   +1563 2321dwqdq0");
    assert(ld == LONG_MIN);
    
    ld = ft_atoi(NULL);
    assert(ld == LONG_MIN);
    ld = ft_atoi("   ++10");
    assert(ld == LONG_MIN);
    ld = ft_atoi("2147483647");
    assert(ld == INT_MAX);
    ld = ft_atoi("9223372036854775807");
    assert(ld == LONG_MIN);
    ld = ft_atoi("-2147483649");
    assert(ld == LONG_MIN);
    ld = ft_atoi("           -21474836444");
    assert(ld == LONG_MIN);
    ld = ft_atoi("++10");
    assert(ld == LONG_MIN);
    ld = ft_atoi("+10  -1");
    assert(ld == LONG_MIN);
    ld = ft_atoi("aaa");
    assert(ld == LONG_MIN);
    ld = ft_atoi("");
    assert(ld == LONG_MIN);
    ld = ft_atoi("12 dwq   dwqdwqfewqfq fwqfwqfwq fqko22e12 fqdf qqqqq");
    assert(ld == LONG_MIN);
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

void test_ft_split(void)
{
    TEST_START;
    
    char *str = strdup("   *******voici*un*test*de*split    1************");
    char *str2 = strdup("hello*world");
    int split_len;
    int i = 0;
    
    char **split = ft_split(str,'*');
    assert(split);
    
    split_len = ft_get_split_len(NULL);
    assert(split_len == -1);
    split_len = ft_get_split_len(split);
    assert(split_len == 6);
    //test clean memory fonction free the first 3 element, send the split to the memoy cleaning fonction and check that return n ;
    int n = 3;
    
    while (i < split_len - n)
    {
        free(split[i]);
        split[i] = NULL;
        i++;
    }
    assert(ft_get_split_len(split) == 0);
    assert(ft_clean_split(&split,6) == 3);
    split = ft_split(str2, 32);
    split_len = ft_get_split_len(split);
    assert(split_len == 1);
    assert(ft_clean_split(&split,split_len) == split_len);
    // try to send still free split arr;
    assert(ft_clean_split(&split, 6) == 0);
    
    TEST_SUCCES;
}


int test_ft_str_to_matrice(void)
{
    TEST_START;
    
    char *m_out = "1 2 3 4 5 6 7 8 9 1 2 3";
    int **arr;
    int i;
    int j;
    int check;
    
    arr = ft_str_to_matrice(NULL, 4,3);
    assert(arr == NULL);
    
    arr = ft_str_to_matrice(m_out,4,3);
    assert(arr);
    ft_print_petri_matrice(arr,4,3, 1);
    assert(ft_clean_matrice_memory(&arr,4) == 5);
    assert(ft_clean_split(NULL,4) == 0);
    assert(ft_clean_matrice_memory(NULL,4) == 0);
    i = 0;
    j = 0;
    check = 1;
    arr = ft_str_to_matrice(m_out,3,4);
    while (i < 3)
    {
        while (j < 4)
        {
            assert(arr[i][j] == check);
            j++;
            check++;
        }
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    assert(!arr[0]);
    assert(ft_clean_matrice_memory(&arr,3) == 1);
    TEST_SUCCES;
    return(1);
}

int tst_utils(void)
{
    test_atoi();
    test_isdigit();
    test_memcpy();
    test_ft_split();
    test_ft_str_to_matrice();
    return(1);
}

