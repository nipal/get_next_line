

all:
	rm -rf a.aout
	gcc -Wall -Wextra -Werror main_test.c get_next_line.c libft.a
