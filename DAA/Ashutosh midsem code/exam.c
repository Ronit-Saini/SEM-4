#include<stdio.h>
#include<stdlib.h>
int partition(int *arr,int start,int end,int n)
{int i,j;
	if(end-start==2)
	{
		if(*(arr+start)==*(arr+end))
		{
			printf("%d %d",*(arr+start),*(arr+end));
		}
		else if(end-start==4)
		{
			if(i=start;i<=end;i++)
			{
				for(j=i+1;j<end;j++)
				{
					if((*(arr+i))==(*(arr+j)))
					{
						return 4;
					}
				}
			}
		}
		else if(end-start==8)
		{
			if(i=start;i<=end;i++)
			{
				for(j=i+1;j<end;j++)
				{
					if((*(arr+i))==(*(arr+j)))
					{
						printf("%d %d",*(arr+i),*(arr+j));
					}
				}
			}
		}
	}
}
void printpartition(int *arr,int start,int end,int n)
{int i;
	for(i=start;i<=end;i++)
	{
		for(j=i+1;j<end;j++)
				{
					if((*(arr+i))==(*(arr+j)))
					{
						return 8;
					}
				}

	}
}
void conquer(int *arr,int n)
{int a=0,b=0,c=0,d=0,e=0,f=0;
	int p=partition(arr,0,7,8);
	if(p==8)
	{
		a=partition(arr,0,3,4);
		b=partition(arr,4,7,8);
	
		if(a==4)
		{
			c=partition(arr,0,1,2);
			d=partition(arr,2,3,2);
		}
		if(b==4)
		{	
			e=partition(arr,4,5,2);
			f=partition(arr,6,7,2);
		}
		if(c==d==e==f=-1)
		{
			printpartition(arr,0,3,4);
			printpartition(arr,4,7,4);
		}
		if(a==b==-1)
		{
			printpartition(arr,0,7,8);
		}
	}
}
int main()
{
	
}