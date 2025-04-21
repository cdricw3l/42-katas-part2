/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/21 21:58:13 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cycle_data.h"

t_report *create_new_report(int cycle, int id)
{
    t_report *report;

    report = malloc(sizeof(t_report));
    if(!report)
        return(NULL);
    report->cycle = cycle;
    report->id = id;
    memset(&report->report, 0, sizeof(long long) * 7);
    report->next = NULL;
    return(report);
}

int    archive_report(t_report **archive, t_report *report)
{
    t_report *first;

    if(!archive || !report)
        return (0);
    if(!*archive)
    {
        *archive = report;
        return (1);
    }
    first = *archive;
    report->next = first;
    *archive = report;
    return (1);
}

void *clean_archive_module(t_report ****archive, int len)
{
    t_report ***archive_r;
    int i;

    i = 0;
    archive_r = *archive;
    while (i < len)
    {
        free(archive_r[i]);
        archive_r[i] = NULL;
        i++;
    }
    free(*archive);
    *archive = NULL;
    return(NULL);
}

t_report ***create_archive_module(int n)
{
    t_report ***archive;
    int i;

    archive = malloc(sizeof(t_report**) * n);
    if(!archive)
        return(NULL);
    i = 0;
    while (i < n)
    {
        archive[i] = malloc(sizeof(t_report *));
        if(!archive[i])
            return(clean_archive_module(&archive, i));
        i++;
    }
    
    return(archive);
}