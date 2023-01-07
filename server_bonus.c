/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:52:09 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/07 15:23:59 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

int	ft_print(int i, int k, char *string)
{
	i = 0;
	ft_putchar(bin_ascii(string));
	if (bin_ascii(string) == 0)
	{
		usleep(150);
		kill(k, SIGUSR1);
	}
	return (i);
}

char	g_str[9];
void	ft_handler(int sig, siginfo_t *info, void *p)
{
	static int	i;
	static int	k;
	int			j;

	(void)p;
	j = info->si_pid;
	if (j != k)
		i = 0;
	k = j;
	if (sig == SIGUSR1)
		g_str[i] = '0';
	if (sig == SIGUSR2)
		g_str[i] = '1';
	i++;
	if (i >= 8)
		i = ft_print(i, k, g_str);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr("PID:");
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	pause();
	return (0);
}
