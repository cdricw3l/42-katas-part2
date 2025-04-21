/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_meal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:45 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/21 22:07:24 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

void simulation_cycle(long long *report, long long start)
{
    int i;

    if(!report)
        return ;
    i = 0;
    while (i < R_SIZE)
    {
        report[i] = get_current_time() - start;
        ft_temporisation(50,get_current_time());
        i++;
    }
}

int tst_meal(void)
{
    t_report *report;
    t_report ***archive;
    
    archive = create_archive_module(5);
    if(!archive)
        return(0);
    report = create_new_report(0,0);
    
    archive_report(archive[0], report);
    simulation_cycle(archive[0][0]->report,get_current_time());
    display_archives(archive[0]);
    return(1);
}