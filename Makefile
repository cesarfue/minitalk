# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/12/03 16:22:23 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

HEADER = minitalk.h

NAME_SERVER = server
NAME_CLIENT = client

CC = cc -g

FLAGS = -I includes

all : ${NAME_SERVER} ${NAME_CLIENT}

%.o : %.c ${HEADER}
    ${CC} ${FLAGS} -c $< -o $@

${NAME_SERVER} : ${OBJS_SERVER}
    ${CC} ${FLAGS} -o ${NAME_SERVER} ${OBJS_SERVER}

${NAME_CLIENT} : ${OBJS_CLIENT}
    ${CC} ${FLAGS} -o ${NAME_CLIENT} ${OBJS_CLIENT}

clean :
    rm -f *.o

fclean : clean
    rm -f ${NAME_SERVER} ${NAME_CLIENT}

re : fclean all

.PHONY : all clean fclean re
