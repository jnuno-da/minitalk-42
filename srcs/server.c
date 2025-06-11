/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:29:11 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/06/11 22:51:19 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_receiver(int sig)
{
	static int	bit = 0;
	static char	c = 0;

	c = c << 1;
	if (sig == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf ("SERVER PID = %d\n", getpid());
	signal (SIGUSR1, signal_receiver);
	signal (SIGUSR2, signal_receiver);
	while (1)
		pause ();
	return (0);
}
