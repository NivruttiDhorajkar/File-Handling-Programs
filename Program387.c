/*
Write a program which accept file name from user
and write data on  that file.
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

    fd = open(Fname,O_RDWR | O_APPEND);
    if( fd == -1)
    {
        return -1;
    }
    
    printf("Enter tha data that you want to write in the file\n");
    scanf(" %[^'\n']s",&Data);

    Length = strlen(Data);

    // write(kasat,kay,kiti);
    write(fd,Data,Length);

    return 0;
}