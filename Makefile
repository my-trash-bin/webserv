# Makefile

CC = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Iincludes

SRC_DIR = srcs
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target executable
NAME = webserv



# Default rule
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

# Full clean rule
fclean:
	$(MAKE) clean
	rm -f $(NAME)

# Rule for rebuilding everything
re:
	$(MAKE) fclean
	$(MAKE) all

# .PHONY rules
.PHONY: all clean fclean re