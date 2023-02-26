NAME        :=	rubik

SRC_DIR     := 	src
OBJ_DIR     := 	obj
SRCS        := 	main.cpp \
				ascii_rubik.cpp \

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := clang++
# CPPFLAGS    := -I include

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)
		$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(DIR_DUP)
		$(CC) -c -o $@ $<
		$(info CREATED $@)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: clean fclean re
.SILENT: