/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:22:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/16 20:31:39 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int	main(void)
{   
    // assert(tst_utils() == 1);
    // assert(tst_ft_init_arr_arg() == 1);
    //assert(tst_ft_create_petri_net() == 1);
    assert(tst_network_extend());
    //assert(tst_thread_managment() == 1);
    
	return(0);
}