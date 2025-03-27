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

int ft_clean_mat(int ***mat, int r)
{
    int **m;
    int i;

    m = *mat;
    i = 0;
    while (m[i])
    {
        free(m[i]);
        m[i] = NULL;
        i++;
    }
    free(*mat);
    return(r);
}

void ft_print_result(int **mat, int n)
{
    int  i;
    int j;

    j = 0;

    while (j < n)
    {
        i = 0;
        while (i < n)
        {
            if(mat[i][j] == 1)
            {
                printf("%d ", j);
            }
            i++;
        }
        j++;
    }
    printf("\n");
}
void ft_print_mat(int **mat, int n)
{
    TEST_START;

    int i;
    int j;

    i = 0;
    j = 0;
    while (i < n)
    {
        j = 0;
        while(j < n)
        {
            printf("%d ", mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    TEST_SUCCES;
}

int ft_check_diag(int **mat, int row, int col, int end)
{
    int i;
    int j;

    i = row;
    j = col;

    while (i >=  0 && j - 1 >= 0)
    {
        if(mat[i - 1][j - 1] == 1)
            return(0);
        i--;
        j--;
    }
    i = row;
    i = col;
    while (i >= 0 && j + 1 < end)
    {
        if(mat[i - 1][j + 1] == 1)
            return(0);
        i--;
        j++;
    }
    return(1);
}

int ft_is_safe(int **mat, int row, int col, int end)
{
    int i;
    int j;

    i = 0;
    j = 0;
    assert(end ==4);
    while (j < end)
    {
        if(mat[row][j] == 1)
            return(0);
        if(mat[i][col] == 1)
            return(0);
        j++;
        i++;
    }
    if(!ft_check_diag( mat, row,  col,  end))
        return(0);
 
    return(1);
}


void ft_n_queen(int **mat ,int row, int  n)
{

    int i;

    i = 0;
    if(!mat || n < 2)
        return;
    if(row == n)
    {
        ft_print_mat(mat,n);
        return;
    }
    while (i < n)
    {
        if(ft_is_safe(mat, row, i, n))
        {
            mat[row][i] = 1;
            ft_n_queen(mat, row + 1,n);
            mat[row][i] = 0;
        }
        i++;
    }
    
}


// int main(int argc, char **argv)
// {
//     int **mat;
//     int i;
//     int j;

//     if(argc != 2)
//         return(1);
//     mat = malloc(sizeof(int *) * atoi(argv[1]));
//     if(!mat)
//         return(0);
//     i = 0;
//     while (i < atoi(argv[1]))
//     {
//         mat[i] = malloc(sizeof(int) * atoi(argv[1]));
//         if(!mat)
//             return(ft_clean_mat(&mat, 1));
//         j = 0;
//         while (j < atoi(argv[1]))
//         {
//             mat[i][j] = 0;
//             j++;
//         }
//         i++;
//     }
    
//     // mat[0][0] = 1;
//     // mat[3][0] = 1;
//     // ft_print_mat(mat, atoi(argv[1]));
//     // // ft_print_mat(mat, atoi(argv[1]));
//     // // assert(ft_is_safe(mat, 3,0, 4) == 0);
//     // assert(ft_is_safe(mat, 3,3, 4) == 0);
//     // mat[2][3] = 1;
//     // ft_print_mat(mat, atoi(argv[1]));
//     // assert(ft_check_diag(mat, 2,3, 4) == 1);
//     // mat[1][2] = 1;
//     ft_print_mat(mat, atoi(argv[1]));
//     // assert(ft_check_diag(mat, 1,2, 4) == 1);
//     // assert(ft_check_diag(mat, 2,3, 4) == 0);

//     ft_n_queen(mat, 0, atoi(argv[1]));
    
// }