# Variables
NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# Source and object files for server
SRCS_SERVER = server.c server_utils.c server_global.c ft_memcpy.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
HEADER_SERVER = server.h

# Source and object files for client
SRCS_CLIENT = client.c client_utils.c client_global.c ft_atoi.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
HEADER_CLIENT = client.h

# Targets
.PHONY: all clean fclean re

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

# Pattern rules for object file compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

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
