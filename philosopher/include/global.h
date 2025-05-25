/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/05/22 19:54:07 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <assert.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define ON 1
# define OFF 0

# define MIN_P    2
# define MAX_P    200      
# define MIN_TTD  60   
# define MIN_TTE  60   
# define MIN_TTS  60   
# define CYCLE_NB 100

# define P 0
# define TTD 1
# define TTE 2
# define TTS 3
# define CYCLE 4
# define ID 5
# define STATE_1 6
# define STATE_2 7

# define ON 1
# define OFF 0

typedef pthread_mutex_t	t_mutex;

typedef struct s_mutex_data
{
	t_mutex	**pens;
	t_mutex	**m_states;
	t_mutex	**cycle_counter;
	t_mutex	**forks;
	t_mutex	*print;
}	t_mutex_data;

typedef struct s_philo
{
	int			pametres[8];
	long long	start;
	t_mutex		*fork_1;
	t_mutex		*fork_2;
	t_mutex		*pen;
	t_mutex		*m_state;
	t_mutex		*print;
	t_mutex		*m_counter;
	long long	*time_data;
	int 		cycle_counter;

}	t_philo;

typedef struct s_network
{
	int				pametres[8];
	long long		**time_board;
	t_mutex_data	*mutex_data;
	t_philo			**philos;

}	t_network;

int	*ft_init_and_check_argument(char **argv, int len);

#endif