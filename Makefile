##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##

ROOT	=		.

SRC_DIR	=		sources

CC	=		gcc

NAME	=		libmalloc.so

REAL	=		$(ROOT)/build

SRC	=		$(SRC_DIR)/malloc.c	\
			$(SRC_DIR)/calloc.c	\
			$(SRC_DIR)/free.c	\
			$(SRC_DIR)/realloc.c	\
			$(SRC_DIR)/utils.c

WARN	=		-W -Wall -Wextra

CFLAGS	=		-I $(ROOT)/includes $(WARN) -fPIC

LDFLAGS	=		-L $(ROOT)/libraries/ -shared

LIB	?=		1

TEST	?=		0

DEB	?=      	0

G	=		-g

V	?=		@

OBJS	=		$(patsubst $(SRC_DIR)/%.c, $(REAL)/%.o, $(SRC))

#COLOR

GREEN	=		\e[1;32m

WHITE	=		\e[0m

ORANGE	=		\e[1;33m

RED	=		\e[1;35m

BLUE	=		\e[1;34m

debug:			CFLAGS += $(G)

all:			$(NAME)

$(NAME):		$(REAL)/$(NAME)
			$(V)cp $(REAL)/$(NAME) $(ROOT)
			$(V)$(CC) -o ./test $(SRC_DIR)/main.c -g
			$(V)printf "$(GREEN)Dup $(NAME) into root directory.$(WHITE)\n"

debug:			fclean echo_d $(NAME)

$(REAL)/$(NAME):	$(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)$(CC) -o $(REAL)/$(NAME) $(OBJS) $(LDFLAGS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(REAL)/%.o:		$(SRC_DIR)/%.c
			$(V)mkdir -p $(dir $@)
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
			$(V)rm -rf $(OBJS)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:			clean
			$(V)rm -f $(REAL)/$(NAME)
			$(V)rm -f test
			$(V)rm -f $(ROOT)/$(NAME)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:			fclean
			$(V)make --no-print-directory all

echo_build:
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
			$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

.PHONY: clean fclean debug all re echo_debug buildrepo
