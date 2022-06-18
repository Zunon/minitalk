# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 18:06:09 by kalmheir          #+#    #+#              #
#    Updated: 2022/06/17 19:02:33 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		hello
SRCS =		hi.c
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LBFT =		libft.a
MKLB =		make -C lib
MOVE =		mv lib/

all: ${LBFT}
	${CC} ${CFLAGS} ${SRCS} libft.a -o ${NAME}
	echo done

${LBFT}:
	${MKLB}
	${MOVE}${LBFT} ${LBFT}
	${MKLB} fclean

clean:
	${RM} ${LBFT}

fclean: clean
	${RM} ${NAME}

re: fclean all
