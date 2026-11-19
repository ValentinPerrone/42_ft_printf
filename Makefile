FILENAME := libftprintf.a
BONUS_MARKER := .bonus
FLAGS := -Wall -Wextra -Werror -I.
SRCS:=	ft_caster.c\
		ft_twrite.c\
		ft_printf.c\
		ft_abs_val.c\
		ft_printer.c\
		ft_arg_number.c\
		ft_null_check.c\
		ft_c_assigner.c\
		libft_functions/ft_atoi.c\
		libft_functions/ft_itoa.c\
		libft_functions/ft_utoa.c\
		libft_functions/ft_bzero.c\
		libft_functions/ft_hextoa.c\
		libft_functions/ft_strchr.c\
		libft_functions/ft_strlen.c\
		libft_functions/ft_isalpha.c\
		libft_functions/ft_isdigit.c\
		libft_functions/ft_voidtoa.c\
		libft_functions/ft_print_char.c\
		libft_functions/ft_toupper_string.c
SRCS_BONUS :=	ft_caster.c\
				ft_twrite.c\
				ft_abs_val.c\
				ft_printer.c\
				ft_arg_number.c\
				ft_null_check.c\
				ft_c_assigner.c\
				ft_printf_bonus.c\
				ft_printf_bonus/ft_dot_bonus.c\
				ft_printf_bonus/ft_0_pr_bonus.c\
				ft_printf_bonus/ft_pl_al_bonus.c\
				ft_printf_bonus/ft_sp_al_bonus.c\
				ft_printf_bonus/ft_0_padd_bonus.c\
				ft_printf_bonus/ft_l_just_bonus.c\
				ft_printf_bonus/ft_hash_flag_bonus.c\
				ft_printf_bonus/ft_flag_checker_bonus.c\
				ft_printf_bonus/ft_flag_override_bonus.c\
				libft_functions/ft_atoi.c\
				libft_functions/ft_itoa.c\
				libft_functions/ft_utoa.c\
				libft_functions/ft_bzero.c\
				libft_functions/ft_hextoa.c\
				libft_functions/ft_strchr.c\
				libft_functions/ft_strlen.c\
				libft_functions/ft_isalpha.c\
				libft_functions/ft_isdigit.c\
				libft_functions/ft_voidtoa.c\
				libft_functions/ft_print_char.c\
				libft_functions/ft_toupper_string.c
HEADER := ft_printf.h
OBJ := $(SRCS:.c=.o)
OBJ_BONUS := $(SRCS_BONUS:.c=.o)
GREEN := \033[32m
YELLOW := \033[33m
WHITE := \033[0m

all: fclean $(FILENAME)
bonus: fclean $(BONUS_MARKER)
$(FILENAME): $(OBJ) 
	@ar -rcs $@ $^; 
	@echo "$(GREEN)\n=============================================================================$(WHITE)"
	@echo "$(GREEN)|                $(YELLOW)$(FILENAME) (bonus) compiled successfully!$(GREEN)               |$(WHITE)"
	@echo "$(GREEN)=============================================================================\n$(WHITE)"
$(BONUS_MARKER): $(OBJ_BONUS)
	@ar -rcs $(FILENAME) $(OBJ_BONUS)
	@touch $(BONUS_MARKER)
	@echo "$(GREEN)\n=============================================================================$(WHITE)"
	@echo "$(GREEN)|                    $(YELLOW)$(FILENAME) compiled successfully!$(GREEN)                   |$(WHITE)"
	@echo "$(GREEN)=============================================================================\n$(WHITE)"
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
	@for obj in $(OBJ_BONUS); do \
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