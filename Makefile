# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 18:06:09 by kalmheir          #+#    #+#              #
#    Updated: 2022/06/18 15:25:56 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minitalk
SRVN =		server
SRVS =		src/server/main.c src/server/utils.c
CLIN =		client
CLIS =		src/client/main.c
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LBFT =		libft.a
MKLB =		make -C lib
MOVE =		mv lib/

all: server client

${LBFT}:
	${MKLB}
	${MOVE}${LBFT} ${LBFT}
	${MKLB} fclean

server: ${LBFT} ${SRVS}
	${CC} ${CFLAGS} ${SRVS} ${LBFT} -o ${SRVN}

client: ${LBFT} ${CLIS}
	${CC} ${CFLAGS} ${CLIS} ${LBFT} -o ${CLIN}

clean:
	${RM} ${LBFT}

fclean: clean
	${RM} ${SRVN}
	${RM} ${CLIN}

re: fclean all
