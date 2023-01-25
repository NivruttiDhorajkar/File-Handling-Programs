/*
Write a program which accept file nme from user and 
count number of small characters from that file.

Input : Demo.txt
Output : Number of capital charters are 21

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int OpenFile(char fName[])
{
    int fd = 0;
    fd = open(fName,O_RDONLY);
    return fd;
}

int main()
{
    char fName[20];
    int fd = 0;
    char Data[100];
    int iCnt = 0;
    int iCount = 0;
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

    while((iLength = read(fd,Data,sizeof(Data))) != 0)
    {
        for(iCnt=0; iCnt<iLength; iCnt++)
        {
            if((Data[iCnt] >= 'a') && (Data[iCnt] <= 'z'))
            {
                iCount++;
            }
        }
    }

    printf("Small charcters in file is %d\n",iCount);
    
    return 0;
}
