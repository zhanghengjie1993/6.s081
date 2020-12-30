#include "types.h"
#include "sysinfo.h"
#include "defs.h"


uint64 sys_sysinfo(){
    uint64 info;
    struct proc *p = myproc();
    struct sysinfo sinfo;
    
    if(argaddr(0, &info) < 0)
        return -1;    
    
    
}