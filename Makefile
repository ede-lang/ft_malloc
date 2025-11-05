# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 16:39:11 by ede-lang          #+#    #+#              #
#    Updated: 2025/11/05 11:11:45 by ede-lang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Vérifie et définit HOSTTYPE si nécessaire
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME        = libft_malloc_$(HOSTTYPE).so
LINK_NAME   = libft_malloc.so

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -fPIC -I include -I libft/include -g
TESTFLAG    = -fPIC -I include -I libft/include -g
RM          = rm -rf
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
	@echo "→ Building libft first"
	$(MAKE) -C $(LIBFT_DIR)
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

# **************************************************************************** #
#                               TEST / RUN RULES                               #
# **************************************************************************** #

# Test avec un main
test: all
	$(CC) $(TESTFLAG) test_main.c -L. -lft_malloc -L$(LIBFT_DIR) -lft -o test_malloc

# Règle pour lancer le test avec preload
test_run: test
	LD_LIBRARY_PATH=$(PWD) ./test_malloc

# **************************************************************************** #
#                               CLEANING RULES                                 #
# **************************************************************************** #

clean:
	@echo "→ Cleaning malloc objects"
	$(RM) $(OBJS_DIR)
	@echo "→ Cleaning libft"
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "→ Removing malloc shared lib and symlink"
	$(RM) $(NAME) $(LINK_NAME) test_malloc
	@echo "→ Full cleaning libft"
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test test_run
