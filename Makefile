FILENAME := libftprintf.a
FLAGS := -Wall -Wextra -Werror -I.
SRCS := ft_printf.c
HEADER := libftprintf.h
OBJ := $(SRCS:.c=.o)
GREEN := \033[32m
YELLOW := \033[33m
WHITE := \033[0m

all: $(FILENAME)
$(FILENAME): $(OBJ) 
	@ar -scr $@ -o $^
	@echo "$(GREEN)\n================================================================$(WHITE)"
	@echo "$(GREEN)|                $(YELLOW)$(FILENAME) compiled successfully!$(GREEN)                |$(WHITE)"
	@echo "$(GREEN)================================================================\n$(WHITE)"
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
	@echo "$(GREEN)\n================================================================$(WHITE)"
	@echo "$(GREEN)|             $(YELLOW).o and .a files removed successfully!$(GREEN)            |$(WHITE)"
	@echo "$(GREEN)================================================================\n$(WHITE)"
re: fclean all

.PHONY : all clean fclean re