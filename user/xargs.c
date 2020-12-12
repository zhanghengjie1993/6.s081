#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

#define STDIN_FILENO 0
#define MAXLINE 1024

int main(int argc, char *argv[])
{
    char *params[MAXARG];
    char tmp[1];
    int param_index = 0;
    for (int i = 1; i < argc; i++) params[param_index++] = argv[i];
    char *cmd = argv[1];
    char *buf = (char *)malloc(10);
    char *p = buf;
    if (fork() == 0){
        while (read(STDIN_FILENO, tmp, 1) > 0){
            if (*tmp != '\n'){
                *buf++ = *tmp;
                continue;
            }
            *buf = 0;
            params[param_index++] = p;
            buf = (char *)malloc(10);
            p = buf;
        }
        params[param_index] = 0;
        exec(cmd, params);
    }
    wait(0);
    exit(0);
}
