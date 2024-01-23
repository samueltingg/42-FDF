CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 
# -fsanitize=address -g
INCLUDES = -I ./includes/ -I$(LIBFT_DIR) -I$(MINILIBX_DIR) 

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRCDIR = srcs/
SRCS_FIL = \
			main.c

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

# library
LIBFT_DIR = libft/
LIBFT.A = $(LIBFT_DIR)libft.a
MINILIBX_DIR = minilibx/
LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit 

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
# -lm
# "-lm" to link to math library

RM = rm -rf

clean:
		@ $(RM) $(OBJDIR) && echo "$(RED) object files were deleted$(RESET)"
		@make clean -C ${LIBFT_DIR} && echo "$(RED) libft object files were deleted$(RESET)"
		@make clean -C ${MINILIBX_DIR} && echo "$(RED)ran make clean in $(MINILIBX_DIR)$(RESET)"


fclean: clean
		@$(RM) $(NAME) && echo "$(RED)$(NAME) was deleted$(RESET)"
		@make fclean -C $(LIBFT_DIR) && echo "$(RED)libft.a was deleted$(RESET)"

re: fclean all


.PHONY: all clean fclean re bonus
