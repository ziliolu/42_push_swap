NAME = push_swap.a
EXEC = push_swap
LIBFT_A = ./libft/libft.a

SRC =	./src/main.c					\
		./src/init_structs.c			\
		./src/print_stack.c				\
		./src/push.c					\
		./src/rotate.c					\
		./src/reverse_rotate.c			\
		./src/swap.c					\
		./src/verify_args.c				\
		./src/panic.c					\
		./src/algorithm.c				\
		./src/index.c					\
		./src/push_swap.c				\
		./src/sorts.c					\
		./src/utils.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wextra -Werror -Wall -g #-fsanitize=address
CC = cc
AR = ar rc
RM = rm -f 

all: $(LIBFT_A) $(NAME) 
	$(CC) $(NAME) $(LIBFT_A) -o $(EXEC)
	
$(LIBFT_A):
	make -C libft

$(NAME): $(OBJ)
	$(AR) $(NAME) $(LIBFT_A) $(OBJ)	

clean: $(OBJ)
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean 
	make fclean -C libft
	$(RM) $(NAME) $(EXEC)

re: clean all