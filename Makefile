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

PS_NAME = push_swap
CH_NAME = checker
LIBFT = ./libft
OBJS_PS = ${SRC_PS:.c=.o}
OBJS_CH = ${SRC_CH:.c=.o}
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror
CC = gcc

SRC = sort_algo.c transform_numbers.c helper.c utils.c rotate.c split.c ps_parser.c \
	swap_push.c ps_result.c simple_sort.c error.c malloc_res.c close_fd.c fd_dealer.c

SRC_PS = push_swap.c

SRC_CH = checker.c


all : $(CH_NAME) $(PS_NAME)
	@echo "Usage push_swap: './push_swap -f [file]' Write results in [file]"
	@echo "Usage checker: './checker -f [file]' Read results from [file]"
	@echo "Usage checker: './checker -v' Launch visualizer"

$(CH_NAME) : $(OBJS) $(OBJS_CH)
	@echo "Compiling Checker..."
	@make -C $(LIBFT) > /dev/null || true
	@$(CC) $(FLAGS) $(SRC) $(SRC_CH) -L $(LIBFT) -lft -o $(CH_NAME)
	@echo "Compiling checker over"	

$(PS_NAME) : $(OBJS) $(OBJS_PS)
	@echo "Compiling Push_swap..."
	@make -C $(LIBFT) > /dev/null || true
	@$(CC) $(FLAGS) $(SRC) $(SRC_PS) -L $(LIBFT) -lft -o $(PS_NAME)
	@echo "Compiling Push_swap over"

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS_PS) $(OBJS_CH) $(OBJS)

fclean :
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJS_PS) $(OBJS_CH) $(OBJS)
	@rm -rf $(PS_NAME) $(CH_NAME)

re : fclean all

full5 :
	@ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG

full100 :
	@ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG

full500 :
	@ARG=`ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG

vis5 :
	@ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -v $$ARG

vis100 :
	@ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -v $$ARG

vis500 :
	@ARG=`ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -v $$ARG

norminette :
	@norminette $(SRC) $(SRC_CH) $(SRC_PS) push_swap.h

checker_error :
	./checker yolo 2>&1 | cat -e
	./checker 1 2 3 4 3 2>&1 | cat -e
	./checker 2147483650 2>&1 | cat -e
	./checker 2>&1 | cat -e

checker_false :
	echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; echo "sa\npb\nsa\npb\nrrr" | ./checker $$ARG

checker_right :
	echo "\0" | ./checker 0 1 2
	echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2

ps_right :
	./push_swap 42
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9

ps_right :
	./push_swap 1 5 2 4 3