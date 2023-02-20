#include <stdio.h>
#include <stdbool.h>

int opcount=0;

bool subset_sum(int set[], int n, int sum) {
  if (sum == 0) 
  {
    opcount++;
    return true;
  } 
  else if (n == 0) 
  {
    opcount++;
    return false;
  } 
  else if (set[n-1] > sum) 
  {
    opcount++;
    return subset_sum(set, n-1, sum);
  } 
  else 
  {
    opcount++;
    return subset_sum(set, n-1, sum) || subset_sum(set, n-1, sum-set[n-1]);
  }
}

int main() {
  
  int sum;
  int no;
  printf("Enter number of values : ");
  scanf("%d",&no);
  int set[no];
  printf("Enter values : ");
  for(int i=0;i<no;i++)
  {
    scanf("%d",&set[i]);
  }
  printf("Enter value of sum ");
  scanf("%d",&sum);

  int n = sizeof(set)/sizeof(set[0]);
  if (subset_sum(set, n, sum) == true) 
  {
    printf("There is a subset of the set with the given sum.\n");
  } 
  else
  {
    printf("There is no subset of the set with the given sum.\n");
  }
  printf("opcount is %d",opcount);
  return 0;
}