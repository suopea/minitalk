all:
	cc libft/*.c server.c -o server
	cc libft/*.c client.c -o client

clean:
	rm server client
