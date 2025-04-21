/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast <ast@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/04/21 22:11:55 by ast              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CYCLE_DATA_H
#define CYCLE_DATA_H

#include "../../include/global.h"

#define LAST_MEAL 0
#define START 1
#define END_THINK 2
#define G_FORK 3
#define END_EAT 4
#define R_FORK 5
#define END_SLEEP 6
#define R_SIZE  7

typedef pthread_mutex_t t_mutex;

typedef struct s_report
{
    int                     id;
    int                     cycle;
    long long               report[R_SIZE];
    struct s_report         *next;
    
} t_report;

t_report    *create_new_report(int cycle, int id);
int         archive_report(t_report **archive, t_report *report);
t_report    ***create_archive_module(int n);
void        *clean_archive_module(t_report ****archive, int len);

void        display_report(t_report *report, int header);
void        display_archives(t_report **archive);

#endif