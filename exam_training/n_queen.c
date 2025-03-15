/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:10 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/12 21:14:56 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N
#define N 10
#endif

#define BUFFER_SIZE 10

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
//#include "get_next_line/get/get_next_line.h"

#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

void *ft_clean_memory(char **arr, int idx)
{
    int i;

    i = 0;
    if(!arr)
        return(NULL);
    while (i < idx)
    {
        if(arr[i])
            free(arr[i]);
        i++;
    }
    free(arr);
    return(NULL);
    
}

char **ft_result_arr(int n)
{
    char **res;
    int i;

    TEST_START;
    if(n <= 0)
        return(NULL);
    res =  malloc(sizeof(char *) * 500);
    if(!res)
        return(NULL);
    i = 0;
    while (i < 500)
    {
        res[i] = malloc(sizeof(char) * (n + 1));
        if(!res[i])
            return(ft_clean_memory(res, i));
        i++;
    }
    TEST_SUCCES;
    return(res);
}



// void ft_print_arr(int arr[N][N], int n)
// {
//     int i;
//     int j;

//     i = 0;
//     while(i < n)
//     {
//         j = 0;
//         while(j < n)
//         {
//             printf("%d ", arr[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
//     printf("\n");
// }

int ft_is_diag_safe(int mat[N][N], int n ,int row, int col)
{
    int i;
    int j;

    i = row;
    j = col;
    while (i - 1 >= 0 && j - 1 >= 0)
    {
        if(mat[i - 1][j - 1] == 1)
            return (0);
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i - 1 >= 0 && j + 1 < n)
    {
        if(mat[i - 1][j + 1] == 1)
            return (0);
        i--;
        j++;
    }
    return(1);
}

int issafe(int mat[N][N], int n ,int row, int col)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < n)
    {
        if(mat[row][i] == 1)
            return(0);
        if(mat[j][col] == 1)
            return(0);
        i++;
        j++;
    }
    if(!ft_is_diag_safe(mat,n, row, col))
        return(0);
    return(1);
}

void ft_print_result(int mat[N][N], char **result)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            if(mat[j][i] == 1)
                printf(" %d ", j + 1);
            j++;            
        }
        i++;
    }
    printf("\n");
}

// void ft_nqueen(int row, int mat[N][N], int n, int *counter, char **result)
// {
//     int i;

//     i = 0;
//     if(row == n)
//     {
//         ft_print_result(mat, result, *counter);
//         (*counter)++;
//         return ;
//     }
//     while (i < n)
//     {
//         if(issafe(mat, n,row, i))
//         {
//             mat[row][i] = 1;
//             ft_nqueen(row + 1, mat, n, counter, result);
//             mat[row][i] = 0;
//         }
//         i++;
//     }
// }


void ft_nqueen(int row, int mat[N][N], int n, int *counter, char **result)
{
    int i;

    i = 0;
    if(row == n)
    {
        ft_print_result(mat,result);
    }
    else
    {
        while (i < n)
        {
            if(issafe(mat,n,row, i))
            {
                mat[row][i] = 1;
                ft_nqueen(row+1, mat, n, counter,result);
                mat[row][i] = 0;
            }
            i++;
        }
    }
}

// int main() {
    
//     int n;
//     int counter;
//     int mat[N][N] ={0};
//     char **result;
//     int i;

//     i = 0;
//     n = N;
//     counter = 0;
//     result = ft_result_arr(n);
//     if(!result)
//         return(-1);
//     assert(mat[0][0] == 0);
//     ft_nqueen(0, mat, N, &counter, result);
//     printf("voici le nombre de solution %d\n", counter);
//     ft_clean_memory(result, 500);
//     return(0);

// }
