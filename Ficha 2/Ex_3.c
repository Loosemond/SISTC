
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>


int main() {

    char *ptr = malloc(8); // defenimos um vetor
    strcpy(ptr,"pai");// vai copiar a string para ptr
    int r = fork();
    if (r==0){ //thread do filho
        strcpy(ptr,"filho");
        puts(ptr);

        exit(0);

    }

    waitpid(r,NULL,NULL);

    puts(ptr);
}