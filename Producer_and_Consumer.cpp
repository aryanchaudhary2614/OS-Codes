#include<iostream>
#include <unistd.h>
#include <string.h>
using namespace std;
int S=1,counter=0,E=3,F=0;
void wait(int &S)
{
    while(S==0);
    S=S-1;
}
void signal(int &S)
{
    S=S+1;
}
void producer()
{
    wait(E);
    wait(S);
    counter=counter+1;
cout<<"Produced is"<<counter<<endl;
    signal(S);
    signal(F);
}
void consumer()
{
    wait(F);
    wait(S);
    counter=counter-1;
cout<<"Consumed is"<<counter<<endl;
    signal(S);
    signal(E);

}
int main()
{
    int choice;
    while(true)
    {
cout<<"1.Produce\n2.Consume\n3.Exit"<<endl;
cout<<"Enter choice"<<endl;
cin>>choice;
        if(choice==1)
        {
if(S==1 && E!=0)
producer();
            else
cout<<"Buffer is full"<<endl;
        }
        else if(choice==2)
        {
if(S==1 && F!=0)
consumer();
            else
cout<<"Buffer is empty"<<endl;
        }
        else if(choice==3)
        {
exit(0);
            break;
        }
        else
cout<<"Invalid Input. Enter correct value"<<endl;
    }
}                                  
