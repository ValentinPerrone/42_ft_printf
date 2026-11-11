FILENAME := libftprintf.a
FLAGS := -Wall -Wextra -Werror -I.
SRCS := ft_abs_val.c ft_arg_number.c ft_caster.c ft_flag_checker.c ft_printf.c ft_terminal_write.c helper_functions/ft_c_assigner.c helper_functions/ft_dot_precison.c helper_functions/ft_flag_override.c helper_functions/ft_hash_flag.c helper_functions/ft_left_justification.c helper_functions/ft_null_check.c helper_functions/ft_plus_alignment.c helper_functions/ft_printer.c helper_functions/ft_space_alignment.c helper_functions/ft_zero_padding.c helper_functions/ft_zero_printing.c libft_functions/ft_atoi.c libft_functions/ft_bzero.c libft_functions/ft_hextoa.c libft_functions/ft_isalpha.c libft_functions/ft_isdigit.c libft_functions/ft_itoa.c libft_functions/ft_print_char.c libft_functions/ft_strchr.c libft_functions/ft_strlen.c libft_functions/ft_toupper_string.c libft_functions/ft_utoa.c libft_functions/ft_voidtoa.c
HEADER := ft_printf.h
OBJ := $(SRCS:.c=.o)
GREEN := \033[32m
YELLOW := \033[33m
WHITE := \033[0m

all: $(FILENAME)
bonus: $(FILENAME)
$(FILENAME): $(OBJ) 
	@ar -scr $@ -o $^
	@echo "$(GREEN)\n=====================================================================$(WHITE)"
	@echo "$(GREEN)|                $(YELLOW)$(FILENAME) compiled successfully!$(GREEN)               |$(WHITE)"
	@echo "$(GREEN)=====================================================================\n$(WHITE)"
%.o: %.c
	@printf "\tCompiling:\t%-18s -> %s\n" "$<" "$@"
	@cc $(FLAGS) -c $^ -o $@
clean:
	@for obj in $(OBJ); do \
		if [ -f "$$obj" ]; then \
			printf "\tRemoving:\t%s\n" "$$obj"; \
			rm -f "$$obj"; \
		fi; \
	done
fclean: clean
	@for FILENAME in $(FILENAME); do \
		if [ -f "$$FILENAME" ]; then \
			printf "\tRemoving:\t%s\n" "$$FILENAME"; \
			rm -f "$$FILENAME"; \
		fi; \
	done
	@echo "$(GREEN)\n=====================================================================$(WHITE)"
	@echo "$(GREEN)|                $(YELLOW).o and .a files removed successfully!$(GREEN)              |$(WHITE)"
	@echo "$(GREEN)=====================================================================\n$(WHITE)"
re: fclean all

.PHONY : all clean fclean re