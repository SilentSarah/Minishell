NAME = libft.a

FT_MALLOC = ft_malloc.a

all : $(NAME)

CC = cc

CFLAGS := -Wall -Wextra -Werror

SRC =  \
 ./ft_memset.c \
 ./ft_bzero.c \
 ./ft_memcpy.c \
 ./ft_memmove.c \
 ./ft_memchr.c \
 ./ft_memcmp.c \
 ./ft_calloc.c \
 ./ft_strlen.c \
 ./ft_strlcpy.c \
 ./ft_strlcat.c \
 ./ft_strchr.c \
 ./ft_strrchr.c \
 ./ft_strncmp.c \
 ./ft_strnstr.c \
 ./ft_strdup.c \
 ./ft_isdigit.c \
 ./ft_atoi.c \
 ./ft_isalpha.c \
 ./ft_isalnum.c \
 ./ft_isascii.c \
 ./ft_isprint.c \
 ./ft_toupper.c \
 ./ft_tolower.c \
 ./ft_substr.c \
 ./ft_strjoin.c \
 ./ft_strtrim.c \
 ./ft_split.c \
 ./ft_itoa.c \
 ./ft_strmapi.c \
 ./ft_striteri.c \
 ./ft_putchar_fd.c \
 ./ft_putstr_fd.c \
 ./ft_putendl_fd.c \
 ./ft_putnbr_fd.c \
 ./is_space.c \
 ./is_empty.c \
 ./ft_lstnew.c \
 ./ft_lstadd_front.c \
 ./ft_lstsize.c \
 ./ft_lstlast.c \
 ./ft_lstadd_back.c \
 ./ft_lstdelone.c \
 ./ft_lstclear.c \
 ./s_strjoin.c \
 ./ft_strcmp.c \
 ./_strlen.c \
 ./ms_reset.c

 SRC_MALLOC_OBJ = $(addprefix ../ft_malloc/, ft_malloc.o misc_functions.o misc_functions2.o)

OBJECTS = $(SRC:.c=.o)

ft_malloc:
	@make -C ../ft_malloc

$(NAME) : ft_malloc $(OBJECTS) $(SRC_MALLOC_OBJ)
	@ar -rcs $(NAME) $(OBJECTS) $(SRC_MALLOC_OBJ)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJECTS) $(SRC_MALLOC_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re