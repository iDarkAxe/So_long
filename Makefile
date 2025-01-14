.PHONY : all clean fclean re bonus clean-lib clean-bin clean-obj debug debug-cc debug-print
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPENDANCIES = -MMD -MP
NO_DIR = --no-print-directory
MAKE := $(MAKE) -j $(NO_DIR)
NAME = so_long

# Debugging flags
CFLAGS_DEBUG = -Wall -Wextra -g3 -D DEBUG=1
CC_DEBUG = clang
CC_DEBUG_CFLAGS = -g3 -D DEBUG=1 -Weverything -Wno-padded -pedantic -O2 -Wwrite-strings -Wconversion -Wno-incompatible-pointer-types-discards-qualifiers -fsanitize=address -fsanitize=leak
#############################################################################################
#                                                                                           #
#                                         DIRECTORIES                                       #
#                                                                                           #
#############################################################################################
# Source directories
P_SRC = src/
P_DRAW = draw/
P_MAP_VERIF = map_verif/
P_UTILS = utils/
P_PRINT = print/

# Object directories
P_OBJ = .obj/

# Header directories
P_INC = inc/
P_INC_MLX = inc_mlx/

# Libraries directories
P_LIB = lib/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################
# Headers
INC = \
	keys.h \
	mlx.h \
	so_long.h \
	ft_print.h

INC_MLX = \
	mlx.h \
	X.h

# Source files
SRC = \
	so_long.c \
	ft_settings.c \
	ft_hooks.c \

DRAW = \
	ft_draw.c \
	ft_draw_map.c

MAP_VERIF = \
	ft_map_dimensions.c \
	ft_map_fill.c

UTILS = \
	ft_map_utils.c \
	ft_random.c

PRINT = \
	ft_print.c \
	ft_print_special.c

LIBS = \
	libmlx_Linux.a \
	libso_long.a

#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS =	\
	$(addprefix $(P_SRC), $(SRC)) \
	$(addprefix $(P_SRC)$(P_DRAW), $(DRAW)) \
	$(addprefix $(P_SRC)$(P_MAP_VERIF), $(MAP_VERIF)) \
	$(addprefix $(P_SRC)$(P_UTILS), $(UTILS)) \
	$(addprefix $(P_SRC)$(P_PRINT), $(PRINT))

# List of object files (redirect to P_OBJ)
OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o))
P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS))

# List of depedencies
DEPS = $(OBJS:%.o=%.d)

# List of header files
INCS = \
	$(addprefix $(P_INC), $(INC)) \
	$(addprefix $(P_INC_MLX), $(INC_MLX))

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all: 
	@$(MAKE) $(NAME)

# Create so_long executable
$(NAME): $(P_OBJ)main.o $(P_LIB)libso_long.a $(P_LIB)libmlx_Linux.a
	$(CC) $(CFLAGS) $(DEPENDANCIES) $(DEBUG_STATE) -I $(P_INC) -I $(P_INC_MLX) -o $(NAME) $< -L$(P_LIB) -lso_long -lmlx_Linux -lXext -lX11

# Create library used to create so_long executable
$(P_LIB)libso_long.a: $(OBJS)
	@mkdir -p $(P_LIB)
	ar -rcs $(P_LIB)libso_long.a $^

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPENDANCIES) $(DEBUG_STATE) -I $(P_INC) -I $(P_INC_MLX) -c $< -o $@

# Create mlx library
$(P_LIB)libmlx_Linux.a:
	@mkdir -p $(P_LIB)
	@$(MAKE) -C minilibx-linux
	@cp minilibx-linux/libmlx_Linux.a $(P_LIB)

#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	rm -rfd $(P_OBJ)

clean-lib:
	rm -rfd $(P_LIB)

clean-bin:
	rm -f $(NAME)
	rm -f checker

clean-obj:
	@$(MAKE) clean

fclean:
	@$(MAKE) clean-obj
	@$(MAKE) clean-lib
	@$(MAKE) clean-bin

re:
	@$(MAKE) fclean
	@$(MAKE) all

# Aliases
clear: clean
fclear: fclean
flcean: fclean
flcear: fclean

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging rules
debug:
	@$(MAKE) $(NAME) CFLAGS="$(CFLAGS_DEBUG)"

debug-checker:
	@$(MAKE) checker CFLAGS="$(CFLAGS_DEBUG)"

debug-cc:
	@$(MAKE) $(NAME) CFLAGS="$(CC_DEBUG_CFLAGS)" CC="$(CC_DEBUG)"

# Debugging print
debug-print:
	@$(MAKE) debug-print-project

debug-print-separator:
	@echo ""
	@echo "$(On_Yellow)____________________$(Color_Off)"
	@echo ""

debug-print-project:
	@echo "$(Red)Project:\n\t$(Blue)$(NAME)$(Color_Off)"
	@echo ""
	@echo "$(Red)SRCS:\n\t$(Blue)$(SRCS)$(Color_Off)"
	@echo ""
	@echo "$(Red)OBJS:\n\t$(Blue)$(OBJS)$(Color_Off)"
	@echo ""
	@echo "$(Red)INCS:\n\t$(Blue)$(INCS)$(Color_Off)"
	@echo ""
	@echo "$(Red)LIBS:\n\t$(Blue)$(LIBS)$(Color_Off)"

#############################################################################################
#                                                                                           #
#                                         COSMETIC                                          #
#                                                                                           #
#############################################################################################
# Reset
Color_Off=\033[0m	# Text Reset

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

-include $(DEPS)% 