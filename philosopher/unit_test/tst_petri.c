/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_petri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:55:10 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/15 23:06:05 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_ft_create_petri_net(void)
{
	TEST_START;
	t_petri_network	*network_1;
	int	pt[T];
	char	*m0 = strdup("1 0 0 1");
	char	*m_out = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	char	*m_int = strdup("1 0 0 0 1 0 0 0 3 0 1 0");
	
	pt[0] = P;
	pt[1] = T;
	
	network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
	if(!network_1)
		return(1);
	assert(network_1->M0 && network_1->M_in && network_1->M_out && network_1->Mp && network_1->Mt && network_1->p && network_1->t);
	
	ft_print_petri_matrice(network_1->M_in,4,3,1);
	ft_print_petri_matrice(network_1->M_out,4,3,1);
	ft_print_network(network_1);
	
	TEST_SUCCES;
	return(1);
	
}




