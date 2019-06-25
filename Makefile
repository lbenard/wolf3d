# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2019/06/25 19:09:16 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	wolf3d
SRCS_LIST		=	main.c												\
																		\
					engine/delta/get_delta_ptr.c						\
					engine/delta/get_last_delta.c						\
					engine/delta/get_wall_time.c						\
					engine/delta/set_last_delta.c						\
																		\
					engine/entity_node/new.c							\
					engine/entity_node/entity_from_node.c				\
					engine/entity_node/free.c							\
																		\
					engine/entity/init.c								\
					engine/entity/init_default.c						\
																		\
					engine/error/throw_error_errno.c					\
					engine/error/throw_error_str.c						\
					engine/error/throw_error.c							\
					engine/error/throw_result_str.c						\
					engine/error/throw_result.c							\
																		\
					engine/event/callback_node/new.c					\
					engine/event/callback_node/free.c					\
																		\
					engine/event/event_handler/init.c					\
					engine/event/event_handler/add_callback.c			\
					engine/event/event_handler/add_sub_handler.c		\
					engine/event/event_handler/call.c					\
					engine/event/event_handler/free.c					\
																		\
					engine/framebuffer/init.c							\
					engine/framebuffer/update.c							\
					engine/framebuffer/clear.c							\
					engine/framebuffer/display.c						\
					engine/framebuffer/free.c							\
																		\
					engine/game/init.c									\
					engine/game/set_scene.c								\
					engine/game/loop.c									\
					engine/game/is_running.c							\
					engine/game/is_focused.c							\
					engine/game/free.c									\
																		\
					engine/map/init.c									\
					engine/map/free.c									\
																		\
					engine/raycasting/angle/ft.c						\
					engine/raycasting/ray/ft.c							\
					engine/raycasting/raycasting_renderer/init.c		\
					engine/raycasting/raycasting_renderer/update.c		\
					engine/raycasting/raycasting_renderer/free.c		\
																		\
					engine/scene/init.c									\
					engine/scene/add_entity.c							\
					engine/scene/free.c									\
																		\
					game/entities/entity_type/update.c					\
					game/entities/entity_type/free.c					\
					game/entities/entity_type/get_entities_from_type.c	\
																		\
					game/entities/list/dummy/new.c						\
					game/entities/list/dummy/free.c						\
					game/entities/list/player/new.c						\
					game/entities/list/player/update.c					\
					game/entities/list/player/movements_event.c			\
					game/entities/list/test/new.c						\
					game/entities/list/test/update.c					\
					game/entities/list/test/free.c						\
																		\
					game/events/add_test_entity_event.c					\
					game/events/close_game_event.c						\
																		\
					game/scenes/list/menu/new.c							\
					game/scenes/list/menu/update.c						\
					game/scenes/list/menu/render.c						\
					game/scenes/list/menu/free.c						\
					game/scenes/list/raycasting/new.c					\
					game/scenes/list/raycasting/update.c				\
					game/scenes/list/raycasting/render.c				\
					game/scenes/list/raycasting/free.c					\
																		\
					game/scenes/scene_type/update.c						\
					game/scenes/scene_type/render.c						\
					game/scenes/scene_type/free.c

UNAME			=	$(shell uname)

SRCS_FOLDER		=	./srcs/
SRCS			=	$(addprefix $(SRCS_FOLDER), $(SRCS_LIST))
OBJS_LIST		=	$(SRCS_LIST:.c=.o)
OBJS_FOLDER		=	./objs/
OBJS			=	$(addprefix $(OBJS_FOLDER), $(OBJS_LIST))

LIBFT_FOLDER	=	libft
LIBFT			=	$(LIBFT_FOLDER)/libft.a

ifneq ($(UNAME), Linux)
	SFML_FOLDER		=	SFML
	SFML_ABSOLUTE	=	$(addprefix $(shell pwd)/, $(SFML_FOLDER))
	CSFML_FOLDER	=	CSFML
	CSFML			=	$(CSFML_FOLDER)/lib
endif

CXX				=	gcc
LD				=	gcc

INCLUDES		:=	-I includes					\
					-I $(LIBFT_FOLDER)/includes
LIB_FOLDERS		:=	-L$(LIBFT_FOLDER)

