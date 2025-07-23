all:
	cc libft/*.c server.c signal_shared.c -o server -g
	cc libft/*.c client.c signal_shared.c -o client -g

clean:
	rm server client
