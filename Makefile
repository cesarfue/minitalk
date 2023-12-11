# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/12/08 08:36:25 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_SERVER	:= $(addprefix build/, $(OBJS_SERVER))
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_CLIENT	:= $(addprefix build/, $(OBJS_CLIENT))


HEADER = includes/minitalk.h

SERVER = server
CLIENT = client

CC = cc -g

FLAGS = -Wall -Wextra -Werror -I includes -fsanitize=address

all :	${SERVER} ${CLIENT}

build/server.o :	server.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

build/client.o :	client.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${SERVER} :	${OBJS_SERVER}
	${CC} ${FLAGS} -o ${SERVER} ${OBJS_SERVER}

${CLIENT} :	${OBJS_CLIENT}
	${CC} ${FLAGS} -o ${CLIENT} ${OBJS_CLIENT}

clean :
	rm -f build/*.o

fclean :	clean
	rm -f ${SERVER} ${CLIENT}

re :	fclean all

.PHONY : all clean fclean re