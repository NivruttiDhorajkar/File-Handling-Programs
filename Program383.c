/*
Write a program which accept file name from user
and open that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 

//  O_RDONLY    Open for reading
//  O_WRONLY    Open for writing
//  O_RDWR      Open for reading and writing.

int main()
{
    char Fname[20];
    int fd = 0;     // File descriptor

    printf("Enter the file name that you want to open\n");
    scanf("%s",&Fname);

    fd = open(Fname,O_RDWR);

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