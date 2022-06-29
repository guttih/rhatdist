#  File Makefile, created 2022-06-28 22:29:44.
# we don’t want to use relative paths, so we set these variables
PROJECT_DIR=/home/gudjon/repos/personal/rhatdist/sandbox/test
SRC_DIR=$(PROJECT_DIR)/src/code
TEST_DIR=$(PROJECT_DIR)/tests
# specify where the source code and includes are located
INCLUDE_DIRS=$(PROJECT_DIR)/src/code
SRC_DIRS=$(PROJECT_DIR)/src/code
TEST_SRC_DIRS = $(TEST_DIR)
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
