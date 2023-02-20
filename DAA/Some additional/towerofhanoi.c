#include <stdio.h>
int opcount=0;
void towers(int,char,char,char);

int main()
{
    int num;
    printf("Enter no of disks : ");
    scanf("%d",&num);
    printf("the sequence of moves involved in tower of hanoi are : \n");
    towers(num,'A','C','B');
    printf("\nopcount=%d",opcount);
    return 0;
}

void towers(int num,char frompeg,char topeg,char auxpeg)
{
    if(num==1)
    {
        printf("Move disk 1 from peg %c to peg %c\n",frompeg,topeg);
        opcount++;
        return;
    }
    opcount++;
    towers(num-1,frompeg,auxpeg,topeg);
    printf("Move disk %d from peg %c to peg %c\n",num,frompeg,topeg);
    towers(num-1,auxpeg,topeg,frompeg);
}