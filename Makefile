# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 21:23:31 by vhavryle          #+#    #+#              #
#    Updated: 2018/06/24 21:23:32 by vhavryle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
SRC = 
SRC += AObject.cpp  
SRC += Bullet.cpp
SRC += BulletList.cpp
SRC += Collisions.cpp
SRC += Field.cpp
SRC += LstNode.cpp
SRC += main.cpp
SRC += Node.cpp
SRC += Ship.cpp
SRC += ShipList.cpp
SRC += Core.cpp

HDR = 
HDR += AObject.hpp 
HDR += Bullet.hpp
HDR += BulletList.hpp
HDR += Collisions.hpp
HDR += Field.hpp
HDR += LstNode.hpp
HDR += Node.hpp
HDR += Ship.hpp
HDR += ShipList.hpp
HDR += Core.hpp

.NOTPARALLEL: all clean fclean re

SRC_O = $(SRC:.c=.o)
all: $(NAME) $(HDR)

$(NAME): $(SRC_O) $(HDR)
	clang++ -std=c++98 -lncurses -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
