//
//  OS2VirtualMem.c
//  
//
//  Created by Pushpa Viviniya on 8/28/18.
//First, it allocates some memory (line a1). Then, it prints out the address of the memory (a2), and then puts the number zero into the first slot of the newly allocated memory (a3). Finally, it loops, delaying for a second and incrementing the value stored at the address held in p. With every print statement, it also prints out what is called the process identifier (the PID) of the running program. This PID is unique per running process.

#include "OS2VirtualMem.h"
#include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "common.h"

int
 main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n",
           getpid(), p);
    *p=0; //a3
    while (1) {
    Spin(1);
    *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);}
    return 0; }

/*prompt> ./mem &; ./mem &
 [1] 24113
 [2] 24114
 (24113) address pointed to by p: 0x200000
 (24114) address pointed to by p: 0x200000
 (24113) p: 1
 (24114) p: 1
 (24114) p: 2
 (24113) p: 2
 (24113) p: 3
 (24114) p: 3
 (24113) p: 4
 (24114) p: 4, if address space randomization is disabled, show both programs are using same address*/
