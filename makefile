NAME	=	fractol

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c\
			mouse_hook.c\
			fractol_utils.c\
			mandelbrot.c\
			color.c\
			key_hook.c\
			draw_fractol.c\
			julia.c\
			set_fractol.c\
			error_exit.c

HEAD	=	fractol.h

OPTHIN	=	-L/usr/X11R6/lib -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OPTHIN) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
