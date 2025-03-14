/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/14 21:51:59 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H


#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "../petri_network/petri_network.h"

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

#define PETRI_P 4
#define PETRI_T (PETRI_P - 1)

typedef struct s_thread_data
{
    int ttd;
    int tte;
    int tts;
    
} s_thread_data;


typedef struct s_thread_managment_data
{
    int counter;
    
    pthread_mutex_t **forks;
    pthread_t **thread;
    s_thread_data data;

}   s_thread_managment_data;




 

void	ft_print_arr_int(int *arr, int len);
void	ft_print_arr_str(char **arr, int len);
long     ft_atoi_long(char *argv);
int     *ft_init_arr_arg(char **argv, int argc);
int     ft_isdigit(char c);
char    **ft_split(char *str, char c);
int     ft_memcpy(void *src, void *dst, int size);
int     ft_strlen(char *str);
void	ft_printm(int **arr, int row, int col);
int	    ft_strlcpy(char *dst, char *src, int dstsize);
void	*ft_clean_split(char **str, int idx);
int	    ft_get_split_len(char **split);

// int     ft_split_len(char **split);
// void    *ft_clean_split(char **str, int idx);

void ft_print_matrice(int **m, int p, int t);

#endif