/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:32:42 by xjose             #+#    #+#             */
/*   Updated: 2024/06/25 15:32:31 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_programa(int error)
{
	if (error == -1)
	{
		ft_printf("\033[1;31mSERVIDOR NÃO ENCONTRADO🙀\033[0m\n");
		exit(1);
	}
}

void	print_erro_arg(void)
{
	ft_printf("\033[1;31m./client \033[1;33m[PID]");
	ft_printf("\033[0m\033[1;32m[MENSAGEM]\033[0m\n\033[0m");
}
