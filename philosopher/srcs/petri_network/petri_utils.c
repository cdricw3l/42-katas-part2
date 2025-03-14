/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:50:09 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/14 09:52:47 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/petri_network/petri_network.h"

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
            return(ft_clean_matrice_mem(new_matrice, i));
        j = 0;
        while (j < t*n)
            new_matrice[i][j++] = 0;
        i++;
    }
    return(new_matrice);
}

void ft_join_matrice(int **old_m,int **new_m, int p, int t , int n)
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
        while(i < p)
        {
            j = 0;    
            while (j < t)
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

int **matrice_fusion(int **m, int p, int t, int n)
{
    int **new_matrice;

    new_matrice = ft_create_matrice(p, t, n);
    if(!new_matrice)
        return(NULL);
    ft_join_matrice(m,new_matrice, p, t, n);
    free(m);
    ft_print_matrice(new_matrice,p * n, t * n);
    return(new_matrice);
}

int **ft_copy_matrice(int **M_in, int P, int T)
{
    int i;
    int r;
    int **M;

    M = malloc(sizeof(int *) * P);
    if(!M)
        return(NULL);
    i = 0;
    while (i < P)
    {
        M[i] = malloc(sizeof(int) * T);
        if(!M[i])
            return(ft_clean_matrice_mem(M, i));
        r = ft_memcpy(M_in[i], M[i], sizeof(int) * T);
        if(r / sizeof(r) != T)
        {
            perror("Err ft_copy_matrice");
            return(ft_clean_matrice_mem(M, i));
        }
        i++;
    }
    return(M);
}

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
void ft_print_matrice_network(t_petri_network *network)
{

    printf("\n[ P: %d ]\n\n", network->p);
    // ft_print_arr_int(network->M0, network->p);
    printf("\n[ T: %d ]\n\n", network->t);
    //ft_print_arr_int(network->T, network->t);
    printf("\n[ matrice M 0 ]\n\n");
    //ft_print_arr_int(network->M0, network->p);
    printf("\n[ matrice M_out ]\n\n");
    ft_print_matrice(network->M_out, network->p, network->t);
    printf("\n[ matrice M_in ]\n\n");
    ft_print_matrice(network->M_in, network->p, network->t);
    printf("\n");
}

void ft_print_matrice(int **m, int p, int t)
{
	int i;
	int mod;

	i = 0;
	mod = 0;
	while (i < p)
	{
		ft_print_arr_int(m[i], t);
		if(mod == 3)
		{
			printf("\n");
			mod = -1;
		}
		mod++;
		i++;
	}	
}

void	ft_print_arr_int(int *arr, int len)
{
	int i;
	int mod;

	i = 0;
	mod = 0;
	while(i < len)
	{
		if(arr[i] == 0)
			printf("%d ", arr[i]);
		else
			printf("\x1B[32m" " %d " "\x1B[0m", arr[i]);
		if(mod == 2)
		{
			printf(" ");
			mod = -1;
		}
		mod++;
		i++;
	}
	printf("\n");
	
}