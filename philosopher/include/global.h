/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/15 18:29:25 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
#define GLOBAL_H

#define PLACE 4
#define TRANSITION 3

#define MIN_P    3      /*minimum number of philosophe*/
#define MIN_TTE  1000   /*minimum time to eat*/
#define MIN_TTS  1000   /*minimum time to spleep*/
#define MIN_TTD  1000   /*minimum time to die*/

int	*ft_init_and_check_argument(char **argv, int len);

#endif