# ar rcs $@ $^ is the recipe or command to build the target. 
# ar: Archive command used for creating static libraries.
# rcs: Options for ar:
#     r: Insert files into the archive.
#     c: Create the archive if it doesn't exist.
#     s: Write an index (symbol table) into the archive.
# $@: Automatic variable representing the target name
# $^: Automatic variable representing all the prerequisites(the object files)

# Standard
NAME :=	fdf

# Directories
LIBFT	:=	./libft/libft.a


# Compiler and Flags
CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
RM := /bin/rm -f
AR	:= ar rcs

# Rules

$(LIBFT):
			@make -C ./libft

all	: 		$(NAME)

$(NAME) :	$(OBJ) $(LIBFT)

clean:
			$(RM) -r $(OBJ_DIR)
			make clean -C ./libft

fclean :		clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)

re:				fclean all


# Phony targets represent non-file targets
.Phony				all clean fclean re


