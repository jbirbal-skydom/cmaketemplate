#include <cstdio>
#include "echo.h"
#include <cstring>

int main() {
    printf("testing:");
    char *req;
    req = echo();
    return strcmp(req, "hello");
}