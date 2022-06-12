#  File Makefile, created 2022-06-12 23:11:37.
# we don’t want to use relative paths, so we set these variables
PROJECT_DIR=/home/gudjon/repos/personal/rhatdist
SRC_DIR=/home/gudjon/repos/personal/rhatdist/desktopdist/classes
TEST_DIR=/home/gudjon/repos/personal/rhatdist/tests
# specify where the source code and includes are located
INCLUDE_DIRS=/home/gudjon/repos/personal/rhatdist/desktopdist/classes
SRC_DIRS=/home/gudjon/repos/personal/rhatdist/desktopdist/classes
TEST_SRC_DIRS = $(TEST_DIR)
$(info    FILE         : /home/gudjon/repos/personal/rhatdist/tests/Makefile)
$(info    PROJECT_DIR  :$(PROJECT_DIR))
$(info    TEST_DIR     :$(TEST_DIR))
$(info    INCLUDE_DIRS :$(INCLUDE_DIRS))
$(info    SRC_DIRS     :$(SRC_DIRS))
$(info    TEST_SRC_DIRS:$(TEST_SRC_DIRS))
# specify where the test code is located

# what to call the test binary
TEST_TARGET=app

# where the cpputest library is located
CPPUTEST_HOME=/usr/local
CPPUTEST_USE_GCOV=Y
# run MakefileWorker.mk with the variables defined here
include MakefileWorker.mk
