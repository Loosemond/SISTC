#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {

    struct sigaction act;
    sigset_t new_mask;


    sigemptyset(&new_mask);

    sigaddset(&new_mask, SIGINT);
    sigaddset(&new_mask, SIGQUIT);
    if( sigprocmask(SIG_SETMASK, &new_mask, NULL) == -1) //bloquei os sinais
    {
        perror("sigprocmask");
        exit(1);
    };
    if(signal(SIGTERM, SIG_IGN)==SIG_ERR)
    {
        perror("signal");
        exit(1);
    };

    while(1) {

        wait_something();
        pid_t r = fork();
        if(r == 0) {
            sigaddset(&new_mask, SIGTSTP);
            if( sigprocmask(SIG_SETMASK, &new_mask, NULL) == -1) //bloquei os sinais
            {
                perror("sigprocmask");
                exit(1);
            };

            do_something();
            return(0);
        }else{
            act.sa_handler=myhandler;
            sigemptyset(&act.sa_mask);
            act.sa_flags = 0;
            if(sigaction(SIGCHLD,&act, NULL)==-1) // define o evento criado pelo sinal
            {
                perror("sigaction"); // verifica se consegue fazer esta funçao
                exit(1);
            };
        }

    }
    return(0);
}


void myhandler(int signum)
{
    do_something();
}


