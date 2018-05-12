##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for bsq
##

CC		=	gcc
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h
LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	my_putstr.c		\
			my_puterror.c		\
			my_put_nbr.c		\
			my_putchar.c		\
			my_strncpy.c		\
			my_memset.c		\

LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
LDFLAGS		=	-L./$(LIB_DIR)
LIBFLAG		=	-l$(LIB_NAMEDIR)

NAME		=	bsq
MAIN		=	src/main.c
SRC		=	src/board.c		\
			src/square.c		\
			src/clean.c		\
			src/board_check.c	\
			src/square_info.c
		
OBJ		=	$(SRC:.c=.o)

#	Tests settings
TEST_NAME	=	unit_tests
TEST_SRC	=	#
			
			
			
TEST_FLAGS	=	--coverage -lcriterion

GDB_MAIN	=	src/main.c
GDB_NAME	=	gdb.out

.PHONY: tclean gclean fclean lclean lfclean

all:	lib $(NAME)

#	Library rules
lib:	libh liba

libh:
	@mkdir -p $(LIB_DIR)/$(HDPATH)
	cp $(LIB_HDS) $(HDPATH)

liba:	$(LIB_OBJ)
	ar rc $(LIB_DIR)/$(LIB_NAME) $^

libclean:
	$(RM) $(LIB_OBJ)

libfclean: libclean
	rm -rf $(LIB_DIR)/$(HDPATH)
	$(RM) $(LIB_DIR)/$(LIB_NAME)

libre: libfclean lib

#	Program rules
$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(SRC) $(LDFLAGS) $(LIBFLAG)

re: fclean all

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

#	Tests rules
gdb:	gclean
	$(DBCC) $(CFLAGS) -o $(GDB_NAME) $(GDB_MAIN) $(SRC) $(LIB_SRC)

gclean:
	$(RM) $(GDB_NAME)

testmake:
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(LDFLAGS)	\
		$(TEST_FLAGS) $(LIBFLAG)
	./$(TEST_NAME)

tests_run: lib testmake

tclean:
	$(RM) *.gc*
	$(RM) $(TEST_NAME)

cclean: tclean fclean libclean gclean libfclean
