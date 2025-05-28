/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 06:57:49 by cw3l              #+#    #+#             */
/*   Updated: 2025/05/28 07:08:42 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *routine_1(void *arg)
{
    int i;

    i = 0;
    (void)arg;
    while (i < 10)
    {
        printf("thred 1 counter : %d\n", i);
        i++;
    }
    return(NULL);
}

void *routine_2(void *arg)
{
    int i;
    (void)arg;
    i = 0;
    while (i < 10)
    {
        printf("thred 1 counter : %d\n", i);
        i++;
    }
    return(NULL);
}


int main(void)
{

    pthread_t t1;
    pthread_t t2;

    
    // params : thrad,  
    if(pthread_create(&t1,NULL,routine_1,NULL) || pthread_create(&t2,NULL,routine_1,NULL))
    {
        printf("Erreur dans le lancement des thread\n");
    }
    if(pthread_join(t1,NULL))
        printf("Erreur dans la jonction des thread\n");
    return(0);
}