# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 08:59:31 by ede-lang          #+#    #+#              #
#    Updated: 2025/10/30 12:03:25 by ede-lang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

# Vérifie et définit HOSTTYPE si nécessaire
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME        = libft_malloc_$(HOSTTYPE).so
LINK_NAME   = libft_malloc.so

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -fPIC -I include -I libft/include -g
RM          = rm -f
AR          = ar rcs
MKDIR       = mkdir -p

# Dossiers
SRCS_DIR    = srcs
OBJS_DIR    = objs
LIBFT_DIR   = libft

# Fichiers sources
SRCS        = $(wildcard $(SRCS_DIR)/*.c)
OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME) $(LINK_NAME)

# Compilation de la lib partagée (malloc custom)
$(NAME): $(OBJS)
	@echo "→ Building $(NAME)"
	$(CC) $(CFLAGS) -shared -o $@ $^ -L$(LIBFT_DIR) -lft

# Lien symbolique vers la lib courante
$(LINK_NAME): $(NAME)
	@echo "→ Creating symlink $(LINK_NAME) → $(NAME)"
	@ln -sf $(PWD)/$(NAME) $(LINK_NAME)

# Règle générique pour les .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier objs si besoin
$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

# Compilation de la libft si besoin
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Test avec un main
test: all
	$(CC) $(CFLAGS) test_main.c -L. -lft_malloc -L$(LIBFT_DIR) -lft -o test_malloc

# Règle pour lancer le test avec preload
test_run: test
	LD_LIBRARY_PATH=$(PWD) ./test_malloc

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LINK_NAME) test_malloc

re: fclean all

.PHONY: all clean fclean re test test_run
