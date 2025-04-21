/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_data_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/21 22:00:37 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cycle_data.h"

static void display_report_header(int id)
{
    printf("Report philosophe %d\n", id);
    printf("[Col 0] : Cycle \t[Col 1] : Last meal\n");
    printf("[Col 2] : Start \t[Col 3] : End Thinking\n");
    printf("[Col 4] : Get fork \t[Col 5] : End eat\n");
    printf("[Col 6] : Release Fork \t[Col 7] : End_sleep\n");
    printf("\n");
}

void display_report(t_report *report, int header)
{
    int i;

    if(!report)
        return ;
    if(header == 1)
        display_report_header(report->id);
    i = 0;
    while (i < R_SIZE + 1)
    {
        if(i == 0)
            printf("Cycle %d \t",report->cycle);
        else
            printf("%lld \t", report->report[i - 1]);
        i++;
    }
    printf("\n");
}

void display_archives(t_report **archive)
{
    t_report *first;
    
    if(!archive || !*archive)
        return ;
    first = *archive;
    display_report_header(0);
    while (first)
    {
        display_report(first, 0);
        first = first->next;
    }
    
}