ifneq ($(UNAME), Linux)
	INCLUDES		:=	$(INCLUDES) -I $(CSFML_FOLDER)/include
	LIB_FOLDERS		:=	$(LIB_FOLDERS) -L $(CSFML_FOLDER)/lib
endif

LIBS			=	-lft				\
					-lm					\
					-lcsfml-graphics	\
					-lcsfml-window		\
					-lcsfml-system		\
					-lcsfml-audio

CFLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto

LDFLAGS			:=	$(LIB_FOLDERS) $(LIBS)
ifneq ($(UNAME), Linux)
	LDFLAGS			:=	$(LDFLAGS) \
						-Wl,-rpath,$(SFML_FOLDER)/extlibs/libs-osx/Frameworks
endif

# Colors
BOLD			=	\e[1m
DIM				=	\e[2m
ITALIC			=	\e[3m
UNDERLINED		=	\e[4m

BLACK			=	\e[30m
RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
BLUE			=	\e[34m
MAGENTA			=	\e[35m
CYAN			=	\e[36m
LIGHT_GRAY		=	\e[37m
DARK_GRAY		=	\e[90m
LIGHT_RED		=	\e[91m
LIGHT_GREEN		=	\e[92m
LIGHT_YELLOW	=	\e[93m
LIGHT_BLUE		=	\e[94m
LIGHT_MAGENTA	=	\e[95m
LIGHT_CYAN		=	\e[96m
WHITE			=	\e[97m
RESET			=	\e[0m

PREFIX			=	$(BOLD)$(LIGHT_CYAN)[$(NAME)]$(RESET):

all: $(CSFML) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(LD) $(OBJS) -o $(NAME) $(LDFLAGS)
	@printf "\e[0K$(PREFIX) done\n"

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@printf "$(PREFIX) $(shell basename $<)\n"
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@printf "\e[1A\e[0K"

run: all
	@./$(NAME)

$(LIBFT):
	@printf "\e[0K"
	@printf "$(PREFIX) libft all\n";
	@make -C libft
	@printf "\e[2A\e[0K"
	@printf "$(PREFIX) libft all done\n";

$(CSFML):
	@printf "\e[0K"
	@printf "$(PREFIX) CSFML\n";
	@cd $(SFML_FOLDER); \
		cmake .; \
		make
	@cd $(CSFML_FOLDER); \
		cmake -DSFML_ROOT="$(SFML_ABSOLUTE)" \
			-DSFML_INCLUDE_DIR="$(SFML_ABSOLUTE)/include" \
			-DCMAKE_MODULE_PATH="$(SFML_ABSOLUTE)/cmake/Modules"; \
		make
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) CSFML done\n";

libft-clean:
	@printf "\e[0K"
	@printf "$(PREFIX) libft clean\n";
	@make -C $(LIBFT_FOLDER) clean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) libft clean done\n";

libft-fclean:
	@printf "\e[0K"
	@printf "$(PREFIX) libft fclean\n";
	@make -C $(LIBFT_FOLDER) fclean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) libft fclean done\n";

csfml-clean:
	@printf "\e[0K"
	@printf "$(PREFIX) CSFML clean\n";
	@if test "$(CSFML_FOLDER)" != "" ; then \
		make -C $(CSFML_FOLDER) clean >/dev/null; \
	fi
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) CSFML clean done\n";

csfml-fclean:
	@printf "\e[0K"
	@printf "$(PREFIX) CSFML fclean\n";
	@if test "$(CSFML_FOLDER)" != ""; then \
		make -C $(CSFML_FOLDER) clean >/dev/null; \
		rm -rf $(CSFML_FOLDER)/lib; \
	fi
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) CSFML fclean done\n";

clean: libft-clean csfml-clean
	@printf "\e[0K"
	@printf "$(PREFIX) cleaned object files\n"
	@rm -rf $(OBJS_FOLDER)

fclean: clean libft-fclean csfml-fclean
	@printf "\e[0K"
	@printf "$(PREFIX) cleaned binary file\n"
	@rm -rf $(NAME)

separator:
	@printf "\n"

re: fclean separator $(LIBFT) all

.PHONY: norm libft-clean libft-fclean csfml-clean csfml-fclean clean fclean re
