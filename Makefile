NAME		= push_swap
NAME2		= checker

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
PM			=
INC_FLAGS	= -I inc

# Useful debugging flags
DEBUG		= #-g -fsanitize=address

# Cosmetics Section:
BLUE		= \033[38;2;39;147;255m
ORANGE		= \033[38;2;255;147;39m
PURP		= \033[38;2;147;39;255m
GRAY		= \033[38;5;243m

BOLD		= \033[1m
NO_COLOR    = \033[m
# End Cosmetics.

# Add header files here: (use full relative path to Makefile)
HEADERS		= push_swap.h \
			  checker.h \
			  common.h \

INC			= $(addprefix inc/, $(HEADERS))

# Add source files here: (files assumed to be in ./src folder)
FILES-P		= push_swap.c \
			  stack_sort.c \
			  final_pass.c \

FILES-C		= checker.c \

FILES-S		= lib_functions.c \
			  print_functions.c \
			  quick_sort.c \
			  dispatcher.c \
			  stack_functions.c \
			  instruction_list.c \

SRC-S		= $(addprefix src/, $(FILES-S))
SRC-P		= $(addprefix src/push/, $(FILES-P))
SRC-C		= $(addprefix src/check/, $(FILES-C))
SRC			= $(SRC-P) $(SRC-C) $(SRC-S)
OBJ			= $(addprefix obj/push/, $(FILES-P:.c=.o))
OBJ			+= $(addprefix obj/check/, $(FILES-C:.c=.o))
OBJ			+= $(addprefix obj/, $(FILES-S:.c=.o))

# ---------------------------------------------------------------------------- #

all: $(OBJ) $(NAME) $(NAME2)

$(NAME2): $(OBJ) $(INC)
	@printf "%b" "$(BOLD)$(PURP)Compiling: $(NO_COLOR)$(ORANGE)$@\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) $(PM) $(INC_FLAGS) -o $(NAME2) $(SRC-C) $(SRC-S) $(LIBS)

$(NAME): $(OBJ) $(INC)
	@printf "%b" "$(BOLD)$(PURP)Compiling: $(NO_COLOR)$(ORANGE)$@\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) $(PM) $(INC_FLAGS) -o $(NAME) $(SRC-P) $(SRC-S) $(LIBS)

obj:
	@printf "$(GRAY)Creating obj/ directory...$(NO_COLOR)\n"
	@mkdir obj/
	@mkdir -p obj/push
	@mkdir -p obj/check

obj/%.o: $(SRC) | obj
	@printf "%b" "$(BOLD)$(PURP)---: $(NO_COLOR)$(BLUE)$@\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(PM) $(INC_FLAGS) -c $< -o $@

clean:
	@printf "$(GRAY)Cleaning up $(ORANGE)$(NAME)$(GRAY)...$(NO_COLOR)\n"
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@printf "%b" "$(GREEN)$(NAME): Checking Norm...\n$(NO_COLOR)"
	@norminette $(SRC)
	@norminette $(INC)


.PHONY: clean fclean all re
