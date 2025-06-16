# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 22:29:06 by jnuno-da          #+#    #+#              #
#    Updated: 2025/06/16 20:08:22 by jnuno-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
NAME = minitalk
LIBFT = ./libft

SERVER_NAME = server
CLIENT_NAME = client

SRCS_SERVER = srcs/server.c
SRCS_CLIENT = srcs/client.c

SERVER_OBJ = $(SRCS_SERVER:.c=.o)
CLIENT_OBJ = $(SRCS_CLIENT:.c=.o)

RM = rm -f 

all: ${NAME} 
	
${NAME}: $(CLIENT_OBJ) $(SERVER_OBJ)
					$(MAKE) -C $(LIBFT)
					cp $(LIBFT)/libft.a .
					$(CC) $(CFLAGS) $(SERVER_OBJ) libft.a -o $(SERVER_NAME)	
					$(CC) $(CFLAGS) $(CLIENT_OBJ) libft.a -o $(CLIENT_NAME)	

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(MAKE) clean -C $(LIBFT)
	@echo "Objects deleted"

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) fclean -C $(LIBFT)
	@echo "CLient, Server, libft deleted"

re: fclean all