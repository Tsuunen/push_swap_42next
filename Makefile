CC := cc
NAME := push_swap
BUILD_DIR := .build
LIBFT = libft/libft.a
INCLUDES = -Ilibft/includes -Iincludes
CFLAGS = -Werror -Wextra -Wall -MD $(INCLUDES)
MODE ?= release

VPATH = srcs
SRCS = main.c\
	   stack_operations.c\
	   stack_operations_utils.c\
	   sort_utils.c\
	   sort_utils_reverse.c\
	   stack_utils.c\
	   stack_complex_operations.c\
	   check_sort.c\
	   comp.c\
	   simple_sort.c\
	   medium_sort.c\
	   disorder.c\
	   complex_sort.c\
	   parser.c

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

CHECKER_SRCS = checker.c\
			   parser.c\
			   stack_operations.c\
			   stack_operations_utils.c\
			   stack_complex_operations.c\
			   check_sort.c\
			   comp.c

CHECKER_OBJS = $(addprefix $(BUILD_DIR)/, $(CHECKER_SRCS:.c=.o))
CHECKER_DEPS = $(CHECKER_OBJS:.o=.d)


ifeq ($(MODE), debug)
	CFLAGS += -g3
endif

all: libft $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

libft:
	$(MAKE) -C libft

bonus: checker

checker: $(BUILD_DIR) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o checker $(LIBFT)

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

-include $(DEPS)
