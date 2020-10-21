CC=gcc -g -Wall -Wextra -Werror -pedantic

%:
	clear
	$(CC) $(files)
	./a.out
	betty-style $(files)
	betty-doc $(files)

%: files=$*-*.c tests/$*-main.c print_array.c
1: files=$*-*.c tests/$*-main.c print_list.c
101: files=$*-*.c tests/$*-main.c print_list.c
