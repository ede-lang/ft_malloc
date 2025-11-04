# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 15:31:55 by ede-lang          #+#    #+#              #
#    Updated: 2024/03/12 14:22:08 by ede-lang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	:= \033[0m
RED		:= \033[1;31m
GREEN	:= \033[1;32m
YELLOW	:= \033[1;33m
CYAN	:= \033[1;36m

SRCS    = char/ft_atoi_base.c \
		char/ft_atoi.c \
		char/ft_atol.c \
		char/ft_isalnum.c \
		char/ft_isalpha.c \
		char/ft_isascii.c \
		char/ft_isdigit.c \
		char/ft_isprint.c \
		char/ft_itoa.c \
		char/ft_tolower.c \
		char/ft_toupper.c \
		ft_lst/ft_lstadd_back.c \
		ft_lst/ft_lstadd_front.c \
		ft_lst/ft_lstclear.c \
		ft_lst/ft_lstdelone.c \
		ft_lst/ft_lstiter.c \
		ft_lst/ft_lstlast.c \
		ft_lst/ft_lstmap.c \
		ft_lst/ft_lstnew.c \
		ft_lst/ft_lstsize.c \
		ft_mem/ft_bzero.c \
		ft_mem/ft_calloc.c \
		ft_mem/ft_memchr.c \
		ft_mem/ft_memcmp.c \
		ft_mem/ft_memcpy.c \
		ft_mem/ft_memmove.c \
		ft_mem/ft_memset.c \
		ft_printf/ft_printf.c \
		ft_put/ft_putadr.c \
		ft_put/ft_putchar_fd.c \
		ft_put/ft_putchar.c \
		ft_put/ft_putendl_fd.c \
		ft_put/ft_putnbr_fd.c \
		ft_put/ft_putnbr_hexa.c \
		ft_put/ft_putnbr.c \
		ft_put/ft_putstr_fd.c \
		ft_put/ft_putstr.c \
		ft_put/ft_putunbr.c \
		ft_str/ft_split.c \
		ft_str/ft_strchr.c \
		ft_str/ft_strcmp.c \
		ft_str/ft_strdup.c \
		ft_str/ft_striteri.c \
		ft_str/ft_strjoin.c \
		ft_str/ft_strlcat.c \
		ft_str/ft_strlcpy.c \
		ft_str/ft_strlen.c \
		ft_str/ft_strmapi.c \
		ft_str/ft_strncmp.c \
		ft_str/ft_strnstr.c \
		ft_str/ft_strrchr.c \
		ft_str/ft_strrep.c \
		ft_str/ft_strtrim.c \
		ft_str/ft_substr.c \
		gnl/get_next_line.c

OBJDIR	= obj

OBJS    = ${SRCS:%.c=$(OBJDIR)/%.o}

NAME    = libft.a

CC  = clang

AR	= ar rcs

CFLAGS  = -Wall -Wextra -Werror

RM  = rm -rf

$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation $(RESET)of $(YELLOW)$(NAME) $(RESET)..."
	@$(AR) $(NAME) $(OBJS)
	@echo "$(YELLOW)$(NAME) $(GREEN)created[0m ✔️"

$(OBJDIR)/%.o: %.c
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	@test -d $(OBJDIR)/char || mkdir $(OBJDIR)/char
	@test -d $(OBJDIR)/ft_lst || mkdir $(OBJDIR)/ft_lst
	@test -d $(OBJDIR)/ft_mem || mkdir $(OBJDIR)/ft_mem
	@test -d $(OBJDIR)/ft_printf || mkdir $(OBJDIR)/ft_printf
	@test -d $(OBJDIR)/ft_put || mkdir $(OBJDIR)/ft_put
	@test -d $(OBJDIR)/ft_str || mkdir $(OBJDIR)/ft_str
	@test -d $(OBJDIR)/gnl || mkdir $(OBJDIR)/gnl
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all:		${NAME}

clean:
		@${RM} $(OBJDIR)
		@echo "$(GREEN)Remove $(YELLOW)$(OBJDIR)$(RESET)[0m ✔️"

fclean:		clean
		@rm -f ${NAME}
		@echo "$(GREEN)Remove $(YELLOW)${NAME}$(RESET)[0m ✔️"


re:			fclean all

.PHONY: all clean fclean re bonus