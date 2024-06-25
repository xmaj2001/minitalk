/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:24:54 by xjose             #+#    #+#             */
/*   Updated: 2024/06/25 15:13:41 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	listener(int sinal, siginfo_t *info, void *uc)
{
	static unsigned char	ch;
	static int				bit;

	(void)uc;
	ch |= (sinal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (ch == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, B1);
		}
		else
			write(1, &ch, 1);
		ch = 0;
		bit = 0;
	}
	else
		ch <<= 1;
}

void	load_server(void)
{
	int	delay;
	int	i;
	int	time;

	delay = 500000;
	i = 1;
	time = 8;
	ft_printf("\033[1;31mCARREGANDO O SERVIDOR ");
	while (i < time)
	{
		usleep(delay);
		ft_printf(".");
		i++;
	}
	ft_clear();
}

void	info(void)
{
	load_server();
	ft_printf("\033[0m\033[0;32m");
	ft_printf("==========================================================\n");
	ft_printf("||------------------------------------------------------||\n");
	ft_printf("||                      SERVIDOR                        ||\n");
	ft_printf("||------------------------------------------------------||\n");
	ft_printf("==========================================================\n");
	ft_printf("\033[0;32m");
	ft_printf("SERVIDOR ONLINE 😎\n");
	ft_printf("\033[0;33mPID %d\n\033[0m", getpid());
	ft_printf("ESPERANDO MENSAGEM...\n");
	ft_printf("\033[0;32m");
}

void	server(void)
{
	struct sigaction	s_sig;

	s_sig.sa_sigaction = &listener;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(B1, &s_sig, NULL);
	sigaction(B0, &s_sig, NULL);
}

int	main(void)
{
	info();
	while (1)
		server();
	return (0);
}
