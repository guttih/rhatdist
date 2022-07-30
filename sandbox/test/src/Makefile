# File src/Makefile created 2022-06-28 21:28:57.
SRC_DIR=/home/gudjon/repos/personal/rhatdist/sandbox/test/src
# specify where the source code and includes are located
INCLUDE_DIRS=$(SRC_DIR)/code
SRC_DIRS=$(SRC_DIR)
CODE_DIR=$(SRC_DIRS)/code
OUT=me

$(info    SRC_DIR:$(SRC_DIR))
$(info    INCLUDE_DIRS:$(INCLUDE_DIRS))
$(info    SRC_DIRS:$(SRC_DIRS))


# run MakefileWorker.mk with the variables defined here
# include MakefileWorker.mk

clean:
	rm $(SRC_DIR)/*.o $(CODE_DIR)/*.o $(OUT)

code.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/testCodeExample.cpp -o $(CODE_DIR)/code.o

Json.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/Json.cpp -o $(CODE_DIR)/Json.o   -lstdc++

JsonData.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/JsonData.cpp -o $(CODE_DIR)/JsonData.o   -lstdc++

AbstractJsonFileData.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/AbstractJsonFileData.cpp -o $(CODE_DIR)/AbstractJsonFileData.o   -lstdc++

Person.o: AbstractJsonFileData.o
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/Person.cpp -o $(CODE_DIR)/Person.o   -lstdc++

main: JsonData.o Json.o code.o Person.o
	gcc -I$(SRC_DIR) -I$(CODE_DIR) $(CODE_DIR)/code.o $(CODE_DIR)/JsonData.o $(CODE_DIR)/Json.o $(CODE_DIR)/AbstractJsonFileData.o $(CODE_DIR)/Person.o $(SRC_DIR)/$(OUT).cpp -o $(OUT)  -lstdc++