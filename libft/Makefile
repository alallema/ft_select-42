RED =			\033[31m
GRE =			\033[32m
YEL =			\033[33m
BLU =			\033[34m
PUR =			\033[94m
PIN =			\033[1;35m
PRR =			\033[0;36m
STD =			\033[39m

NAME =			libft.a

IDIR =			./inc/
INCS =			libft.h

INCC =			$(addprefix $(IDIR),$(INCS))

SDIR =			./src/
SDIR_ASM =		./src_asm/

SRC =			ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strncpy.c	\
				ft_strncat.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strncmp.c	\
				ft_isprintable.c	\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_itoa.c		\
				ft_itoa_base.c	\
				ft_nbrlen.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_putendl.c	\
				ft_putnbr.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_lstnew.c		\
				ft_lstdelone.c	\
				ft_lstdel.c		\
				ft_lstadd.c		\
				ft_lstiter.c	\
				ft_lstclear.c	\
				ft_lstpushback.c\
				get_next_line.c

SRC_ASM =		ft_bzero.s			\
				ft_strcat.s 		\
				ft_isalpha.s		\
				ft_isdigit.s		\
				ft_isalnum.s		\
				ft_isascii.s		\
				ft_isprint.s		\
				ft_toupper.s		\
				ft_tolower.s		\
				ft_puts.s			\
				ft_strlen.s			\
				ft_memset.s			\
				ft_memcpy.s			\
				ft_strdup.s 		\
				ft_strcpy.s			\
				ft_strcmp.s			\
				ft_memdel.s			\
				ft_memalloc.s		\
				ft_atoi.s			\
				ft_cat.s

SRCC =		$(addprefix $(SRCS))

ODIR =		./objs/

OBJS =		$(SRC:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

OBJS_ASM =	$(SRC_ASM:.s=.o)
OBCC_ASM =	$(addprefix $(ODIR),$(OBJS_ASM))

CFLAG =		-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBCC) $(OBCC_ASM)
	@echo "  ${PUR}++ Compilation ++ :${STD} $@"
	@ar rc $(NAME) $(OBCC) $(OBCC_ASM)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	@gcc $(CFLAG) -c $< -o $@ -I$(IDIR)

$(ODIR)%.o: $(SDIR_ASM)%.s
	@mkdir -p $(ODIR)
	@nasm -f macho64 $< -o $@

clean:
	@echo "  ${RED}-Delete all object files${STD}"
	@rm -rf $(ODIR)
	@rm -f $(OBCC)

fclean: clean
	@rm -f $(NAME)
	@echo "  ${RED}-Delete objects and binary${STD}"

re: fclean all
