/*
Write application which accept file name from user and 
read all data from that file and display contents on screen.

Input : Demo.txt
Output : Display all data of file

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int OpenFile(char Name[])
{
    int fd = 0;
    fd = open(Name,O_RDWR);
    return fd;
}

int main()
{
    char fName[20];
    char Data[100];
    int fd = 0;
    int iLength = 0;

    printf("Enter the file name that u want to open\n");
    scanf("%s",&fName);

    fd = OpenFile(fName);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is succesfully opened\n");
    }

    iLength = read(fd,Data,100);
    printf("Data from file is\n");

    write(1,Data,iLength);

    return 0;
}