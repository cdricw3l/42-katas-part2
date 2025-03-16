/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 12:06:25 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

void *ft_thread(void *p)
{
    int id;
    int j;

    j = 0;
    id = *(int *)(p);
    while (j < 100)
    {
        printf("je suis le thread: %d et j'en suis a la %d eme iteration\n", id, j);
        j++;
    }
    pthread_exit(&j);
}

int tst_thread_managment(void)
{

    TEST_START;
    
    pthread_t thread_1;
    pthread_t thread_2;
    int j;
    
    j = pthread_create(&thread_1, NULL,ft_thread, &j);
    pthread_create(&thread_2, NULL,ft_thread, &j);

    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    //pthread_create(&thread_1, NULL,ft_thread, &j);
    (void)thread_2;
    TEST_SUCCES;
    return(1);
}