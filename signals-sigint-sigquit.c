#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void sigint(int sig){  
    (void) signal(SIGINT,SIG_DFL); //reverse interruption code 
    sleep(2);//wait 2 seconds
    kill(getpid(),SIGINT);//sends signal to current process
}

int main(){
    struct sigaction act;
    act.sa_handler=sigint;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(SIGINT,&act,0);
    sigaction(SIGQUIT,&act,0);
    while(true){
        printf("Hello world\n");
        sleep(1);
    }
return 0;
}