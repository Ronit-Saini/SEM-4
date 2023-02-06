#include <stdio.h>
#include <stdlib.h>

void prime_factors(int m)
{
    int i;
    int arr[10];
    int j=0;

    for(i=1;i<=m;i++)
    {
        if (m%i==0)
        {
            if (is_prime(i)!=0)
            {
                arr[j]=i;
                j++;
            }
        }
    }
    printf("Factors list of %d is : ",m);
    for(i=0;i<j;i++)
    {
        printf("%d ",arr[i]);
    }
}

int is_prime(int m)
{
    int i;
    int count=0;
    for(i=1;i<=m;i++)
    {
        if (m%i==0)
        {
            count++;
        }
    }
    if (count==2)
    {
        return m;
    }
    return 0;
}

int main()
{
    int m,n;
    printf("Enter number 1 : ");
    scanf("%d",&m);
    printf("\n");
    prime_factors(m);

    /*printf("\nEnter number 2 : ");
    scanf("%d",&n);
    printf("\n");
    prime_factors(n);*/
}
