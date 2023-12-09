# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrett <fbarrett@42quebec.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 09:59:24 by fbarrett          #+#    #+#              #
#    Updated: 2023/12/09 11:27:57 by fbarrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

MY_LIBRARY	=	./Libft/

MY_SOURCES	=	main.c	push_swap_utils.c	push_swap_utils2.c	operators.c\
				operators2.c	sort_stacks.c	small_stack.c	push_swap_utils3.c

BONUS_SOURCES	=	

TEST_SOURCES	= test_operators.c

MY_OBJECTS	=	$(MY_SOURCES:%.c=%.o)

MY_BONUS	=	$(BONUS_SOURCES:%.c=%.o)

MY_TESTS	=	$(TEST_SOURCES:%.c=%.o)

CC	=	gcc

LIBFLAGS = -L./Libft/ -lft -I.

CCFLAGS	=	-Wall -Wextra -Werror -g

all:	$(NAME)

$(NAME): $(MY_OBJECTS) $(MY_LIBRARY)
	@make -C $(MY_LIBRARY)
	$(CC) $(CCFLAGS) -o $(NAME) $(MY_OBJECTS) $(LIBFLAGS)

test: $(MY_OBJECTS) $(MY_LIBRARY) $(MY_TESTS)
	@make -C $(MY_LIBRARY)
	$(CC) $(CCFLAGS) -o test $(MY_OBJECTS) $(MY_TESTS) $(LIBFLAGS)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re test
