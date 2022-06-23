#!/usr/bin/env bash

#Function: getScriptPath()
#
#Brief: Gets the path to this script
#
getScriptPath(){
    echo "$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
}


#Function: buildAndRunTests()
#
#Brief: Builds and runs tests
#
buildAndRunTests(){
    make && ./QtTesting && echo -e "\033[01;32mTest ran Successfully\033[0m"  || echo -e "\033[01;31mTesting failed\033[0m"
}


PARENT_DIR=$(getScriptPath)
DIR="$PARENT_DIR/QtTest/build-QtTesting-Desktop-Debug"
reset
echo "DIR:$DIR"
cd "$DIR" && buildAndRunTests
