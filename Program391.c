/*
write a program which Accept file name from user and 
read whole file and display data on console.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 
#include<string.h>


int main()
{
    char Fname[20];
    int fd = 0;     // File descriptor
    char Data[100];
    int Length = 0;

    printf("Enter the file name that you want to open\n");
    scanf("%s",&Fname);

    fd = open(Fname,O_RDONLY);

    if(fd == -1)   
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((Length = read(fd,Data,sizeof(Data))) != 0)
    {
        write(1,Data,Length);
    }

    close(fd);
    
    return 0;
}
