/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:54:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/16 14:54:24 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst_unit.h"

int tst_split(void)
{
    char h[]= "hello***world***demerde***comment";

    char **split;

    split = ft_split(h,'*');
    if(!split)
        return(1);
    if(split)
    {
        assert(ft_get_split_len(split) == 4);
        ft_split_print(split);
        ft_split_clean(&split);

    }
    return(1);
}