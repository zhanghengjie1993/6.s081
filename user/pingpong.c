#include "kernel/types.h"
#include "user.h"

void 
main(int argc, char const *argv[])
{   
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);
    if (fork() == 0)
    {
        unsigned char writebuf[4] = "pong";
        unsigned char readbuf[4];
        read(p1[0], (void *)readbuf, 4);
        int pid = getpid();
        printf("%d: received %s\n", pid, readbuf);
        write(p2[1], writebuf, 4);
        exit(0);
    }else
    {   
        unsigned char writebuf[4] = "ping";
        unsigned char readbuf[4];
        write(p1[1], writebuf, 4);
        read(p2[0], (void *)readbuf, 4);
        int pid = getpid();
        printf("%d: received %s\n", pid, readbuf);
        exit(0);
    }
}
