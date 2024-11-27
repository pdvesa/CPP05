CC = c++

CCFLAGS = -Wall -Werror -Wextra

NAME = bureaucrat

INC = -Iincludes

SRCS = srcs/main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/ShrubberyRequestForm.cpp srcs/RobotomyRequestForm.cpp srcs/PresidentialPardonForm.cpp srcs/Intern.cpp

OBJS = $(SRCS:srcs/%.cpp=build/%.o)

DEPS = $(SRCS:srcs/%.cpp=build/%.d)

BUILD_DIR = build

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: srcs/%.cpp | $(BUILD_DIR)
	$(CC) $(CCFLAGS) $(INC) -MMD -MP -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re