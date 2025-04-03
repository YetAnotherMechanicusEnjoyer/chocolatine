##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Compiles C files
##

DIR_LIB		=	lib/

LIB_FILES	=	write.c		\
				get_len.c	\
				my_cmp.c	\
				my_cpy.c	\
				my_dup.c	\
				convert.c	\
				swap.c		\
				file_reader.c	\
				str_to_word_array.c

DIR_TMP		=	template/

TMP_FILES	=	init.c	\

DIR_SRC		=	src/

SRC_FILES	=	main.c	\
				$(addprefix $(DIR_LIB), $(LIB_FILES))	\
				$(addprefix $(DIR_TMP), $(TMP_FILES))

SRC			=	$(addprefix $(DIR_SRC), $(SRC_FILES))

DIR_TEST	=	tests/

TEST_FILES	=	test.c	\
				lib.c	\

TESTS		=	$(addprefix $(DIR_TEST), $(TEST_FILES))

BINARY_TEST	=	test

TFLAGS		=	--coverage -lcriterion

TEST_SRC	=	$(addprefix $(DIR_SRC), $(addprefix $(DIR_LIB), $(LIB_FILES)))\
				$(addprefix $(DIR_SRC), $(addprefix $(DIR_TMP), $(TMP_FILES)))

TEST_OBJ	=	$(TEST_SRC:.c=.o)

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-I./include -g -Wall -Wextra

BINARY		=	chocolatine

all: 	$(BINARY)

$(BINARY):	$(OBJ)
		@gcc $(OBJ) -o $(BINARY) $(CFLAGS)
		@echo -e "\x1b[36mMakefile -> compile\x1b[0m"

clean:
		@rm -f $(OBJ) $(TEST_OBJ)
		@rm -rf .ropeproject
		@echo -e "\x1b[35mMakefile -> clean\x1b[0m"

fclean: clean
		@rm -f $(BINARY)
		@rm -f $(BINARY_TEST)
		@rm -f *.log
		@rm -f *.gcov
		@rm -f *.gcda
		@rm -f *.gcno
		@rm -rf .cache
		@rm -f vgcore.*
		@echo -e "\x1b[35mMakefile -> fclean\x1b[34m"

re:		fclean all
		@rm -rf .ropeproject
		@echo -e "\x1b[31mMakefile -> re\x1b[0m"

run:	re
		@echo -e "\x1b[33mMakefile -> run\x1b[0m"
		@echo -e "\x1b[32m>-------------------<\x1b[35m"
		@-./$(BINARY) --help
		@echo -e "\x1b[36m+-----------+\x1b[0m"
		@-./$(BINARY)
		@rm -f $(BINARY)
		@rm -f $(OBJ)
		@rm -f *.log
		@rm -f *.gcov
		@rm -f *.gcda
		@rm -f *.gcno
		@rm -f vgcore.*
		@echo -e "\x1b[32m>-------------------<\x1b[0m"

criterion: fclean $(TEST_OBJ)
		@gcc -o $(BINARY_TEST) $(TEST_OBJ) $(TESTS) $(CFLAGS) $(TFLAGS)
		@rm -f $(TEST_OBJ)
		@echo -e "\x1b[36mMakefile -> criterion\x1b[0m"

run_tests:	criterion
		@-./$(BINARY_TEST)
		@gcovr --exclude ./$(BINARY_TEST)
		@rm -f $(BINARY) $(BINARY_TEST)
		@rm -f *.gcov
		@rm -f *.gcda
		@rm -f *.gcno
		@echo -e "\x1b[34mMakefile -> run_tests\x1b[0m"

.PHONY: all clean fclean re criterion run_tests run
