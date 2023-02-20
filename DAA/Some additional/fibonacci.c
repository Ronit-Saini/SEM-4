#include <stdio.h>

int opcount=0;

int fibo(int num);

int main()
{
    int num,fibonacci;
    printf("Enter any nuber to find nth finbonacci term : ");
    scanf("%d",&num);
    fibonacci=fibo(num);
    printf("%dth fibonacci term is %d",num,fibonacci);
    printf("\nopcount is %d",opcount);
    return 0;
}

int fibo(int num)
{
    if(num==0)
        {opcount++;return 0;}
    else if(num==1)
        {opcount++;return 1;}
    else 
        {opcount++;return (fibo(num-1)+fibo(num-2));}
    
}
