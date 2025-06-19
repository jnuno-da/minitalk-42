/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:29:09 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/06/19 10:51:13 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"

# define BLOCK_SIZE 1024
# define MAX_BLOCKS 100

typedef struct s_buffer
{
	char	**blocks;
	int		block_index;
	int		char_index;	
}	t_buffer;

#endif