#include "source_file.h"

#include <stdio.h>
#include "headerconfig.h"

void hello(void) {
#ifdef BUGGER
    printf("LIB DEBUG used!\n");
#endif
    printf("LIB accessed \n");
}