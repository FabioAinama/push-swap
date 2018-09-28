# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 15:31:26 by fginja-d          #+#    #+#              #
#    Updated: 2018/09/25 15:31:28 by fginja-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	@echo "Compilation..."
	@gcc push-swap.c sort-algo.c transform-numbers.c checker.c order-b.c order-a.c libft/libft.a
	@echo "Compilation terminée..."	

test0 :
	@./a.out 16 5 22 13 1 20 55

test1 :
	@./a.out 5 4 1 3 2

test2 :
	@./a.out 16 5 22 13 1 20 55 2 89 34 25

test3 :
	@./a.out 4 3 2 1

test4 :
	@./a.out 21 7 31 4 30 11 6 32 26 10 25 1 20 9 14 33 2 18 34 23 22 13 19 12 17 27 3 24 35 28 15 8 16 5 29

test5 :
	@./a.out 21 7 31 32 38 4 30 11 6 26 10 25 39 1 20 9 14 33 2 18 34 23 22 13 35 19 36 12 17 37 27 3 24 28 40 15 8 16 5 29

test6 :
	@./a.out 21 7 31 38 4 43 32 30 11 41 6 26 10 25 39 1 20 42 9 14 33 2 18 34 23 22 13 44 35 19 36 12 17 37 45 27 3 24 28 40 15 8 16 5 29

random100 :
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
	@./a.out $ARG