NAME = philo

SRC_DIR = sources

OBJ_DIR = .objs

SRC =	$(SRC_DIR)/threads_wrapper.c \
		$(SRC_DIR)/mutex_wrapper.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/error.c \
		$(SRC_DIR)/log.c \
		$(SRC_DIR)/atoi.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/dinning.c \
		$(SRC_DIR)/time.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra -Ofast #-fsanitize=address
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving philo\033[0m"

re: fclean all

.PHONY: all clean fclean re
