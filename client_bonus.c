/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:14:40 by xjose             #+#    #+#             */
/*   Updated: 2024/06/25 15:42:48 by xjose            ###   ########.fr       */
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

void	ms_ok(int sinal)
{
	if (sinal == B1)
	{
		ft_printf("\033[1;33mMENSAGEM ENVIADA👍\033[0m\n");
		exit(0);
	}
}

void	listener(void)
{
	struct sigaction	s_action;

	ft_clear();
	s_action.sa_handler = &ms_ok;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(B1, &s_action, NULL);
	sigaction(B0, &s_action, NULL);
}

int	main(int c, char *v[])
{
	pid_t	pid;

	g_error = 0;
	if (c != 3)
		print_erro_arg();
	else
	{
		pid = ft_atoi(v[1]);
		if (pid == 0)
		{
			ft_printf("\033[1;31mESTE PID\033[0m \033[1;32m%s ", v[1]);
			ft_printf("\033[1;31mÉ INVALIDO.\n\033[0m");
			exit(1);
		}
		pid = ft_atoi(v[1]);
		ft_printf("\033[0;35mENVIANDO MENSAGEM AO SERVIDOR ...\n \033[0m");
		listener();
		send_ms(pid, v[2]);
		while (1)
		{
			exit_programa(g_error);
			pause();
		}
	}
	return (0);
}
