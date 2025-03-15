// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Combination_Sum.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/22 19:53:10 by cw3l              #+#    #+#             */
// /*   Updated: 2025/03/06 17:33:38 by cbouhadr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

// void ft_print_arr(int *arr, int n)
// {
//     int i;

//     i = 0;

//     while(i < n)
//     {
//         printf("%d ", arr[i]);
//         i++;
//     }

//     printf("\n");
// }

// int *ft_push(int **arr, int len,int n)
// {
//     int *new_arr;
//     int i;
//     int j;

//     new_arr = malloc(sizeof(int) * (len + 1));
//     if(!new_arr)
//         return(NULL);
//     i = 0;
//     new_arr[i++] = n;
//     if(!(*arr))
//         return(new_arr);
//     j = 0;
//     while (j < len)
//         new_arr[i++] = (*arr)[j++];
//     free(*arr);
//     return(new_arr);
// }
// int *ft_pop(int **arr, int len)
// {
//     int *new_arr;
//     int i;
//     int j;

//     new_arr = malloc(sizeof(int) * (len));
//     if(!new_arr)
//         return(NULL);
//     i = 1;
//     if(!(*arr))
//         return(NULL);
//     j = 0;
//     while (j < len)
//         new_arr[j++] = (*arr)[i++];
//     free(*arr);
//     return(new_arr);
// }

void combi(int *arr,int target, int start, int end)
{
    int i;

    if(target < 0)
        return ;
    if( target == 0)
    {
        printf("resultat");
    }
    i = start;
    while (i < end)
    {
        combi(arr, target - arr[i], i, end);
        i++;
    }
    
}


target - arr[i],

// void conbine(int *arr,int *result,int *len, int arr_len, int target, int idx)
// {
//     if(target == 0)
//     {
//         printf("combinaison trouve\n");
//     }
//     if(target < 0 || idx >= arr_len)
//         return ;
//     result = ft_push(&result,len, arr[idx]);
//     *len++;
//     ft_print_arr(arr, len);
//     conbine(arr, result,&((*len) + 1), arr_len,target - arr[idx],idx);

//     ft_pop(&result, *len);
//     conbine(arr, result,(*len) + 1, arr_len,target,idx + 1);
// }



void print_int_arr(int *arr, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
}

void print_matrice(int **m, int x, int y)
{
    int i;

    i = 0;
    while (i < x)
    {
        print_int_arr(m[i], y);
        i++;
    } 
}

void *ft_clean_mat(int **arr, int idx)
{
    int i;

    i = 0;
    while (i < idx)
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
    return(NULL);
}

int **get_matrice(int x,int y)
{
    int **mat;
    int i;
    int j;

    mat = malloc(sizeof(int *) * x);
    if(!mat)
        return(NULL);
    i = 0;
    while (i < x)
    {
        j = 0;
        mat[i] = malloc(sizeof(int) * y);
        if(!mat[i])
            return(ft_clean_mat(mat, i));
        while (j < y)
            mat[i][j++] = 0;
        i++;
    }
    return(mat);
}


int main(int argc, char **argv)
{
    int n;
    
    if(argc != 2)
        return(1);


    n = atoi(argv[1]);
    printf("%d\n", n);

    int **mat;

    mat = get_matrice(n,n);
    if(!mat)
        return(1);
    print_matrice(mat,n,n);
    free(mat);
    return(0);
}