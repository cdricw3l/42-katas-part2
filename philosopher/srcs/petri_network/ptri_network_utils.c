/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_network_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:50:09 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 01:25:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptri_network.h"

int **ft_create_matrice(int p, int t, int n)
{
    int **new_matrice;
    int i;
    int j;

    new_matrice = malloc(sizeof(int *) * (p * n));
    if(!new_matrice)
        return(NULL);
    i = 0;
    while (i < p * n)
    {
        new_matrice[i] = malloc(sizeof(int) * (t * n));
        if(!new_matrice[i])
        {
            ft_clean_matrice_memory(&new_matrice, i);
            return(NULL);
        }
        j = 0;
        while (j < t*n)
            new_matrice[i][j++] = 0;
        i++;
    }
    return(new_matrice);
}

void ft_join_matrice(int **old_m,int **new_m, int x, int y , int n)
{
    int i;
    int j;
    int off_set_col;
    int off_set_row;

    i = 0;
    j = 0;
    off_set_col = 0;
    off_set_row = 0;
    while (n > 0)
    {
        while(i < x)
        {
            j = 0;    
            while (j < y)
            {
                new_m[i + off_set_row][j + off_set_col] =  old_m[i][j];   //a decommenter ;
                j++;
            }
            i++;
        }
        i = 0;
        off_set_col += 3;
        off_set_row += 4;
        n--;
    }
}

int *ft_create_arr_int(int n)
{
    int *arr_int;
    int i;

    if(n < 1)
        return(NULL);
    arr_int = malloc(sizeof(int) * n);
    if(!arr_int)
        return(0);
    i = 0;
    while (i < n)
        arr_int[i++] = 0;
    return(arr_int);
}



// int **ft_copy_matrice(int **M_in, int P, int T)
// {
//     int i;
//     int r;
//     int **M;

//     M = malloc(sizeof(int *) * P);
//     if(!M)
//         return(NULL);
//     i = 0;
//     while (i < P)
//     {
//         M[i] = malloc(sizeof(int) * T);
//         if(!M[i])
//             return(ft_clean_matrice_memory(M, i));
//         r = ft_memcpy(M_in[i], M[i], sizeof(int) * T);
//         if(r / sizeof(r) != T)
//         {
//             perror("Err ft_copy_matrice");
//             return(ft_clean_matrice_memory(M, i));
//         }
//         i++;
//     }
//     return(M);
// }

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!b && len == 0)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int *ft_create_state(int P, int *M_0)
{
    int *places;
    int i;

    places = malloc(sizeof(int) * (P + 1));
    if(!places)
        return(NULL);
    i = 0;
    while (i < P)
    {
        places[i] = M_0[i];
        i++;
    }
    return(places);
}