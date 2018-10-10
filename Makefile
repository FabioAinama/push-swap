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
	@gcc checker.c ps_parser.c rotate.c swap-push.c helper.c utils.c libft/libft.a -o checker
	@gcc push-swap.c sort_algo.c transform-numbers.c helper.c utils.c rotate.c split.c ps_parser.c swap-push.c libft/libft.a
	@mv a.out push-swap
	@echo "Compilation terminée..."	

test0 :
	@python3 pyviz.py 16 5 22 0 13 1 20 55

test1 :
	@./push-swap 5 4 1 3 2

test2 :
	@./push-swap 16 5 22 13 1 20 55 2 89 34 25

testneg :
	@python3 pyviz.py -5 2 3 -1 -4 -3 -2 1

testmix :
	@./push-swap "-10 8 -7 9 5 6" 4 3 2 1 "11"

test35 :
	@./push-swap 21 7 31 4 30 11 6 32 26 10 25 1 20 9 14 33 2 18 34 23 22 13 19 12 17 27 3 24 35 28 15 8 16 5 29

test40 :
	@./push-swap 21 7 31 32 38 4 30 11 6 26 10 25 39 1 20 9 14 33 2 18 34 23 22 13 35 19 36 12 17 37 27 3 24 28 40 15 8 16 5 29

test50 :
	@./push-swap 21 7 31 50 38 4 43 32 30 46 11 41 6 26 10 25 39 48 1 20 42 9 14 33 2 18 34 23 22 13 44 49 35 19 36 12 17 37 45 27 3 47 24 28 40 15 8 16 5 29

test60 :
	@./push-swap 21 7 31 50 57 38 4 43 32 52 30 46 11 41 6 51 26 10 55 25 39 48 1 20 42 9 14 33 2 18 34 23 22 13 54 44 49 35 19 36 58 12 17 37 45 59 27 53 3 47 24 28 40 56 15 8 16 5 60 29

test65 :
	@./push-swap 61 21 7 31 50 57 38 63 4 43 32 52 30 62 46 11 41 6 51 26 10 55 25 39 48 1 20 42 9 14 33 2 18 34 23 22 13 54 44 49 35 19 36 58 12 17 37 45 59 64 27 53 3 47 24 28 40 56 15 8 16 5 60 29 65

test75 :
	@./push-swap 61 21 7 31 50 57 69 38 63 4 43 32 52 30 62 46 73 11 67 41 6 51 26 10 55 75 25 39 48 1 74 20 42 9 14 33 2 18 34 23 66 22 13 72 54 44 49 35 19 36 58 68 12 17 37 45 59 64 27 53 3 47 70 24 28 40 56 70 15 8 16 5 60 29 65

test85 :
	@./push-swap 61 21 7 31 50 57 69 38 63 82 4 43 32 52 30 78 62 46 73 11 67 41 6 51 26 10 55 75 25 39 48 1 74 20 42 77 9 14 33 2 76 18 34 23 66 22 83 13 72 54 44 49 35 85 19 36 58 68 12 17 80 37 45 59 64 27 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65

vis100 :
	@python3 pyviz.py 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 87 61 21 7 31 50 57 69 38 63 82 4 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 71 15 8 16 5 60 29 84 65

vis200 :
	@python3 pyviz.py 87 61 21 7 50 31 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 -10 -20 -30

test100 :
	@./push-swap 6 61 21 7 31 50 57 69 38 32 90 52 30 78 62 46 73 11 99 67 89 87 41 51 98 26 10 91 55 75 25 39 48 86 63 82 4 43 1 74 20 92 42 77 9 14 33 2 76 18 94 34 8 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 71 15 16 5 60 29 84 65

test500 :
	@./push-swap 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65

vis500 :
	@python3 pyviz.py 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65 87 61 21 7 31 50 57 69 38 63 82 4 43 32 90 52 30 78 62 46 73 11 99 67 89 41 6 51 98 26 10 91 55 75 25 39 48 86 1 74 20 92 42 77 9 14 33 2 76 18 94 34 23 66 22 96 83 13 72 54 93 44 49 100 35 95 85 19 36 58 68 12 17 80 37 88 45 59 64 27 97 79 53 3 47 70 24 28 40 81 56 70 15 8 16 5 60 29 84 65

random100 :
	python3 pyviz.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"` 

trandom100 :
	@./push-swap `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"` 

random200 :
	python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"` 

random500 :
	python3 pyviz.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` 