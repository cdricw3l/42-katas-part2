// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   voyageur.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/12 21:29:06 by cw3l              #+#    #+#             */
// /*   Updated: 2025/03/13 08:55:26 by cw3l             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <string.h>


// la meilleur solution pour parser les ville. ft_strchr + ft_strncpy

char *ft_strchr(char *str, char c)
{
    while (*str)
    {
        if(*str == c)
            return(str);
        str++;
    }
        
    return(str);
}

int ft_strncpy(char *dest, char *src, int size)
{
    int i;

    i = 0;
    if(!dest || !src)
        return(-1);
    while(src[i] && i < size)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\n';
    return(i);
}




void ft_print_matrice(char **arr, int n)
{
    int i;
    int j;

    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            printf("%d ", arr[i][j]);
            j++;
        }
        
        i++;
    }
    printf("\n");
}
int ft_isdigit(char c)
{
    if(c < 48 || c > 57)
        return(0);
    return(1);
}


double ft_atof(char *str)
{
    printf("voivi la str %s\n", str);
    int i;
    int dot;
    int isneg;
    double  res;
    i = 0;
    while (str[i] == 32)
        i++;
    if(str[i] == '-')
    {
        isneg = 1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if(str[i] == '.')
    {
        dot = 10;
        while (ft_isdigit(str[i]))
        {
            res = res + ((str[i] - '0') / dot);
            dot *=10;
            i++;
        }
        if(isneg)
            return(res * -1);
        return(res);
        
    }
    return(-1);
    
}

int main(void)
{
    char *city[] ={"0.00 , -10.50","-10.00 , -11.50", "2.00 , -13.50", "4.00 , -14.50"};
    //double t = ft_atof(city[0]);

                                                                            
    int len;
    char *s = ft_strchr(city[0], ',');

    len = s - city[0];
    char tmp[len];

    ft_strncpy(tmp, city[1], len);

    printf("voici le premier %f\n", ft_atof(tmp));
    // int c = 0;
    // while (c < 4)
    // {
        
    // }
    
    return(0);
}