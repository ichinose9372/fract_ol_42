
NAME	=	fractol

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c\
			mouse_hook.c\
			fract_ol_utils.c\
			mandelbrot.c\
			unit_color.c\
			key_hook.c\
			fractol.c\
			julia.c\
			set_fractol.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

all : $(NAME)

$(NAME)	: $(SRCS)
		$(CC) $(CFLAGS) $(SRCS)  -L/usr/X11R6/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
