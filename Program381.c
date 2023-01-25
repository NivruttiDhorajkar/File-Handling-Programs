/*
Write a program which create a file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 

int main()
{
    char Fname[20];
    int fd = 0;     // File descriptor

    printf("Enter the file name that you want to create\n");
    scanf("%s",&Fname);

    fd = creat(Fname,0777); // 0-Octal Number

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File is succesfully created with FD %d\n",fd);
    }

    return 0;
}