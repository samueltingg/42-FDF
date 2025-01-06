CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -fPIC
NAME = libft.a

SRCS = \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstlast.c
OBJS = $(SRCS:.c=.o)

# bonus
BONUS_SRCS = \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ft_printf
PRINTF_SRCS = $(addprefix ft_printf/srcs/, $(PRINTF_SRCS_FILE))
PRINTF_SRCS_FILE = \
			ft_printf.c \
			check_flags.c \
			digit_count_base.c \
			write_padding.c \
			ft_putnbr_base.c \
			ft_putnbr_long.c \
			print_char.c \
			print_str.c \
			print_ptr.c \
			print_uint.c \
			print_int.c \
			print_hex.c \

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
CFLAGS += -Ift_printf/
# ^so that ft_printf.h doesn't need to be in home directory

#changes
GNL_SRCS = $(addprefix get_next_line/, $(GNL_SRCS_FILE))
GNL_SRCS_FILE = \
				get_next_line.c \
				get_next_line_utils.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c  
GNL_OBJS = $(GNL_SRCS:.c=.o)
CFLAGS += -Iget_next_line/
			

all: $(NAME)

# $(NAME): $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
# 		ar -rc $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

$(NAME): $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
		@ar -rc $(NAME) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
# ^run bonus all the time

%.o:%.c
	@cc $(CFLAGS) -c $< -o $@

RM = rm -f

clean:
		@$(RM) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all
