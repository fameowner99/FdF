NAME = fdf

LIB_DIR = ./libft/

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC = alg_bresenham \
	change_color \
	connecting_lines \
	fdf \
	ft_image \
	main \
	move_map \
	read_map \
	rotate \
	zoom \
	read_map2


CFILES = $(patsubst %, %.c, $(SRC))

OFILES = $(patsubst %, %.o, $(SRC))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	gcc -Wall -Wextra -Werror -c  $(CFILES) $(MLX_FLAGS)
	gcc -Wall -Wextra -Werror -g $(OFILES)  $(LIB) -o $(NAME)  -I minilibx_macos \
	-L minilibx_macos -lmlx -framework OpenGL -framework AppKit
clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OFILES)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)
re : fclean all

.PHONY: all clean fclean re
