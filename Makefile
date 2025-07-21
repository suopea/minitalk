all:
	cc libft/*.c server.c signals.c -o server -g
	cc libft/*.c client.c signals.c -o client -g

clean:
	rm server client
