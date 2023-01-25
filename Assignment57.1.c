/*
Write application which accept file name from user and 
open that file in read mode.

Input : Demo.txt
Output : File opened succesfully

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int CreateFile(char Name[])
{
    int fd = 0;

    fd = creat(Name,0777);

    return fd;
}

int OpenFile(char Name[])
{
    int fd = 0;
    fd = open(Name,O_RDONLY);
    return fd;
}

int main()
{
    char fName[20];
    char Data[100];
    int fd = 0;

    printf("Enter the file name that u want to create\n");
    scanf("%s",&fName);

    fd = CreateFile(fName);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    else
    {
        printf("File is succesfully created\n");
    }

    fd = OpenFile(fName);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is open succesfully\n");
    }
    return 0;
}