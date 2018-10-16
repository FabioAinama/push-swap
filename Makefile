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
	@gcc checker.c ps_parser.c rotate.c swap_push.c helper.c utils.c ps_result.c error.c fd_dealer.c libft/libft.a -o checker
	@gcc push-swap.c sort_algo.c transform-numbers.c helper.c utils.c rotate.c split.c ps_parser.c swap_push.c ps_result.c simple-sort.c error.c libft/libft.a
	@mv a.out push-swap
	@echo "Compilation terminée..."	

random9 :
	python3 pyviz.py `ruby -e "puts (-5..3).to_a.shuffle.join(' ')"`

trandom9 :
	./push-swap `ruby -e "puts (-5..3).to_a.shuffle.join(' ')"`

random3 :
	python3 pyviz.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`

random5 :
	python3 pyviz.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"` | cat -e

trandom5 :
	./push-swap `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`

fail100 :
	python3 pyviz.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

random100 :
	./push-swap `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

full100 :
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push-swap $$ARG | ./checker $$ARG

vis100 :
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push-swap $$ARG | ./checker -v $$ARG


vis500 :
	ARG=`ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`; ./push-swap $$ARG | ./checker -v $$ARG

trandom100 :
	./push-swap -f res.txt `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

random200 :
	python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

random500 :
	python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

debug :
	./debug res.txt res2.txt > final.txt