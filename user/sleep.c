#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc != 2) {
    fprintf(2, "usage: sleep ticks\n");
    exit(0);
  }
  sleep(atoi(argv[1]));
  printf("process sleep over\n");
  exit(0);
}