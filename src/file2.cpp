//
// Created by skydom on 3/21/2023.
//
#include "stdio.h"



#ifdef USE_DEBUG
void echo(void){
    printf("class DEBUG used!\n");
}
#else
void echo(void){
    printf("class!\n");
}
#endif