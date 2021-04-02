CC	=	gcc

SRC	=	src/strlen.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strchr.asm	\
		src/strcmp.asm	\
		src/memmove.asm	\
		src/strncmp.asm	\
		src/strcasecmp.asm	\
		src/rindex.asm	\
		src/strstr.asm	\
		src/strpbrk.asm	\
		src/strcspn.asm	\

SRC_TEST	=	tests/test_strlen.c	\
			tests/test_memset.c	\
			tests/test_memcpy.c	\
			tests/test_strchr.c	\
			tests/test_strcmp.c	\
			tests/test_memmove.c	\
			tests/test_rindex.c	\
			tests/test_strstr.c	\
			tests/test_strpbrk.c	\
			tests/test_strcspn.c	\
			tests/test_strcasecmp.c	\
			tests/test_strncmp.c	\

OBJ	=	$(SRC:.asm=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	libasm.so

TESTNAME	=	unit_tests

TESTFLAGS	=	--coverage -lcriterion -ldl

LDFLAGS	=	-fPIC -shared

RM_F	=	@rm -f

all:	$(OBJ)
	@echo -n "\033[32m------------------------\033[0m\n"
	@ld $(LDFLAGS) -o $(NAME) $(OBJ) && echo "Compilation Lib [\033[32mDONE\033[0m]" || echo "Compilation Lib [\033[31mFAIL\033[0m]"
	@echo -n "\033[32m------------------------\033[0m\n"

%.o: %.asm
	@nasm -f elf64 -o $@ $< && echo "Compiling ASM: $< [\033[32mOK\033[0m]" || echo "Compiling ASM: $< [\033[31mKO\033[0m]"

%.o: %.c
	@echo -n "Compiling Test: $<"
	@$(CC) $(CFLAGS) -c $< -o $@ && echo " [\033[32mOK\033[0m]" || echo " [\033[31mKO\033[0m]"

tests_run:	all $(OBJ_TEST)
	@echo -n "\033[32m------------------------\033[0m\n"
	@$(CC) -o $(TESTNAME) $(OBJ_TEST) $(TESTFLAGS) && echo "Compilation Test [\033[32mDONE\033[0m]" || echo "Compilation Test [\033[31mFAIL\033[0m]"
	@echo -n "\033[32m------------------------\033[0m\n"
	@./$(TESTNAME)

clean:
	$(RM_F) src/*.o
	$(RM_F) tests/*.o
	$(RM_F) *.gc*

fclean:	clean
	$(RM_F) $(NAME)
	$(RM_F) $(TESTNAME)

re:	fclean all

.PHONY:	all clean fclean re $(NAME) tests_run
