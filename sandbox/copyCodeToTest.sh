#!/usr/bin/env bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
FILES_TO_COPY=( Json.h Json.cpp JsonData.h JsonData.cpp String.h )
FROM_DIR=$(readlink -m $DIR/../desktopdist)
TO_DIR=$(readlink -m $DIR/test/src/code/)

printHelp() {
    printf 'Usage: %s [OPTIONS]...\n' "$(basename "$0")"
    echo "  Copies the files:"
    echo "   ${FILES_TO_COPY[@]}"
    echo "   From $FROM_DIR"
    echo "     To $TO_DIR"
    echo 
    echo "OPTIONS        Option description"
    echo "  -help        Prints this help page"
    echo
    exit 0
}

#Text Color commands
#Brief: Commands to change the color of a text
highlight=$(echo -en '\033[01;37m')
purpleColor=$(echo -en '\033[01;35m')
cyanColor=$(echo -en '\033[01;36m')
errorColor=$(echo -en '\033[01;31m')
warningColor=$(echo -en '\033[00;33m')
successColor=$(echo -en '\033[01;32m')
norm=$(echo -en '\033[0m')

#Function: parseOptions()
#
#Brief: Checks if all options are correct and saves them to variables
#
#Arguments all bash options
parseOptions() {
    while (("$#")); do # While there are arguments still to be shifted

        if [[ "$1" == "--help" || "$1" == "-h" ]]; then
            printHelp
        fi
        shift
    done

}

parseOptions "$@"

echo "Hello ${cyanColor}bash${norm} world"




#Function: CopyFiles()
#
#Brief: Copies spesific files from one directory to anouther
#
#Argument 1($1): Copy files from this directory
#Argument 2($2): Copy files to this directory
#Argument 3($3): Files to copy
CopyFiles(){
    if [ $# -lt 3 ]; then echo "Invalid number of parameters provided to $FUNCNAME"; exit 1; fi
    declare FROM=$1
    declare TO=$2
    shift; shift
    for e; do 
        echo "cp $FROM/${highlight}$e${norm} $TO"
        cp "$FROM/$e" "$TO"
    done
}
 echo "Copying files from $FROM_DIR to $TO_DIR"
 CopyFiles $FROM_DIR $TO_DIR "${FILES_TO_COPY[@]}"

