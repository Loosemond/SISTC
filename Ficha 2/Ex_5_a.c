
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define PRINT printf("\n%i %i",getpid(),getppid());


int main() {
    int r = fork();
    if (r==0){

        PRINT

        exit(0);
    }
    sleep(5);
    puts("");
    system("ps -f");
    puts("Shutting down");

}

