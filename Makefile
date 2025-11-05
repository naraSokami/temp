CC := gcc
FLAGS := -Wall -Wextra -Werror -no-pie #-D PRINT
# compile with -D PRINT to see visuals

NAME := push_swap
BONUS_NAME := checker

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

INCS_DIR := incs
SRCS_DIR := srcs
OBJS_DIR := objs
INCS_FILES := 	push_swap.h
SRCS_FILES :=	main.c \
				parsing.c \
				list.c \
				list_utils.c \
				list_find_elem.c \
				operations.c \
				btree.c \
				sort.c \
				push_swap.c

BONUS_INCS_FILES := bonus/push_swap_bonus.h
BONUS_SRCS_FILES :=	bonus/checker_bonus.c \
					bonus/parsing_bonus.c \
					bonus/list_bonus.c \
					bonus/operations_bonus.c \
					bonus/instructions_bonus.c \
					bonus/print_bonus.c

INCS := $(addprefix $(INCS_DIR)/,$(INCS_FILES))
SRCS := $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
OBJS := $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
BONUS_INCS := $(addprefix $(INCS_DIR)/,$(BONUS_INCS_FILES))
BONUS_SRCS := $(addprefix $(SRCS_DIR)/,$(BONUS_SRCS_FILES))
BONUS_OBJS := $(BONUS_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lft -L$(LIBFT_DIR) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -lft -L$(LIBFT_DIR) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCS_DIR) -I$(LIBFT_DIR)/incs

$(BONUS_OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/bonus
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCS_DIR)/bonus -I$(LIBFT_DIR)/incs

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
