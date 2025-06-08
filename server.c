/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:29:11 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/06/08 01:37:38 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler()
{

	
}

int main (void)
{
	ft_printf("SERVER PID = %d\n", getpid());

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	{
	}
	return(0);
}