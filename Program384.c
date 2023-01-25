/*
Write a program which accept file name from user
and open that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 

int OpenFile(char Name[])
{
    int fd = 0;

    fd = open(Name,O_RDWR);

    return fd;
}

int main()
{
    char Fname[20];
    int fd = 0;     // File descriptor

    printf("Enter the file name that you want to open\n");
    scanf("%s",&Fname);

    fd = OpenFile(Fname);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File is succesfully opened with FD %d\n",fd);
    }

    return 0;
}