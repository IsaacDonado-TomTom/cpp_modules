NAME = bureaucrats
SRCS =	main.cpp\
		Bureaucrat.cpp

HDRS = -I includes/
CPP_VERSION=-std=c++98
FLAGS = -Wall -Werror -Wextra
CC = clang++
HDRS = -I includes/

all: $(NAME)

$(NAME): $(SRCS)
	@ $(CC) $(CPP_VERSION) $(HDRS) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "\033[1m\033[32mSuccessfully Compiled\033[39m"

clean: 
	@rm -f $(NAME)
	@echo "\033[1m\033[33mCleaning Project Folder\033[39m"

fclean: clean
	@echo "\033[1m\033[31mSuper Cleaned Project Folder?\033[39m"

re: fclean all

.PHONY: all clean fclean re bereaucrats