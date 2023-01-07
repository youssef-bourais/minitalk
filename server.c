/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:14:11 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/07 15:24:11 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(unsigned int a, unsigned int b)
{
	int	n;

	n = 1;
	if (b == 0)
		return (1);
	if (a == 0)
		return (0);
	while (b > 0)
	{
		n = a * n;
		b--;
	}
	return (n);
}

int	bin_ascii(char *str)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 7;
	while (i <= 7 && j >= 0)
	{
		n = n + (str[i] - '0') * ft_power(2, j);
		j--;
		i++;
	}
	return (n);
}

char	g_str[9];
void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	int			n;
	int			j;
	static int	k;

	(void)context;
	j = info->si_pid;
	if (k == 0 || j != k)
	{
		k = j;
		i = 0;
	}
	if (sig == SIGUSR1)
		g_str[i] = '0';
	if (sig == SIGUSR2)
		g_str[i] = '1';
	i++;
	if (i == 8)
	{
		i = 0;
		g_str[8] = '\0';
		n = bin_ascii(g_str);
		write(1, &n, sizeof(char));
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	msg;

	pid = getpid();
	ft_putstr("PID:");
	ft_putnbr(pid);
	write(1, "\n", 1);
	msg.sa_sigaction = ft_handler;
	msg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &msg, NULL);
	sigaction(SIGUSR2, &msg, NULL);
	while (1)
		;
	pause();
	return (0);
}
