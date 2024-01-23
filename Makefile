CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 
# -fsanitize=address -g
INCS = -I ./includes/

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

# # bonus
# BONUS_SRCS_FIL =  

# # ^ last line for source files can't end with '\'
# BONUS_SRCS = $(addprefix $(SRCDIR), $(BONUS_SRCS_FIL))
# BONUS_OBJS = $(addprefix $(OBJDIR), $(notdir $(BONUS_SRCS:.c=.o)))


# library
LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = fdf

all:  $(OBJDIR) $(NAME)

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft
#  -Lmlx -lmlx -framework OpenGL -framework AppKit 

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS) 
# -Imlx
# -lm
# "-lm" to link to math library

RM = rm -rf

clean:
		@ $(RM) $(OBJDIR)
		@make clean -C ${LIBFTDIR} && echo "$(RED)object files were deleted$(RESET)"

fclean: clean
		@$(RM) $(NAME) && echo "$(RED)$(NAME) was deleted$(RESET)"
		@make fclean -C $(LIBFTDIR) && echo "$(RED)libft.a was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
