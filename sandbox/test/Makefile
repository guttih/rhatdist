#  File Makefile, created 2022-06-28 22:29:44.
PROJECT_DIR=/home/gudjon/repos/personal/rhatdist/sandbox/test
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/tests
CODE_DIR=$(PROJECT_DIR)/src/code
OUT=me
TEST_TARGET=app
COVERAGE_DIR=$(TEST_DIR)/coverage
CPPUTEST_USE_GCOV=Y

$(info    PROJECT_DIR:$(PROJECT_DIR))
$(info    SRC_DIR:$(SRC_DIR))
$(info    TEST_DIR:$(TEST_DIR))
$(info    CODE_DIR:$(CODE_DIR))
$(info    OUT:$(OUT))
$(info    TEST_TARGET:$(TEST_TARGET))
$(info    COVERAGE_DIR:$(COVERAGE_DIR))

copy_files:
	$(PROJECT_DIR)/../copyCodeToTest.sh 

test:
	make -C $(TEST_DIR)

test_clean:
	make -C $(TEST_DIR) clean

testCodeExample.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/testCodeExample.cpp -o $(CODE_DIR)/testCodeExample.o

build:
	make -C app

#main: testCodeExample.o
#	gcc -I$(CODE_DIR) $(CODE_DIR)/testCodeExample.o $(SRC_DIR)/$(OUT).cpp -o $(SRC_DIR)/$(OUT)

main:
	make -C $(SRC_DIR) main

all: copy_files test main coverage

testcov: test coverage
	xdg-open $(COVERAGE_DIR)/index.html

clean_coverage:
	rm -rf $(COVERAGE_DIR)

coverageFirst: clean_coverage
	mkdir $(COVERAGE_DIR); lcov --capture --directory . --output-file $(COVERAGE_DIR)/coverage.info; genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR) && echo -ne "To open report give command\n  xdg-open $(COVERAGE_DIR)/index.html\n"

coverage: coverageFirst
	lcov --remove $(COVERAGE_DIR)/coverage.info '/usr/include/*'   --output-file $(COVERAGE_DIR)/coverage2.info;genhtml $(COVERAGE_DIR)/coverage2.info --output-directory $(COVERAGE_DIR)

clean: test_clean clean_coverage
	rm $(SRC_DIR)/*.o $(CODE_DIR)/*.o $(OUT)
