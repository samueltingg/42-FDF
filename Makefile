CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99  
# -fsanitize=address -g
INCLUDES = -I ./includes/ -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m
# SRCS
SRCDIR = srcs/
SRCS_FIL = \
			main.c \
			render.c \
			bresenham.c \
			parsing.c \
			ft_atoi_base.c \
			transformation_matrix.c \
			transformation_2d.c \
			handle_key_event.c \
			transformation_utils.c \
			gradient.c \
			split_4_view_bonus.c \
			free.c \
			print_grid.c  # temporary

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

# OBS
OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

# LIBRARIES
LIBFT_DIR = libft/
LIBFT.A = $(LIBFT_DIR)libft.a

# Set MINILIBX_DIR based on the operating system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)  # macOS
    MINILIBX_DIR = minilibx/
	LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
else ifeq ($(UNAME_S), Linux)  # Linux
    MINILIBX_DIR = minilibx-linux/
	LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else
    $(error Unsupported operating system)
endif

NAME = fdf

all:  $(OBJDIR) $(NAME)

$(OBJDIR):
		@mkdir -p $(OBJDIR) && echo "$(GREEN)$(OBJDIR) was created$(RESET)"

$(NAME): $(OBJS)
		@make -C $(LIBFT_DIR)
		@make -C $(MINILIBX_DIR)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES) && echo "$(GREEN)$(NAME) was created$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) && echo "$(GREEN)object files were created$(RESET)"


RM = rm -rf

clean:
		@ $(RM) $(OBJDIR) && echo "$(ORANGE) object files were deleted$(RESET)"
		@make clean -C ${LIBFT_DIR} && echo "$(ORANGE) libft object files were deleted$(RESET)"
		@make clean -C ${MINILIBX_DIR} && echo "$(ORANGE)ran make clean in $(MINILIBX_DIR)$(RESET)"


fclean: clean
		@$(RM) $(NAME) && echo "$(ORANGE)$(NAME) was deleted$(RESET)"
		@make fclean -C $(LIBFT_DIR) && echo "$(ORANGE)libft.a was deleted$(RESET)"

re: fclean all


.PHONY: all clean fclean re bonus
# ^ .PHONY -> informs computer that above phrases are not files

