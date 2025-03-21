/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptri_network_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:50:09 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/21 22:42:03 by cw3l             ###   ########.fr       */
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

// int ft_add_add(t_petri_network *network, t_arc arc)
// {

//     // est ce un ajout ou un retrai: est ce t ---> p or p ---> t.?
//     // Si t ---> p, action sur W+ arc.direction == 0
//     // Si p ---> t, action sur w-

//     if(!network && !ft_network_check(network, network->p))
//         return(0);
//     if(arc.direction == t_to_p)
//     {
//         //verification de la matrice.
//         if(!network->M_in || !network->M_in[arc.p])
//             return(0);
//         network->M_in[arc.p][arc.t] = arc.weight;
//     }
//     if(arc.direction == p_to_t)
//     {
//         //verification de la matrice.
//         if(!network->M_out || !network->M_in[arc.p])
//             return(0);
//         network->M_out[arc.p][arc.t] = arc.weight;
//     }
//     return(1);
// }

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