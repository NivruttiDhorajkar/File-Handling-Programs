/*
Write a program which accepts file name from user and 
one character from user user and count number of occurences of
that characters from that file.

Input : Demo.txt
        i
Output : Frequency of i is 
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int CountCharOccu(char fName[], char ch)
{
    int fd = 0;
    int iCnt = 0;
    int iLength = 0;
    char Data[100];
    int iCount = 0;
    char temp = '\0';

    if(ch >= 'a' && ch <= 'z')
    {
        temp = ch - 32;
    }
    else
    {
        temp = ch + 32;
    }

    fd = open(fName,O_RDONLY);

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
            if((Data[iCnt] == ch )|| (Data[iCnt] == temp))
            {
                iCount++;
            }
        }
    }
    return iCount;
}

int main()
{
    char fName[20];
    char ch = '\0';
    int iRet = 0;

    printf("Enter the file name that u want to open\n");
    scanf("%s",&fName);

    printf("Enter the character that u want to search occurence\n");
    scanf(" %c",&ch);

    iRet = CountCharOccu(fName,ch);

    printf("Frequency of %c is %d\n",ch,iRet);
    return 0;
}