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

#Directories
SRC_DIR			= src/
OBJ_DIR			= obj/

#Compiler and Flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIBFT = ./libs/libft/libft.a
MINILIBX = ./libs/mlx_linux/libmlx.a

#Source Files
SRCS				= 	$(SRC_DIR)main.c \
						$(SRC_DIR)iso_coordinates.c


# Creation of Object files for each source file
# OBJ := $(SRCS:%.c=%.o)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


#Rules
all: ${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(@D)
		${CC} ${CFLAGS} -I./libs/libft -I./libs/mlx_linux -c $? -o $@

# %.o: %.c
# 			@mkdir -p $(@D)
# 			${CC} ${CFLAGS} -I./libs/libft -I./libs/mlx_linux -c $? -o $@

${NAME}: ${OBJ}
		@make -C ./libs/libft
		@make -C ./libs/mlx_linux
#linux
		@${CC} ${CFLAGS} $^ -L./libs/libft -lft -L./libs/mlx_linux -lmlx -lXext -lX11 -lm -lz -o ${NAME}

libft:
		@make -C libs/libft

mlx_linux:
		@make -C libs/mlx_linux

clean:
		@make clean -C ./libs/libft
		@make clean -C ./libs/mlx_linux
		@${RM} ${OBJ}

fclean: clean
		@${RM} ${NAME}
		@${RM} ./libs/libft/libft.a
		@rm -rf ${OBJ_DIR} 

re: fclean all

.PHONY: all clean fclean re libft mlx_linux