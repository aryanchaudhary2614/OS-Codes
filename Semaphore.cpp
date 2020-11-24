#include<iostream>
#include <unistd.h>
#include <string.h>
using namespace std;
int S=1;
char* msg= "Hey!!It's a message!";
void wait(int S)
{
    while(S==0);
    S=S-1;
}
void signal(int S)
{
    S=S+1;
}
int main()
{
    char buff[1024];
    int fd[2];
    pipe(fd);
    if(fork()!=0)
    {
        wait(S);
cout<<"Parent process"<<endl;
cout<<msg<<endl;
msg="Hello World";
        write(fd[1], msg, strlen(msg)+1);
        signal(S); 

    }
    else
    {
        wait(S);
cout<<"Child process"<<endl;
        read(fd[0], buff, 1024);
cout<<buff;
        signal(S);
    }
}
