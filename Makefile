#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: Data Structures														#\
#########################################################################################

NAME = $(BIN_DIR)data_structures.a

LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/bin/libft.a
CC	= cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	includes/
BIN_DIR =	bin/
SRC_DIR	=	src/

BTREE_DIR =		btree/
HTABLE_DIR =	hash_table/
QUEUE_DIR =		queue/
STACK_DIR =		stack/

BIN_DIRS	=	$(addprefix $(BIN_DIR), $(BTREE_DIR))		\
				$(addprefix $(BIN_DIR), $(HTABLE_DIR))		\
				$(addprefix $(BIN_DIR), $(QUEUE_DIR))		\
				$(addprefix $(BIN_DIR), $(STACK_DIR))		\

########################################################################################\
Sources & objects for Libft
########################################################################################

BTREE_FILES		=	btree					\
					btree_operations

HTABLE_FILES	=	hash_table				\
					hash_table_utils		\
					hash_table_management	\
					hash_table_collisions

QUEUE_FILES 	=	queue					\
					queue_operations		\
					queue_info				\
					queue_arithmetic

STACK_FILES 	=	stack					\
					stack_operations		\
					stack_info				\
					stack_arithmetic

FILES	=	$(addprefix $(BTREE_DIR), $(BTREE_FILES))	\
			$(addprefix $(HTABLE_DIR), $(HTABLE_FILES))	\
			$(addprefix $(QUEUE_DIR), $(QUEUE_FILES))	\
			$(addprefix $(STACK_DIR), $(STACK_FILES))
		
SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(BIN_DIR), $(addsuffix .o, $(FILES)))

########################################################################################\
Colors
########################################################################################

DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

########################################################################################\
Rules
########################################################################################

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(G)[DATA STRUCTURES] Library compiled!$(DEF_COLOR)-> $@\n"

$(BIN_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(BIN_DIRS)
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c $< -o $@

libft: $(LIBFT) 

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)[DATA STRUCTURES] All .o files removed$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)[DATA STRUCTURES] Library .a file removed$(DEF_COLOR)"

re: fclean all