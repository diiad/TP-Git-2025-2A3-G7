FLAGS= -Wall -Werror -Wextra

game:
	gcc main.c output.c $(FLAGS) -o main
