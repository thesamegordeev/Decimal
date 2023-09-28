COMPILE=gcc -Wall -Werror -Wextra -std=c11 -Wno-unused-parameter
TEST_LIBS=-lcheck -lm -lpthread -lrt -lsubunit
LIB_NAME=s21_decimal.a
PRGRM_NAME=test_s21_decimal
TEST_DIR=test/
TEST_FILES=$(TEST_DIR)test*.c $(TEST_DIR)*/test*.c $(TEST_DIR)headers/*test.c
IMPL_FILES=*/s21_*.c
OBJ_FILES=s21_*.o


# Targets
all: gcov_report

compile: $(LIB_NAME)
	@$(COMPILE) $(TEST_FILES) $(TEST_LIBS) $(LIB_NAME) -o $(PRGRM_NAME)

test: compile
	@./$(PRGRM_NAME) || true

s21_decimal.a: $(IMPL_FILES)
	@$(COMPILE) -c $(IMPL_FILES)
	@ar -rcs $(LIB_NAME) $(OBJ_FILES)
	@rm -f $(OBJ_FILES)

add_coverage:
	@$(eval COMPILE+=--coverage)

gcov_report: add_coverage test
	@gcovr -r . --exclude=test --exclude=common/s21_dec_to_string.c --html --html-details -s -o report.html
	@rm -f *.gcda *.gcno

clean:
	@rm -f $(PRGRM_NAME) *.html *.css *.gcda *.gcno $(OBJ_FILES) $(LIB_NAME)