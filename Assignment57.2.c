/*
Write application which accept file name from user and 
create that file.

Input : Demo.txt
Output : File created succesfully

*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int CreateFile(char Name[])
{
    int fd = 0;

    fd = creat(Name,0777);

    return fd;
}

int main()
{
    char fName[20];
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

    return 0;
}