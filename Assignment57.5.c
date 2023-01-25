/*
Write application which accept file name from user and 
one string from user.
Write that string at the end of tha file.

Input : Demo.txt
        Hello World
Output: write Hello world at the end of Demo.txt file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int OpenFile(char fName[])
{
    int fd = 0;

    fd = open(fName,O_RDWR | O_APPEND);
    return fd;
}

int main()
{
    char fname[20];
    char Data[200];
    int fd = 0;
    int length = 0;

    printf("Enter the file name that u want to open\n");
    scanf("%s",&fname);

    fd = OpenFile(fname);

    printf("Enter the string that u want to write in file\n");
    scanf(" %[^'\n']s",&Data);

    length = strlen(Data);

    write(fd,Data,length);

    return 0;
}