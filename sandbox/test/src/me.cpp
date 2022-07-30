// File me.cpp created 2022-06-28 21:28:57.
#include <stdlib.h>
#include <stdio.h>
#include "code/testCodeExample.h"
#include "code/Json.h"

int untestedFunc( int a, int b )
{
    return a + b;
}

int main( void )
{
    test_func();
    printf( "hello world!\n" );
    printf( "untestedFunc(2,3) = %d\n", untestedFunc( 2, 3 ) );
    String str="{\"hello\":\"world\"}";
    Json j(str.c_str());
    printf("\nJ:tostring: %s\n", j.toString().c_str());
    exit( 0 );
}
