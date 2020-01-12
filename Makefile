RED =	\033[31m
GRE =	\033[32m
YEL =	\033[33m
BLU =	\033[34m
PUR =	\033[94m
PIN =	\033[1;35m
PRR =	\033[0;36m
STD =	\033[39m

NAME =	ft_select 

IDIR =	./inc/
ILIB =	./libft/inc
INCS =	select.h

INCC =	$(addprefix $(IDIR),$(INCS))

LDIR =	./libft
LIBS =	-lft

VPATH =			./src/:

SRCS =	main.c				\
		termios.c			\
		signal.c			\
		windows.c			\
		key.c				\
		termcaps_print.c	\
		utils.c				\
		utils_color.c		\
		print.c				\
		list.c

SRCC =	$(addprefix $(SRCS))

ODIR =	./objs/
OBJS =	$(SRCS:.c=.o)
OBCC =	$(addprefix $(ODIR),$(OBJS))

NORM =	$(SRCC) $(INCC)

CFLAG =	-Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${PUR}++ Compilation ++ :${STD} $@"
	@make -C ./libft/
	@gcc -g $(CFLAG) $(OBCC) -ltermcap -L$(LDIR) $(LIBS) -o $(NAME)

$(ODIR)%.o: $(SRCC_PATH)%.c
	@echo "  ${PUR}+Compilation :${STD} $^"
	@mkdir -p $(ODIR)
	@gcc $^ $(CFLAG) -c -o $@ -I$(IDIR) -I$(ILIB)

header:
	@echo "${PRR}"
	@echo "	   __ _              _           _  "
	@echo "  / _| |            | |         | |  "
	@echo " | |_| |_   ___  ___| | ___  ___| |_ "
	@echo " |  _| __| / __|/ _ \ |/ _ \/ __| __|"
	@echo " | | | |_  \__ \  __/ |  __/ (__| |_ "
	@echo " |_|  \__| |___/\___|_|\___|\___|\__|"
	@echo "       ______                        "
	@echo "      |______|                       "
	@echo "${STD}"

norme: header
	@echo "${PRR}  Verification de la norme${STD}\n"
	@norminette $(NORM)
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

clean: header
	@echo "  ${RED}-Delete all object files${STD}"
	@rm -rf $(ODIR)
	@make -C ./libft/ fclean
	@rm -f $(OBCC)

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make -C ./libft/ fclean
	@echo "  ${RED}-Delete objects and binary${STD}"

re: fclean all
