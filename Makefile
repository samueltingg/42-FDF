CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 
# -fsanitize=address -g
INCS = -I ./includes/

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

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS) 
# -lm
# "-lm" to link to math library

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(NAME) 
		make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus
