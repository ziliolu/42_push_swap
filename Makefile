NAME = push_swap.a
EXEC = p

SRC =	./src/main.c					\
		./src/destroy.c					\
		./src/init_structs.c			\
		./src/print_stack.c				\
		./src/push.c					\
		./src/rotate.c					\
		./src/reverse_rotate.c			\
		./src/swap.c					\
		./src/verify_args.c				\
		./src/panic.c					\
		./src/verify_two_elements.c		\
		./src/utils.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wextra -Werror -Wall -g
CC = cc
AR = ar rc
RM = rm -f 

all: $(NAME)
	$(CC) $(NAME) -o $(EXEC)
	
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)	

clean: $(OBJ)
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME) $(EXEC)