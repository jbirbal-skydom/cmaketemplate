#include "source_file.h"

#include <cstdio>
#include "stdlib.h"
#include "headerconfig.h"
#include "echo.h"

void hello() {
#ifdef BUGGER
    printf("LIB DEBUG used!\n");
    char* res;
    res = echo();
    printf(" %s", res );
    free(res);

#else
    printf("LIB accessed \n");
#endif
}