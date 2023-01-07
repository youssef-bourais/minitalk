SRC = server.c client.c tools.c
SRC_BONUS = server_bonus.c client_bonus.c tools_bonus.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all:server client
bonus:server_bonus client_bonus

client:$(OBJ)
	cc $(CFLAGS) client.o tools.o -o client 
server:$(OBJ)
	cc $(CFLAGS) server.o tools.o -o server
client_bonus:$(OBJ_BONUS)
	cc $(CFLAGS) client_bonus.o tools_bonus.o -o client_bonus
server_bonus:$(OBJ_BONUS)
	cc $(CFLAGS) server_bonus.o tools_bonus.o -o server_bonus

%.o:%.c
	cc $(CFLAGS) $^ -c

clean:
	rm -f $(OBJ)
clean_bonus:
	rm -f $(OBJ_BONUS)

fclean:clean
	rm -f server client
fclean_bonus:clean_bonus
	rm -f server_bonus client_bonus

re:fclean server client
re_bonus:fclean_bonus server_bonus client_bonus
