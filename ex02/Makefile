NAME		=	accounting

SRC			=	tests.cpp \
				Accounts.cpp

OBJS		=	$(SRC:.cpp=.o)

CC		=	c++

# -std=c++98 displays an error if an unauthorized function is left in the code
CXXFLAGS		=	-g -Wall -Wextra -Werror -std=c++98

EXE_NAME	=	-o $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) $(EXE_NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.cpp.o:
	${CC} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

.PHONY:	all clean fclean re