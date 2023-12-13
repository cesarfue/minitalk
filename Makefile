# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/12/13 10:19:43 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf

SERVER = server
SERVER_B = server_bonus
CLIENT = client
CLIENT_B = client_bonus

SERVER_SRCS = srcs/server.c
SERVER_B_SRCS = srcs_bonus/server_bonus.c
CLIENT_SRCS = srcs/client.c
CLIENT_B_SRCS = srcs_bonus/client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_B_OBJS = $(SERVER_B_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_B_OBJS = $(CLIENT_B_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
	
$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client
	
$(SERVER_B): $(SERVER_B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_B_OBJS) $(LIBFT) -o server_bonus
$(CLIENT_B): $(CLIENT_B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_B_OBJS) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(SERVER_B_OBJS) $(CLIENT_B_OBJS) 
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_B) $(CLIENT_B)
re: fclean all

bonus: $(SERVER_B) $(CLIENT_B)