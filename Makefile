NAME = libftprintf.a
OBJ_DIR = ./obj/
SRC_LIBFT_DIR = ./libft/
SRC_PF_DIR = ./src/
SRC_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_putchar.c ft_putstr.c ft_isupper.c ft_islower.c ft_tabfree.c \
			ft_ctoi.c
SRC_PF = ft_printf.c \
			ft_get_integer.c \
			ft_put_utils.c \
			ft_parse_format.c \
			ft_put_argument.c \
			ft_put_percentage.c \
			ft_put_character.c \
			ft_put_string.c \
			ft_put_pointer.c \
			ft_put_integer.c

OBJ_LIBFT = $(addprefix $(OBJ_DIR),$(SRC_LIBFT:%.c=%.o))
OBJ_PF = $(addprefix $(OBJ_DIR),$(SRC_PF:%.c=%.o))
OBJ = $(OBJ_LIBFT) $(OBJ_PF)
HEADERS = includes/*.h
HEADERS_DIR = includes
FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_LIBFT_DIR)%.c $(HEADERS)
	gcc $(FLAGS) -o $@ -c $< -I $(HEADERS_DIR)

$(OBJ_DIR)%.o: $(SRC_PF_DIR)%.c $(HEADERS)
	gcc $(FLAGS) -o $@ -c $< -I $(HEADERS_DIR)

bonus: $(NAME)

run: a.out
	./a.out

a.out: $(NAME) main.c
	gcc $(FLAGS) main.c -L . -lftprintf -I $(HEADERS_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re run
