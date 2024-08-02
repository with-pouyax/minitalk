NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# Source and object files for server
SRCS_SERVER = server.c server_utils.c server_global.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
HEADER_SERVER = server.h

# Source and object files for client
SRCS_CLIENT = client.c client_utils.c client_global.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
HEADER_CLIENT = client.h

# Targets
all: $(FT_PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

# Build ft_printf library
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Server build rules
$(NAME_SERVER): $(OBJS_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(FT_PRINTF_LIB)

# Client build rules
$(NAME_CLIENT): $(OBJS_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(FT_PRINTF_LIB)

# Compilation rules
server.o: server.c $(HEADER_SERVER)
	$(CC) $(CFLAGS) -c server.c -o server.o

server_utils.o: server_utils.c $(HEADER_SERVER)
	$(CC) $(CFLAGS) -c server_utils.c -o server_utils.o

server_global.o: server_global.c $(HEADER_SERVER)
	$(CC) $(CFLAGS) -c server_global.c -o server_global.o

client.o: client.c $(HEADER_CLIENT)
	$(CC) $(CFLAGS) -c client.c -o client.o

client_utils.o: client_utils.c $(HEADER_CLIENT)
	$(CC) $(CFLAGS) -c client_utils.c -o client_utils.o

client_global.o: client_global.c $(HEADER_CLIENT)
	$(CC) $(CFLAGS) -c client_global.c -o client_global.o

# Clean up object files
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean up all files
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
