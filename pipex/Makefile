NAME = pipex

SRC = pipex.c \
		child_functions.c \
		erros.c \
		free_functions.c \
		utils/ft_split.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_strncmp.c \
		utils/ft_substr.c \

INCLUDES = pipex.h  

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ) 
		gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c	$(INCLUDES) 
		gcc $(FLAGS) -c  $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
