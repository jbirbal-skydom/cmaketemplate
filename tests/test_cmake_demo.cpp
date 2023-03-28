#include <cstdio>
#include "echo.h"
#include <cstring>

int main() {
    printf("testing:");
    char* req;
    req = echo();
    if (strcmp(req, "hello") == 0)
    {
        return 0;
    } else
    {
        return 1;
    }


}
