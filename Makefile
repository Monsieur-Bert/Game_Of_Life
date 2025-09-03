NAME	=	Game_of_life

## ########################################################################## ##
#   INGREDIENTS																  ##
## ########################################################################## ##
# INC			header file locations
#
# SRCS_DIR		source directory
# SRCS			source files
#
# BUILD_DIR		build directory
# OBJS			object files
# DEPS			dependencies files

INC			:=	./includes
SRCS_DIR	:=	srcs
SRCS		:=	main.cpp\
				Cell.cpp	Grid.cpp	Renderer.cpp

SRCS		:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS		:=	$(SRCS:$(SRCS_DIR)/%.cpp=$(BUILD_DIR)/%.d)

## ########################################################################## ##
#   TOOLS																	  ##
## ########################################################################## ##
# CPP			compiler
# CPPFLAGS		compiler flags
#
# RM			force recusfly remove
# DIR_DUP		duplicate directory tree

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++17 -MMD -MP

DIR_DUP		=	mkdir -p $(@D)
RM			=	rm -rf

## ########################################################################## ##
#   EXTERNAL LBIB															  ##
## ########################################################################## ##
# SFML_DIR		source directory
# SFML_INC		source includes
# SFML_LIB		source lib.a and lib.so
# SFML_FLAGS	compiler flafs

SFML_DIR	:=	SFML-3.0.0
SFML_INC	:=	$(SFML_DIR)/include
SFML_LIB	:=	$(SFML_DIR)/lib
SFML_FLAGS	:=	-lsfml-graphics -lsfml-window -lsfml-system

# ########################################################################### ##
#	ANSI_CODES																  ##
## ########################################################################## ##

PREV_LINE	:=	\033[A

GREEN		:=	\033[1;32m
BLUE		:=	\033[1;34m
RED			:=	\033[1;31m
YELLOW		:=	\033[1;33m
RESET		:=	\033[0m

## ########################################################################## ##
#	PROGRESS BAR															  ##
## ########################################################################## ##

TOTAL_FILES		:=	$(words $(OBJS))
CURR_FILE		:=	0
BAR_LENGTH		:=	50
NAME_LENGTH		:=	50

define PROGRESS_BAR
	@$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
	@$(eval PERCENTAGE=$(shell echo $$(($(CURR_FILE) * 100 / $(TOTAL_FILES)))))
	@$(eval FILLED=$(shell echo $$(($(CURR_FILE) * $(BAR_LENGTH) / $(TOTAL_FILES)))))
	@printf "\rCompiling [%d/%d] %-$(NAME_LENGTH)s" $(CURR_FILE) $(TOTAL_FILES) "$(notdir $<)"
	@printf "\n"
	@printf "\r"
	@for i in `seq 1 $(FILLED)`; do printf "█"; done
	@for i in `seq 1 $$(($(BAR_LENGTH) - $(FILLED)))`; do printf "░"; done
	@printf " %3d%%" $(PERCENTAGE)
	@printf "$(PREV_LINE)\r"
endef

## ########################################################################## ##
#   RECIPES																	  ##
## ########################################################################## ##
# all			default goal
# $(NAME)		link .o -> archive file
# %.o			compilation .c -> .o
# clean			remove .o && directory tree
# fclean		remove .o && libft.a
# re			fclean && default goal

all: $(NAME)

run: $(NAME)
	@echo "${GREEN}Launching $(NAME)...${RESET}"
	@LD_LIBRARY_PATH=SFML-3.0.0/lib:$$LD_LIBRARY_PATH ./$(NAME)

$(NAME): $(OBJS)
	@printf "\n\n${BLUE}Linking objects into $(NAME)${RESET}\n"
	@$(CPP) $(CPPFLAGS) $^ -o $@ -I$(SFML_INC) -L$(SFML_LIB) $(SFML_FLAGS)
	@echo "${GREEN}Binary $(NAME) successfully created${RESET}"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@$(DIR_DUP)
	$(PROGRESS_BAR)
	@$(CPP) $(CPPFLAGS) -I$(INC) -I$(SFML_INC) -o $@ -c $<

clean:
	@$(RM) $(BUILD_DIR)
	@echo "${RED}Objects removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "${RED}Binary $(NAME) and $(BONUS) removed${RESET}"

re: fclean all

.PHONY: all clean fclean re run

-include $(DEPS)