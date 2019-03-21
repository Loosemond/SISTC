#include <stdio.h>
#include <zconf.h>
#include <string.h>
#include <errno.h>
//extern int errno ;

int main() {
    printf("Deleting fifo\n");
    const char file[80] = {"/home/joao/CLionProjects/Ficha4/sistc_fifo"};
    unlink(file);
    fprintf(stderr,"%s\n", strerror( errno ));
    return 0;

}
