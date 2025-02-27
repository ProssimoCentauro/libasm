#Variables
NAME = test_lib

SRCS_DIR = ./srcs/

C_SRC = $(SRCS_DIR)test_lib.c

S_SRCS = $(SRCS_DIR)ft_strlen.s $(SRCS_DIR)ft_strcpy.s \
	   $(SRCS_DIR)ft_strcmp.s $(SRCS_DIR)ft_write.s \
	   $(SRCS_DIR)ft_read.s \

S_OBJS = $(S_SRCS:.s=.o)

#Compilation
NASM = nasm -f elf64
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

test_lib:
	$(NASM) ./srcs/ft_strlen.s
	$(NASM) ./srcs/ft_strcpy.s
	$(NASM) ./srcs/ft_strcmp.s
	$(NASM) ./srcs/ft_write.s
	$(NASM) ./srcs/ft_read.s
	$(CC) $(CFLAGS) $(C_SRC) $(S_OBJS) -o test_lib

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(S_OBJS)

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME)

re: fclean all
