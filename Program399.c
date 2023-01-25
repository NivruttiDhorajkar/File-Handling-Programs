/*
write a program which accept file name from user and create another file
and copy that first file data into created file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>   // file controler 
#include<string.h>


int main(int argc, char *argv[])
{
    int fdSource = 0;     // File descriptor
    int fdDest = 0;
    char Data[100];
    int Length = 0;

    fdSource= open(argv[1],O_RDONLY);

    if(fdSource == -1)   
    {
        printf("Unable to open file\n");
        return -1;
    }


    fdDest = creat(argv[2],0777);

    if(fdDest == -1)
    {
        printf("Unable to create new file\n");
        return -1; 
    }
    
    while((Length = read(fdSource,Data,sizeof(Data))) != 0)
    {
        write(fdDest,Data,Length);
    }

    close(fdSource);
    close (fdDest);

    printf("Data succesfully copied\n");
    
    return 0;
}
