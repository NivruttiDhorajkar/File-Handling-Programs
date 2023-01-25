/*
Write application which accept file name from user and 
display size of file.

Input : Demo.txt
Output : File size is 56 bytes.

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
    int iSize = 0;

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

    while((iLength = read(fd,Data,100)) != 0)
    {
        iSize = iSize + iLength;
    }

    printf("Fikle size is %d bytes\n",iSize);

    return 0;
}