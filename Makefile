all:
	cc -Wall -Wextra -Werror libft/*.c server.c the_rest.c -o server -g
	cc -Wall -Wextra -Werror libft/*.c client.c the_rest.c -o client -g

clean:
	rm server client
