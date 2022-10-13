#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    char userChoice = 'z';
    while(userChoice != 'q'){
        printf("a: ls ");
        printf("b: ps ");
        printf("c: who ");
        printf("q for quit ");
        scanf(" %c", &userChoice);
        pid_t cpid;
        cpid = fork();
        if(cpid < 0){
            exit(-1);
        }    
        else if(cpid == 0){
            if(userChoice == 'a'){
                execl("/bin/ls", "ls", NULL);
            }        
            else if(userChoice == 'b'){
                execl("/bin/ps", "ps", NULL);
            }                
            else if(userChoice == 'c'){
                execl("/bin/whoami", "whoami", NULL);
            }
            else{
                exit(0);
            }
        }
        wait(NULL);
    }
    printf("parent terminated\n");
    return 0;
}