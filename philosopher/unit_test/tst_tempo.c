/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_tempo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:52:51 by ast               #+#    #+#             */
/*   Updated: 2025/04/19 21:57:10 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

int tst_tempo(void)
{
    long long current;
    long long current2;

    current = get_current_time();
    sleep(1);
    current2 = get_current_time();
    printf("voci current %lld\n", current2 - current);
    return(1);
}