
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
    sleep(2);
    execl("/bin/ps","-f",(char*) NULL); // é preciso que o camniho seja absoluto , faço o cast do char para ter a certesa que ele é do tipo char
    puts("Shutting down");

}

