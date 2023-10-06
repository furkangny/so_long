SRCS = source/main.c source/utils1.c source/utils2.c source/screen.c source/utils3.c source/event.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS = ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I./mlx -I./libft -I./ft_printf -I./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft
	make -C ./get_next_line
	make -C ./ft_printf
	make -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	make fclean -C ./get_next_line
	$(RM) $(NAME)

clean :
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./get_next_line
	make clean -C ./mlx
	$(RM) ./source/*.o

re : fclean all

.PHONY : all fclean clean re
