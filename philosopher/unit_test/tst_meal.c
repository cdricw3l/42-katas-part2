/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_meal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:45 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/21 19:20:47 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tst_unit.h"

#define LAST_MEAL 0
#define START 1
#define END_THINK 2
#define G_FORK 3
#define END_EAT 4
#define R_FORK 5
#define END_SLEEP 6
#define R_SIZE  7

typedef struct s_report
{
    int                     cycle;
    int                     id;
    long long               report[R_SIZE];
    struct s_report         *next;
    
} t_report;


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

char *get_header(int i)
{
    if(i == 0)
        return("\t");
    if(i == 1)
        return("LM \t");
    if(i == 2)
        return("ST \t");
    if(i == 3)
        return("ET \t");
    if(i == 4)
        return("GF \t");
    if(i == 5)
        return("Ee \t");
    if(i == 6)
        return("RL \t");
    if(i == 7)
        return("ES \t");
    return(NULL);
}

void display_report_header(void)
{
    int i;

    i = 0;
    while (i < R_SIZE + 1)
    {
        printf("%s ",get_header(i));
        i++;
    }
    printf("\n");
}

void display_report(t_report *report, int header)
{
    int i;

    if(!report)
        return ;
    if(header == 1)
        display_report_header();
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
    display_report_header();
    while (first)
    {
        display_report(first, 0);
        first = first->next;
    }
    
}

void simulation_cycle(long long *report, long long start)
{
    int i;

    if(!report)
        return ;
    i = 0;
    while (i < R_SIZE)
    {
        report[i] = get_current_time() - start;
        ft_temporisation(200,get_current_time());
        i++;
    }
}

int tst_meal(void)
{
    t_report *report;
    t_report **archive;
    long long start;

    int i;

    i = 0;
    archive = malloc(sizeof(t_report*));
    if(!archive)
        return(0);
    start = get_current_time();
    while (i < 10)
    {
        report = create_new_report(i,1);
        simulation_cycle(report->report, start);
        if(!archive_report(archive, report))
        {
            printf("error\n");
            return(0);
        }
        i++;
    }
    display_archives(archive);
    return(1);
}