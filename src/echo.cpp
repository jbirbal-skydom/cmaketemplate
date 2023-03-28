//
// Created by skydom on 3/21/2023.
//
#include <cstdio>
#include <cstdlib>
#include "echo.h"
#include <cstring>
#include <iostream>
#include <iterator>

#ifdef USE_DEBUG
void echo(void){
    printf("class DEBUG used!\n");
}
#else
char *echo(){
    char Something[]="hello";
//    char *copy;
//    copy = (char*) malloc(sizeof (char));
//    *(char*)copy = Something;



    printf("Accessed:");



////// memory allocate

    size_t len = strlen(Something) +1; //find length of s plus the null terminator
    char *copy;
    copy = (char *)malloc(len); //cast to char
    int i;
    for(i=0;i<len;++i)
    {
        copy[i]=Something[i];  //copy characters
    }

    return copy;
}
#endif