# ar rcs $@ $^ is the recipe or command to build the target. 
# ar: Archive command used for creating static libraries.
# rcs: Options for ar:
#     r: Insert files into the archive.
#     c: Create the archive if it doesn't exist.
#     s: Write an index (symbol table) into the archive.
# $@: Automatic variable representing the target name
# $^: Automatic variable representing all the prerequisites(the object files)

# Standard
NAME 				= fdf

# Directories
LIBFT				= ./libs/libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFLAGS
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I
RM 					= rm -f

# Source Files
OPERATIONS_DIR		= 	$(SRC_DIR)main.c

# Concatenate all source files
SRCS				= $(OPERATIONS_DIR)

# Creation of object files for each source file
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Rules
start:
					@make all

$(LIBFT):
					@make -C ./libs/libft

all:				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					$(RM) -r $(OBJ_DIR)
					make clean -C ./libs/libft

fclean : 			clean
					$(RM) $(NAME)
					$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent non-file targets
.PHONY: 			start all clean fclean re
