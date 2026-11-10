NAME := ft_ping

SRC_DIR := src
INC_DIR := include
BUILD_DIR := .build

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I$(INC_DIR) -MMD -MP
LDLIBS = -lm

SRCS := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)
