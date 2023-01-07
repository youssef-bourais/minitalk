/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:52:55 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/06 19:31:47 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
char	*ft_bin(int a);
void	ft_send_signal(char *pid, char *s);
void	ft_handler(int sig, siginfo_t *info, void *context);
int		ft_power(unsigned int a, unsigned int b);
int		bin_ascii(char *str);

#endif
