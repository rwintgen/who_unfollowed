MAKEFLAGS	+=	--no-print-directory

NAME		=	who_unfollowed
HEADER		=	-I ./include

CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g

SRCDIR		=	./src
OBJDIR		=	./obj
INCDIR		=	./include

SRCS		=	$(SRCDIR)/main.c \
				$(SRCDIR)/exec/options.c \
				$(SRCDIR)/exec/compare.c \
				$(SRCDIR)/exec/quicksort.c \
				$(SRCDIR)/parsing/file.c \
				$(SRCDIR)/parsing/get_next_user.c \
				$(SRCDIR)/parsing/parse_infile.c \
				$(SRCDIR)/utils/file_utils.c \
				$(SRCDIR)/utils/free_close.c \
				$(SRCDIR)/utils/print_utils.c \

OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

GREEN		=	\033[0;32m
RED			=	\033[0;31m
NC			=	\033[0m

all			:	$(NAME)
				@echo "$(GREEN)who_unfollowed compiled$(NC)"

$(NAME)		:	$(OBJS)
				@clear
				@echo "             __                    ___     ____                  __  "
				@echo "     _    __/ /  ___    __ _____  / _/__  / / /__ _    _____ ___/ /  "
				@echo "    | |/|/ / _ \/ _ \  / // / _ \/ _/ _ \/ / / _ \ |/|/ / -_) _  /   "
				@echo "    |__,__/_//_/\___/__\_,_/_//_/_/ \___/_/_/\___/__,__/\__/\_,_/    "
				@echo "                   /___/                                             "
				@echo "                             by rwintgen                             "
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)who_unfollowed linked$(NC)"

$(OBJDIR)/%.o: %.c
				@mkdir -p $(@D)
				@$(CC) $(HEADER) $(CFLAGS) -c $< -o $@

clean		:
				@rm -rf $(OBJDIR)
				@echo "$(RED)object files deleted$(NC)"

fclean		:	clean
				@rm -f $(NAME)
				@echo "$(RED)executable deleted$(NC)"

re			:	fclean all

uninstall	:	fclean
				@echo "$(RED)uninstalling who_unfollowed...$(NC)"
				@rm -rf $(SRCDIR) $(INCDIR)
				@rm README.md Makefile
				@echo "$(RED)who_unfollowed uninstalled$(NC)"

.PHONY: all clean fclean re