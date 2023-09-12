NAME		 =	btc
CC			 =	c++

OBJECTFOLDER = temp
MKDIR = mkdir
SRCS		=	$(wildcard *.cpp)
OBJS		=	$(patsubst %.cpp, $(OBJECTFOLDER)/%.o, $(SRCS))
CFLAGS		=	#-std=c++98 -Wall -Wextra -Werror -fsanitize=address -g
RM			=	rm -rf
HEADER		= $(wildcard *.hpp)

all: $(OBJECTFOLDER) $(NAME) 

$(OBJECTFOLDER) :
	mkdir $(OBJECTFOLDER)

$(OBJECTFOLDER)/%.o: %.cpp $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) 
	$(RM) $(OBJECTFOLDER) 

fclean: clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean bonus fclean re

