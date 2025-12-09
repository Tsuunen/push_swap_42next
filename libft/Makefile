CC := cc
INCLUDES := -Iincludes
CFLAGS := -Werror -Wextra -Wall -MD $(INCLUDES)
NAME := libft.a
BUILD_DIR := .build

VPATH := srcs/gnl:srcs/is:srcs/lst:srcs/mem:srcs/print:srcs/str:srcs/to
SRCS := ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isprint.c\
	   ft_isascii.c\
	   ft_isspace.c\
	   ft_strlen.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_lstnew.c\
	   ft_lstadd_front.c\
	   ft_lstsize.c\
	   ft_lstlast.c\
	   ft_lstadd_back.c\
	   ft_lstdelone.c\
	   ft_lstclear.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_realloc.c\
	   ft_printf.c\
	   printf_char.c\
	   printf_int.c\
	   printf_percent.c\
	   printf_pointer.c\
	   printf_string.c\
	   printf_uint.c\
	   printf_xint.c\
	   printf_Xint.c\
	   ft_itoa_base.c\
	   ft_ltoa_base.c\
	   ft_ultoa_base.c\
	   ft_utoa_base.c\
	   ft_utoa.c\
	   ft_strtol.c\
	   ft_strtoi.c\
	   ft_toabs.c

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
