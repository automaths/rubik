NAME        :=	rubik

SRC_DIR     := 	src
OBJ_DIR     := 	obj
SRCS        := 	main.cpp \
				Cubos.cpp \
				ascii_rubik.cpp \
				cross.cpp \
				2FL.cpp \
				OLL.cpp \
				PLL.cpp \
				formula_utils.cpp \

STSRCS        := 	stat_main.cpp \
				Cubos.cpp \
				ascii_rubik.cpp \
				cross.cpp \
				2FL.cpp \
				OLL.cpp \
				PLL.cpp \
				formula_utils.cpp \

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
STSRCS        := $(STSRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
STOBJS        := $(STSRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC          := g++ -std=c++14 -fsanitize=address -g
# CPPFLAGS    := -I include

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME) stats

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)
		$(info CREATED $(NAME))

stats: $(STOBJS)
		$(CC) $(STOBJS) -o stats
		$(info CREATED stats)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		$(DIR_DUP)
		$(CC) -c -o $@ $<
		$(info CREATED $@)

clean:
		$(RM) $(OBJS)
		$(RM) $(STOBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) stats

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: clean fclean re
.SILENT: