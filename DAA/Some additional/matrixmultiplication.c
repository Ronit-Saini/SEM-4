#include <stdio.h>

int opcount=0;

int main()
{
    int r1,r2,c1,c2;
    printf("Enter the rows for first matrix : \n");
    scanf("%d",&r1);
    printf("Enter the columns for first matrix : \n");
    scanf("%d",&c1);
    printf("Enter the rows for second matrix : \n");
    scanf("%d",&r2);
    printf("Enter the columns for second matrix : \n");
    scanf("%d",&c2);

    if(c1!=r2)
    {
        printf("Cant be multiplied");
        return 0;
    }

    int m1[r1][c1],m2[r2][c2],i,j,k;
    printf("Enter the elements of matrix 1 : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2 : \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }
    
    printf("Matrix 1 : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d \t",m1[i][j]);
        }printf("\n");
    }

    printf("Matrix 2 : \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",m2[i][j]);
        }printf("\n");
    }

    int mul[r1][c2];
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {   mul[i][j]=0;
            for(int k=0;k<c1;k++)
            {
                opcount++;
                mul[i][j]=mul[i][j]+m1[i][k]*m2[k][j];
            }
        }
    }

    printf("Multiplied matrix is : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",mul[i][j]);
        }printf("\n");
    }

    printf("\nopcount is %d",opcount);

}