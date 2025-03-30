/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/25 07:55:59 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

void *ft_hello(void *p)
{
    (void)p;
    printf("hello world \n");
    return(NULL);
}

int ft_c(pthread_t thread[], int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        assert(pthread_create(&thread[i], NULL, ft_hello,NULL) == 0);
        printf("lauch thread %d\n", i);
        i++;
    }
    return(1);
}
int ft_joint(pthread_t thread[], int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        assert(!pthread_join(thread[i], NULL));
        printf("joint thread %d\n", i);
        i++;
    }
    return(1);
}

int ft_tst_thead_easy(void)
{

    int i;
    i = 0;

    while (i < N  - 1)
    {
        if(i % 2 == 0)
            printf("voici i paire %d\n",i);
        i++;
    }
    i = 0;
    printf("\n");
    while (i < N  - 1)
    {
        if((i % 3 == 0 && i != 0 )|| i == 1)
            printf("voici i impaire %d\n",i);
        i++;
    }

    pthread_t mutex[2];

    ft_c(mutex, 2);
    ft_joint(mutex, 2);
    return(1);
}