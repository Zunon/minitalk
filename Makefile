# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 18:06:09 by kalmheir          #+#    #+#              #
#    Updated: 2022/06/18 16:07:01 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minitalk
SRVN =		server
SRVS =		src/server/main.c src/server/utils.c
CLIN =		client
CLIS =		src/client/main.c
BCLS =		extra/client/main_bonus.c
BCLN =		client_bonus
BSRN =		server_bonus
BSRS =		extra/server/main_bonus.c extra/server/utils_bonus.c
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LBFT =		libft.a
MKLB =		make -C lib
MOVE =		mv lib/

mandatory: client server

all: mandatory bonus

bonus: client_b server_b

${LBFT}:
	${MKLB}
	${MOVE}${LBFT} ${LBFT}
	${MKLB} fclean

server: ${LBFT} ${SRVS}
	${CC} ${CFLAGS} ${SRVS} ${LBFT} -o ${SRVN}

client: ${LBFT} ${CLIS}
	${CC} ${CFLAGS} ${CLIS} ${LBFT} -o ${CLIN}

server_b: ${LBFT} ${BSRS}
	${CC} ${CFLAGS} ${BSRS} ${LBFT} -o ${BSRN}

client_b: ${LBFT} ${BCLS}
	${CC} ${CFLAGS} ${BCLS} ${LBFT} -o ${BCLN}

clean:
	${RM} ${LBFT}

fclean: clean
	${RM} ${SRVN}
	${RM} ${CLIN}
	${RM} ${BSRN}
	${RM} ${BCLN}

re: fclean all
