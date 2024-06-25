/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:41:35 by xjose             #+#    #+#             */
/*   Updated: 2024/06/25 15:37:23 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include "libft/libft.h"
# include <signal.h>

# define B1 SIGUSR1
# define B0 SIGUSR2

void	print_erro_arg(void);
void	exit_programa(int error);

#endif