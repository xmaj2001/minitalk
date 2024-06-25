/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:14:40 by xjose             #+#    #+#             */
/*   Updated: 2024/06/25 15:33:29 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_error;

void	send_char_tobit(pid_t pid, char ch)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (ch & 0b10000000)
			g_error = kill(pid, B1);
		else
			g_error = kill(pid, B0);
		ch <<= 1;
		usleep(10);
	}
}

void	send_ms(pid_t pid, char *ms)
{
	while (*ms)
	{
		send_char_tobit(pid, *ms);
		ms++;
	}
	send_char_tobit(pid, '\0');
}

void	info(void)
{
	ft_printf("\033[0;35m");
	ft_printf("ENVIANDO MENSAGEM AO SERVIDOR ...\n \033[0;33m");
	ft_printf("\033[0m");
}

int	main(int c, char *v[])
{
	pid_t	pid;

	g_error = 0;
	if (c != 3)
		print_erro_arg();
	else
	{
		ft_clear();
		pid = ft_atoi(v[1]);
		if (pid == 0)
		{
			ft_printf("\033[1;31mESTE PID\033[0m \033[1;32m%s ", v[1]);
			ft_printf("\033[1;31mÉ INVALIDO.\n\033[0m");
			exit(1);
		}
		info();
		pid = ft_atoi(v[1]);
		send_ms(pid, v[2]);
		exit_programa(g_error);
		ft_clear();
		ft_printf("\033[1;33mMENSAGEM ENVIADA👍\033[0m\n");
	}
	return (0);
}
