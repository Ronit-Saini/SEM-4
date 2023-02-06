#include <stdio.h>
#include <stdlib.h>

int con_int_gcd(int m,int n)
{
    int t;
    if (m<n)
        t=m;
    else
        t=n;

    while (t!=0)
        {
        if ((m%t)==0)
            {
            if ((n%t)==0)
                return t;
            }
        t=t-1;
        }

    return t;
}

int main()
{
    int x,y;
    printf("Enter number 1 : ");
    scanf("%d",&x);
    printf("\nEnter number 2 : ");
    scanf("%d",&y);
    printf("\nGCD of %d and %d is %d \n",x,y,con_int_gcd(x,y));
}
