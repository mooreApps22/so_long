NAME	= so_long
CC		= clang -Wall -Wextra -Werror -g
SRC		= $(wildcard src/*.c)
BONUS	= $(wildcard bonus/*c)
OBJ		= $(SRC:.c=.o)
B_OBJ	= $(BONUS:.c=.o)
HEADER	= libft/include/libft.h include/so_long.h
IFLAG	= -I./include
MLX		= -L./minilibx_linux -lmlx -lXext -lX11

LIBFT	= libft/libft.a

all: $(NAME) $(LIBFT)

$(LIBFT):
	@make -C libft/ all

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) $(MLX) $(IFLAG) -o $(NAME)

bonus: $(B_OBJ) $(LIBFT)
	@$(CC) $(B_OBJ) $(LIBFT) $(MLX) $(IFLAG) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(IFLAGS)

clean:
	@make -C ./libft clean
	@rm -f src/*.o
	@rm -f bonus/*.o
	@rm -f *.o

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all so_long clean fclean re libft
