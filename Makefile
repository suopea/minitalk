all:
	cc -Wall -Wextra -Werror libft/*.c server.c signal_shared.c -o server -g
	cc -Wall -Wextra -Werror libft/*.c client.c signal_shared.c -o client -g

clean:
	rm server client
